#include <Zydis/Register.h>
#include <array>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <zasm/base/register.hpp>
#include <zasm/formatter/formatter.hpp>
#include <zasm/program/instruction.hpp>
#include <zasm/program/node.hpp>
#include <zasm/program/program.hpp>
#include <zasm/x86/meta.hpp>
#include <zasm/x86/mnemonic.hpp>
#include <zasm/x86/register.hpp>

namespace zasm::formatter
{
    namespace detail
    {
        struct Context
        {
        public:
            static constexpr std::size_t kInlineCapacity = 64;

            const Program* program{};
            Options options{};

            union
            {
                char* ptr;
                std::array<char, kInlineCapacity> buf;
            } _data{};

            std::size_t size{};
            std::size_t capacity{ kInlineCapacity };

            constexpr Context() = delete;
            constexpr Context(Options opts)
                : program(nullptr)
                , options(opts)
            {
            }
            constexpr Context(const Program& prog, Options opts)
                : program(&prog)
                , options(opts)
            {
            }
            Context(const Context&) = delete;
            Context(Context&&) = delete;

            ~Context()
            {
                if (capacity > kInlineCapacity)
                {
                    // NOLINTNEXTLINE
                    std::free(_data.ptr);
                }
            }

            Context& operator=(const Context&) = delete;
            Context& operator=(Context&&) = delete;

            // NOLINTNEXTLINE
            template<std::size_t N> void appendLiteral(const char (&str)[N])
            {
                if (N > 0 && str[N - 1] == '\0')
                {
                    return append(str, N - 1); // NOLINT
                }
                return append(str, N); // NOLINT
            }

            void appendString(const char* str)
            {
                const std::size_t len = strlen(str);
                return append(str, len);
            }

            void append(const char* str, std::size_t len)
            {
                const std::size_t spaceLeft = capacity - size;
                if (len > spaceLeft)
                {
                    growBuffer(len);
                }
                std::memcpy(data() + size, str, len);
                size += len;
            }

            template<typename TFmt, typename... TArgs> void format(TFmt&& fmt, TArgs&&... args)
            {
                std::size_t spaceLeft = capacity - size;
                // NOLINTNEXTLINE
                int len = snprintf(data() + size, spaceLeft, std::forward<TFmt>(fmt), std::forward<TArgs>(args)...);
                if (len >= spaceLeft)
                {
                    growBuffer(len);

                    spaceLeft = capacity - size;
                    // NOLINTNEXTLINE
                    len = snprintf(data() + size, spaceLeft, std::forward<TFmt>(fmt), std::forward<TArgs>(args)...);
                }

                size += len;
            }

            bool empty() const noexcept
            {
                return size == 0;
            }

            bool hasOption(Options opt) const noexcept
            {
                return (options & opt) != Options::None;
            }

            char* data() noexcept
            {
                if (capacity <= kInlineCapacity)
                {
                    return _data.buf.data();
                }
                return _data.ptr;
            }

            void growBuffer(std::size_t extraLen) noexcept
            {
                assert(extraLen > 0);

                const std::size_t newCapacity = (capacity + extraLen) << 2;

                char* ptr = nullptr;
                if (capacity > kInlineCapacity)
                {
                    // NOLINTNEXTLINE
                    ptr = static_cast<char*>(std::realloc(_data.ptr, newCapacity));
                }
                else
                {
                    // NOLINTNEXTLINE
                    ptr = static_cast<char*>(std::malloc(newCapacity));
                    if (ptr != nullptr)
                    {
                        std::memcpy(ptr, _data.buf.data(), size);
                    }
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
            const char* str = ZydisMnemonicGetString(static_cast<ZydisMnemonic>(mnemonic.value()));
            ctx.appendString(str);
        }

        static void opToString([[maybe_unused]] Context& ctx, [[maybe_unused]] const Operand::None& opNone) noexcept
        {
        }

        static void opToString(Context& ctx, const Reg& opReg)
        {
            const char* str = ZydisRegisterGetString(static_cast<ZydisRegister>(opReg.getId()));
            ctx.appendString(str);
        }

        static void opToString(Context& ctx, const Imm& opImm)
        {
            const auto val = opImm.value<std::int64_t>();
            if (ctx.hasOption(Options::HexImmediates))
            {
                if (val < 0)
                {
                    ctx.format("-0x%08" PRIx64, -val);
                }
                else
                {
                    ctx.format("0x%08" PRIx64, val);
                }
            }
            else
            {
                ctx.format("%" PRId64, val);
            }
        }

        static void labelToString(Context& ctx, const Label& label)
        {
            if (ctx.program != nullptr)
            {
                auto labelData = ctx.program->getLabelData(label);
                if (labelData.hasValue() && labelData->name != nullptr)
                {
                    ctx.format("%s", labelData->name);
                    return;
                }
            }

            ctx.format("L%u", label.getId());
        }

        static void opToString(Context& ctx, const Label& label)
        {
            return labelToString(ctx, label);
        }

        static Reg getDefaultMemSegment(const Mem& mem)
        {
            if (const auto seg = mem.getSegment(); seg.isValid())
            {
                return seg;
            }
            if (const auto base = mem.getBase(); base.isValid())
            {
                if (base.getPhysicalIndex() == x86::sp.getPhysicalIndex()
                    || base.getPhysicalIndex() == x86::bp.getPhysicalIndex())
                {
                    return x86::ss;
                }
            }
            return x86::ds;
        }

        static void opToString(Context& ctx, const Mem& opMem)
        {
            if (opMem.getBitSize() == BitSize::_8)
            {
                ctx.appendLiteral("byte ptr ");
            }
            else if (opMem.getBitSize() == BitSize::_16)
            {
                ctx.appendLiteral("word ptr ");
            }
            else if (opMem.getBitSize() == BitSize::_32)
            {
                ctx.appendLiteral("dword ptr ");
            }
            else if (opMem.getBitSize() == BitSize::_64)
            {
                ctx.appendLiteral("qword ptr ");
            }
            else if (opMem.getBitSize() == BitSize::_80)
            {
                ctx.appendLiteral("tword ptr ");
            }
            else if (opMem.getBitSize() == BitSize::_128)
            {
                ctx.appendLiteral("xmmword ptr ");
            }
            else if (opMem.getBitSize() == BitSize::_256)
            {
                ctx.appendLiteral("ymmword ptr ");
            }
            else if (opMem.getBitSize() == BitSize::_512)
            {
                ctx.appendLiteral("zmmword ptr ");
            }

            if (const auto regSeg = getDefaultMemSegment(opMem); regSeg.isValid())
            {
                opToString(ctx, regSeg);
                ctx.appendLiteral(":");
            }

            ctx.appendLiteral("[");

            bool hasRel = false;
            bool hasBase = false;
            if (const auto regBase = opMem.getBase(); regBase.isValid())
            {
                if (regBase.isIP())
                {
                    hasRel = true;
                }
                else
                {
                    opToString(ctx, regBase);
                    hasBase = true;
                }
            }

            bool hasIndex = false;
            if (const auto regIdx = opMem.getIndex(); regIdx.isValid())
            {
                if (hasBase)
                {
                    ctx.appendLiteral("+");
                }
                opToString(ctx, regIdx);
                hasIndex = true;

                if (opMem.getScale() > 1)
                {
                    ctx.format("*%d", opMem.getScale());
                }
            }

            bool hasLabel = false;
            if (const auto label = opMem.getLabel(); label.isValid())
            {
                if (hasBase || hasIndex)
                {
                    ctx.appendLiteral("+");
                }

                opToString(ctx, label);
                hasLabel = true;
            }

            if (const auto disp = opMem.getDisplacement(); disp != 0)
            {
                if (hasBase || hasIndex || hasLabel)
                {
                    if (disp < 0)
                    {
                        ctx.appendLiteral("-");
                    }
                    else
                    {
                        ctx.appendLiteral("+");
                    }
                }
                else if (hasRel)
                {
                    ctx.appendLiteral("rel ");
                }
                if (ctx.hasOption(Options::HexOffsets))
                {
                    if (disp < 0)
                    {
                        ctx.format("0x%02" PRIx64, -disp);
                    }
                    else
                    {
                        ctx.format("0x%02" PRIx64, disp);
                    }
                }
                else
                {
                    if (disp < 0)
                    {
                        ctx.format("%" PRId64, -disp);
                    }
                    else
                    {
                        ctx.format("%" PRId64, disp);
                    }
                }
            }
            else
            {
                if (!hasBase && !hasIndex && !hasLabel)
                {
                    ctx.appendLiteral("0");
                }
            }

            ctx.appendLiteral("]");
        }

        static void nodeToString([[maybe_unused]] Context& ctx, [[maybe_unused]] const Sentinel& node) noexcept
        {
        }

        static void nodeToString(Context& ctx, const Align& node) noexcept
        {
            if (node.getType() == Align::Type::Code)
                ctx.format(".align %u, nop", node.getAlign());
            else
                ctx.format(".align %u", node.getAlign());
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
            {
                return;
            }

            if (node.isU8())
            {
                if (node.getRepeatCount() > 1)
                {
                    ctx.format("times %zu ", node.getRepeatCount());
                }
                dataPrefix(ctx, BitSize::_8);
                ctx.format("0x%02" PRIx8, node.valueAsU8());
            }
            else if (node.isU16())
            {
                if (node.getRepeatCount() > 1)
                {
                    ctx.format("times %zu ", node.getRepeatCount());
                }
                dataPrefix(ctx, BitSize::_16);
                ctx.format("0x%04" PRIx16, node.valueAsU16());
            }
            else if (node.isU32())
            {
                if (node.getRepeatCount() > 1)
                {
                    ctx.format("times %zu ", node.getRepeatCount());
                }
                dataPrefix(ctx, BitSize::_32);
                ctx.format("0x%08" PRIx32, node.valueAsU32());
            }
            else if (node.isU64())
            {
                if (node.getRepeatCount() > 1)
                {
                    ctx.format("times %zu ", node.getRepeatCount());
                }
                dataPrefix(ctx, BitSize::_64);
                ctx.format("0x%016" PRIx64, node.valueAsU64());
            }
            else
            {
                const auto* data = static_cast<const uint8_t*>(node.getData());
                constexpr const auto bytesPerLine = 16;

                size_t bytesOnLine = 0;
                for (size_t i = 0; i < node.getSize(); ++i)
                {
                    if (bytesOnLine >= bytesPerLine)
                    {
                        bytesOnLine = 0;
                        ctx.appendLiteral("\n");
                    }

                    if (bytesOnLine == 0)
                    {
                        dataPrefix(ctx, BitSize::_8);
                    }

                    if (bytesOnLine > 0)
                    {
                        ctx.appendLiteral(", ");
                    }

                    ctx.format("0x%02" PRIx8, data[i]);
                    bytesOnLine++;
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
            if (ctx.program != nullptr)
            {
                const char* str = ctx.program->getSectionName(node);
                ctx.format(".section %s", str);
            }
            else
            {
                ctx.appendLiteral(".section");
            }
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
            {
                ctx.appendLiteral("lock ");
            }
            if (node.hasAttrib(x86::Attribs::Rep))
            {
                ctx.appendLiteral("rep ");
            }
            if (node.hasAttrib(x86::Attribs::Repe))
            {
                ctx.appendLiteral("repe ");
            }
            if (node.hasAttrib(x86::Attribs::Repne))
            {
                ctx.appendLiteral("repne ");
            }

            mnemonictoString(ctx, node.getMnemonic());

            for (std::size_t opIndex = 0; opIndex < node.getOperandCount(); ++opIndex)
            {
                const auto& operand = node.getOperand(opIndex);
                if (operand.holds<Operand::None>())
                {
                    break;
                }

                operand.visit([&](auto&& opVal) {
                    if (opIndex == 0)
                    {
                        ctx.appendLiteral(" ");
                    }
                    else if (opIndex > 0)
                    {
                        ctx.appendLiteral(", ");
                    }
                    opToString(ctx, opVal);
                });
            }
        }

    } // namespace detail

    std::string toString(const Program& program, const Node* node, Options options /*= kDefaultOptions*/)
    {
        if (node == nullptr)
        {
            return "<nullptr>";
        }

        auto ctx = detail::Context(program, options);

        node->visit([&](auto&& n) { detail::nodeToString(ctx, n); });

        return { ctx.data(), ctx.size };
    }

    std::string toString(const Program& program, Options options /*= {}*/)
    {
        return toString(program, program.getHead(), nullptr, options);
    }

    std::string toString(
        const Program& program, const Node* nodeFrom, const Node* nodeTo, Options options /*= kDefaultOptions*/)
    {
        auto ctx = detail::Context(program, options);

        const auto* node = nodeFrom;
        while (node != nullptr && node != nodeTo)
        {
            if (!ctx.empty())
            {
                ctx.appendLiteral("\n");
            }

            node->visit([&](auto&& n) { detail::nodeToString(ctx, n); });

            node = node->getNext();
        }

        return { ctx.data(), ctx.size };
    }

    std::string toString(const Program& program, const Instruction* instr, Options options /*= kDefaultOptions*/)
    {
        if (instr == nullptr)
        {
            return "<nullptr>";
        }

        auto ctx = detail::Context(program, options);

        detail::nodeToString(ctx, *instr);

        return { ctx.data(), ctx.size };
    }

    std::string toString(const Instruction* instr, Options options /*= kDefaultOptions*/)
    {
        if (instr == nullptr)
        {
            return "<nullptr>";
        }

        auto ctx = detail::Context(options);

        detail::nodeToString(ctx, *instr);

        return { ctx.data(), ctx.size };
    }

    std::string toString(const Reg& reg, Options options /*= kDefaultOptions*/)
    {
        auto ctx = detail::Context(options);

        detail::opToString(ctx, reg);

        return { ctx.data(), ctx.size };
    }

} // namespace zasm::formatter
