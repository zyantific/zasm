#include <Zydis/Register.h>
#include <algorithm>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstring>
#include <zasm/formatter/formatter.hpp>
#include <zasm/program/instruction.hpp>
#include <zasm/program/node.hpp>
#include <zasm/program/program.hpp>
#include <zasm/program/register.hpp>
#include <zasm/x86/instruction.hpp>

namespace zasm::formatter
{
    namespace detail
    {
        struct Context
        {
            static constexpr size_t kInlineCapacity = 128;

            Program& program;
            Options options{};

            union
            {
                char* ptr;
                char buf[kInlineCapacity];
            } _data{};

            size_t size{};
            size_t capacity{ kInlineCapacity };

            constexpr Context(Program& p, Options o)
                : program(p)
                , options(o)
            {
            }

            ~Context()
            {
                if (capacity > kInlineCapacity)
                    std::free(_data.ptr);
            }

            void append(const char* str)
            {
                format("%s", str);
            }

            template<typename TFmt, typename... TArgs> void format(TFmt&& fmt, TArgs&&... args)
            {
                size_t spaceLeft = capacity - size;

                int len = snprintf(data() + size, spaceLeft, std::forward<TFmt>(fmt), std::forward<TArgs>(args)...);
                if (len >= spaceLeft)
                {
                    growBuffer(len);

                    spaceLeft = capacity - size;
                    len = snprintf(data() + size, spaceLeft, std::forward<TFmt>(fmt), std::forward<TArgs>(args)...);
                }

                size += len;
            }

            bool empty() const
            {
                return size == 0;
            }

            bool hasOption(Options opt) const noexcept
            {
                return (options & opt) != Options::None;
            }

            char* data()
            {
                if (capacity <= kInlineCapacity)
                    return _data.buf;

                return _data.ptr;
            }

            void growBuffer(size_t extraLen)
            {
                assert(extraLen > 0);

                const size_t newCapacity = (capacity + extraLen) << 1;

                char* ptr = nullptr;
                if (capacity > kInlineCapacity)
                {
                    ptr = reinterpret_cast<char*>(std::realloc(_data.ptr, newCapacity));
                }
                else
                {
                    ptr = reinterpret_cast<char*>(std::malloc(newCapacity));
                    std::memcpy(ptr, _data.buf, size);
                }

                if (ptr == nullptr)
                {
                    assert(ptr != nullptr);
                    return;
                }

                _data.ptr = ptr;
                capacity = newCapacity;
            }
        };

        static void mnemonictoString(Context& ctx, const Instruction::Mnemonic mnemonic)
        {
            const char* str = ZydisMnemonicGetString(static_cast<ZydisMnemonic>(mnemonic));
            ctx.append(str);
        }

        static void opToString(Context&, const Operand::None&)
        {
        }

        static void opToString(Context& ctx, const Reg& op)
        {
            const char* str = ZydisRegisterGetString(static_cast<ZydisRegister>(op.getId()));
            ctx.append(str);
        }

        static void opToString(Context& ctx, const Imm& op)
        {
            int64_t val = op.value<int64_t>();
            if (ctx.hasOption(Options::HexImmediates))
            {
                if (val < 0)
                    ctx.format("-0x%08" PRIx64, -val);
                else
                    ctx.format("0x%08" PRIx64, val);
            }
            else
            {
                ctx.format("%" PRId64, val);
            }
        }

        static void labelToString(Context& ctx, const Label& label)
        {
            auto labelData = ctx.program.getLabelData(label);
            if (labelData.hasValue())
            {
                if (labelData->name != nullptr)
                    ctx.format("%s", labelData->name);
                else
                    ctx.format("L%u", label.getId());
            }
            else
            {
                ctx.format("L%u", label.getId());
            }
        }

        static void opToString(Context& ctx, const Label& op)
        {
            return labelToString(ctx, op);
        }

        static void opToString(Context& ctx, const Mem& op)
        {
            if (op.getByteSize() == 1)
                ctx.append("byte ptr ");
            else if (op.getByteSize() == 2)
                ctx.append("word ptr ");
            else if (op.getByteSize() == 4)
                ctx.append("dword ptr ");
            else if (op.getByteSize() == 8)
                ctx.append("qword ptr ");
            else if (op.getByteSize() == 10)
                ctx.append("tword ptr ");
            else if (op.getByteSize() == 16)
                ctx.append("xmmword ptr ");
            else if (op.getByteSize() == 32)
                ctx.append("ymmword ptr ");
            else if (op.getByteSize() == 64)
                ctx.append("zmmword ptr ");

            if (auto regSeg = op.getSegment(); regSeg.isValid())
            {
                opToString(ctx, regSeg);
                ctx.append(":");
            }

            ctx.append("[");

            bool hasBase = false;
            if (auto regBase = op.getBase(); regBase.isValid())
            {
                opToString(ctx, regBase);
                hasBase = true;
            }

            bool hasIndex = false;
            if (auto regIdx = op.getIndex(); regIdx.isValid())
            {
                if (hasBase)
                    ctx.append("+");
                opToString(ctx, regIdx);
                hasIndex = true;

                if (op.getScale() > 1)
                {
                    ctx.format("*%d", op.getScale());
                }
            }

            bool hasLabel = false;
            if (auto label = op.getLabel(); label.isValid())
            {
                if (hasBase || hasIndex)
                    ctx.append("+");

                opToString(ctx, label);
                hasLabel = true;
            }

            bool hasDisp = false;
            if (auto disp = op.getDisplacement(); disp != 0)
            {
                if (hasBase || hasIndex || hasLabel)
                {
                    if (disp < 0)
                        ctx.append("-");
                    else
                        ctx.append("+");
                }
                if (ctx.hasOption(Options::HexOffsets))
                {
                    if (disp < 0)
                        ctx.format("0x%" PRIx64, -disp);
                    else
                        ctx.format("0x%" PRIx64, disp);
                }
                else
                {
                    if (disp < 0)
                        ctx.format("%" PRId64, -disp);
                    else
                        ctx.format("%" PRId64, disp);
                }
                hasDisp = true;
            }
            else
            {
                if (!hasBase && !hasIndex && !hasLabel)
                {
                    ctx.append("0");
                    hasDisp = true;
                }
            }

            ctx.append("]");
        }

        static void nodeToString(Context&, const NodePoint&)
        {
        }

        static void dataPrefix(Context& ctx, BitSize size)
        {
            switch (size)
            {
                case BitSize::_8:
                    ctx.append("db ");
                    break;
                case BitSize::_16:
                    ctx.append("dw ");
                    break;
                case BitSize::_32:
                    ctx.append("dd ");
                    break;
                case BitSize::_64:
                    ctx.append("dq ");
                    break;
                default:
                    break;
            }
        }

        static void nodeToString(Context& ctx, const Data& node)
        {
            if (node.getSize() == 0)
                return;

            if (node.isU8())
            {
                dataPrefix(ctx, BitSize::_8);
                ctx.format("0x%02" PRIx8, node.valueAsU8());
            }
            else if (node.isU16())
            {
                dataPrefix(ctx, BitSize::_16);
                ctx.format("0x%04" PRIx16, node.valueAsU16());
            }
            else if (node.isU32())
            {
                dataPrefix(ctx, BitSize::_32);
                ctx.format("0x%08" PRIx32, node.valueAsU32());
            }
            else if (node.isU64())
            {
                dataPrefix(ctx, BitSize::_64);
                ctx.format("0x%016" PRIx64, node.valueAsU64());
            }
            else
            {
                const uint8_t* data = reinterpret_cast<const uint8_t*>(node.getData());
                constexpr const auto bytesPerLine = 16;

                size_t bytesOnLine = 0;
                for (size_t i = 0; i < node.getSize(); ++i)
                {
                    if (bytesOnLine == 0)
                        dataPrefix(ctx, BitSize::_8);

                    if (bytesOnLine > 0)
                        ctx.append(", ");

                    ctx.format("0x%02" PRIx8, data[i]);
                    bytesOnLine++;

                    if (bytesOnLine >= bytesPerLine)
                    {
                        bytesOnLine = 0;
                        ctx.append("\n");
                    }
                }
            }
        }

        static void nodeToString(Context& ctx, const Label& node)
        {
            opToString(ctx, node);
            ctx.append(":");
        }

        static void nodeToString(Context& ctx, const Section& node)
        {
            const char* str = ctx.program.getSectionName(node);
            ctx.format(".section %s", str);
        }

        static void nodeToString(Context& ctx, const EmbeddedLabel& node)
        {
            dataPrefix(ctx, node.getSize());
            labelToString(ctx, node.getLabel());
            if (node.isRelative())
            {
                ctx.append(" - ");
                labelToString(ctx, node.getRelativeLabel());
            }
        }

        static void nodeToString(Context& ctx, const Instruction& node)
        {
            if (node.hasAttrib(x86::Attribs::Lock))
                ctx.append("lock ");
            if (node.hasAttrib(x86::Attribs::Rep))
                ctx.append("rep ");
            if (node.hasAttrib(x86::Attribs::Repe))
                ctx.append("repe ");
            if (node.hasAttrib(x86::Attribs::Repne))
                ctx.append("repne ");

            mnemonictoString(ctx, node.getMnemonic());

            size_t opIndex = 0;
            for (auto& op : node.getOperands())
            {
                if (op.holds<Operand::None>())
                    break;

                if (node.isOperandHidden(opIndex))
                    continue;

                op.visit([&](auto&& op) {
                    if (opIndex == 0)
                        ctx.append(" ");
                    else if (opIndex > 0)
                        ctx.append(", ");

                    opToString(ctx, op);
                });

                opIndex++;
            }
        }

    } // namespace detail

    std::string toString(Program& program, Options options /*= {}*/)
    {
        auto ctx = detail::Context(program, options);

        auto* node = program.getHead();
        while (node != nullptr)
        {
            if (!ctx.empty())
                ctx.append("\n");

            node->visit([&](auto&& n) { detail::nodeToString(ctx, n); });

            node = node->getNext();
        }

        return { ctx.data(), ctx.size };
    }

    std::string toString(Program& program, const Node* node, Options options /*= {}*/)
    {
        auto ctx = detail::Context(program, options);

        node->visit([&](auto&& n) { detail::nodeToString(ctx, n); });

        return { ctx.data(), ctx.size };
    }

    std::string toString(Program& program, const Node* from, const Node* to, Options options /*= {}*/)
    {
        std::string res;

        auto* node = from;
        while (node != nullptr && node != to)
        {
            if (!res.empty())
                res.append("\n");

            auto ctx = detail::Context(program, options);

            node->visit([&](auto&& n) { detail::nodeToString(ctx, n); });

            res.append(ctx.data(), ctx.size);

            node = node->getNext();
        }

        return res;
    }

    std::string toString(Program& program, const Instruction* instr, Options options /*= {}*/)
    {
        auto ctx = detail::Context(program, options);

        detail::nodeToString(ctx, *instr);

        return { ctx.data(), ctx.size };
    }

} // namespace zasm::formatter
