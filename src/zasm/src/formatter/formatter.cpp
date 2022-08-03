#include <Zydis/Register.h>
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
            static constexpr size_t kInlineCapacity = 64;

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

            template<size_t N> void appendLiteral(const char (&str)[N])
            {
                return append(str, N - 1);
            }

            void appendString(const char* str)
            {
                size_t len = strlen(str);
                return append(str, len);
            }

            void append(const char* str, size_t len)
            {
                size_t spaceLeft = capacity - size;
                if (len > spaceLeft)
                {
                    growBuffer(len);
                }
                std::memcpy(data() + size, str, len);
                size += len;
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

                const size_t newCapacity = (capacity + extraLen) << 2;

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
            ctx.appendString(str);
        }

        static void opToString(Context&, const Operand::None&)
        {
        }

        static void opToString(Context& ctx, const Reg& op)
        {
            const char* str = ZydisRegisterGetString(static_cast<ZydisRegister>(op.getId()));
            ctx.appendString(str);
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
                ctx.appendLiteral("byte ptr ");
            else if (op.getByteSize() == 2)
                ctx.appendLiteral("word ptr ");
            else if (op.getByteSize() == 4)
                ctx.appendLiteral("dword ptr ");
            else if (op.getByteSize() == 8)
                ctx.appendLiteral("qword ptr ");
            else if (op.getByteSize() == 10)
                ctx.appendLiteral("tword ptr ");
            else if (op.getByteSize() == 16)
                ctx.appendLiteral("xmmword ptr ");
            else if (op.getByteSize() == 32)
                ctx.appendLiteral("ymmword ptr ");
            else if (op.getByteSize() == 64)
                ctx.appendLiteral("zmmword ptr ");

            if (auto regSeg = op.getSegment(); regSeg.isValid())
            {
                opToString(ctx, regSeg);
                ctx.appendLiteral(":");
            }

            ctx.appendLiteral("[");

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
                    ctx.appendLiteral("+");
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
                    ctx.appendLiteral("+");

                opToString(ctx, label);
                hasLabel = true;
            }

            bool hasDisp = false;
            if (auto disp = op.getDisplacement(); disp != 0)
            {
                if (hasBase || hasIndex || hasLabel)
                {
                    if (disp < 0)
                        ctx.appendLiteral("-");
                    else
                        ctx.appendLiteral("+");
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
                    ctx.appendLiteral("0");
                    hasDisp = true;
                }
            }

            ctx.appendLiteral("]");
        }

        static void nodeToString(Context&, const NodePoint&)
        {
        }

        static void dataPrefix(Context& ctx, BitSize size)
        {
            switch (size)
            {
                case BitSize::_8:
                    ctx.appendLiteral("db ");
                    break;
                case BitSize::_16:
                    ctx.appendLiteral("dw ");
                    break;
                case BitSize::_32:
                    ctx.appendLiteral("dd ");
                    break;
                case BitSize::_64:
                    ctx.appendLiteral("dq ");
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
                        ctx.appendLiteral(", ");

                    ctx.format("0x%02" PRIx8, data[i]);
                    bytesOnLine++;

                    if (bytesOnLine >= bytesPerLine)
                    {
                        bytesOnLine = 0;
                        ctx.appendLiteral("\n");
                    }
                }
            }
        }

        static void nodeToString(Context& ctx, const Label& node)
        {
            opToString(ctx, node);
            ctx.appendLiteral(":");
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
                ctx.appendLiteral(" - ");
                labelToString(ctx, node.getRelativeLabel());
            }
        }

        static void nodeToString(Context& ctx, const Instruction& node)
        {
            if (node.hasAttrib(x86::Attribs::Lock))
                ctx.appendLiteral("lock ");
            if (node.hasAttrib(x86::Attribs::Rep))
                ctx.appendLiteral("rep ");
            if (node.hasAttrib(x86::Attribs::Repe))
                ctx.appendLiteral("repe ");
            if (node.hasAttrib(x86::Attribs::Repne))
                ctx.appendLiteral("repne ");

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
                        ctx.appendLiteral(" ");
                    else if (opIndex > 0)
                        ctx.appendLiteral(", ");

                    opToString(ctx, op);
                });

                opIndex++;
            }
        }

    } // namespace detail

    std::string toString(Program& program, const Node* node, Options options /*= {}*/)
    {
        auto ctx = detail::Context(program, options);

        node->visit([&](auto&& n) { detail::nodeToString(ctx, n); });

        return { ctx.data(), ctx.size };
    }

    std::string toString(Program& program, Options options /*= {}*/)
    {
        return toString(program, program.getHead(), nullptr, options);
    }

    std::string toString(Program& program, const Node* from, const Node* to, Options options /*= {}*/)
    {
        auto ctx = detail::Context(program, options);

        auto* node = from;
        while (node != nullptr && node != to)
        {
            if (!ctx.empty())
                ctx.appendLiteral("\n");

            node->visit([&](auto&& n) { detail::nodeToString(ctx, n); });

            node = node->getNext();
        }

        return { ctx.data(), ctx.size };
    }

    std::string toString(Program& program, const Instruction* instr, Options options /*= {}*/)
    {
        auto ctx = detail::Context(program, options);

        detail::nodeToString(ctx, *instr);

        return { ctx.data(), ctx.size };
    }

} // namespace zasm::formatter
