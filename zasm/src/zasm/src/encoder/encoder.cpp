#include "zasm/encoder/encoder.hpp"

#include "../program/program.state.hpp"
#include "encoder.context.hpp"
#include "zasm/x86/meta.hpp"
#include "zasm/x86/mnemonic.hpp"

#include <Zydis/Decoder.h>
#include <Zydis/Encoder.h>
#include <cstddef>
#include <limits>
#include <optional>

namespace zasm
{
    // Ensure size is correct.
    static_assert(std::tuple_size_v<EncoderOperands> == ZYDIS_ENCODER_MAX_OPERANDS);

    struct EncoderState
    {
        EncoderContext* ctx{};
        ZydisEncoderRequest req{};
        std::size_t operandIndex{};
        RelocationType relocKind{};
        RelocationData relocData{};
        Label::Id relocLabel{ Label::Id::Invalid };
    };

    // NOTE: This value has to be at least larger than 0xFFFF to be used with imm32/rel32 displacement.
    static constexpr std::int32_t kTemporaryRel32Value = 0x123456;

    static constexpr std::int32_t kTemporaryRel8Value = 0x44;

    static constexpr std::int32_t kHintRequiresSize = -1;

    static constexpr auto kAllowedEncodingX86 = static_cast<ZydisEncodableEncoding>(
        ZYDIS_ENCODABLE_ENCODING_LEGACY | ZYDIS_ENCODABLE_ENCODING_3DNOW);

    static constexpr auto kAllowedEncodingX64 = static_cast<ZydisEncodableEncoding>(
        ZYDIS_ENCODABLE_ENCODING_LEGACY | ZYDIS_ENCODABLE_ENCODING_3DNOW | ZYDIS_ENCODABLE_ENCODING_XOP
        | ZYDIS_ENCODABLE_ENCODING_VEX | ZYDIS_ENCODABLE_ENCODING_EVEX);

    struct EncodeVariantsInfo
    {
        bool isControlFlow{};
        std::int8_t encodeSizeRel8{ -1 };
        std::int8_t encodeSizeRel32{ -1 };
        std::int8_t cfOperandIndex{ -1 };

        constexpr bool canEncodeRel8() const noexcept
        {
            return encodeSizeRel8 != -1;
        }

        constexpr bool canEncodeRel32() const noexcept
        {
            return encodeSizeRel32 != -1;
        }
    };

    static constexpr auto buildEncodeVariantTable() noexcept
    {
        std::array<EncodeVariantsInfo, ZydisMnemonic::ZYDIS_MNEMONIC_MAX_VALUE> data{};

        // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
        data[ZYDIS_MNEMONIC_JMP] = EncodeVariantsInfo{ true, 2, 5, 0 };
        data[ZYDIS_MNEMONIC_JB] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JBE] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JCXZ] = EncodeVariantsInfo{ true, 2, -1, 0 };
        data[ZYDIS_MNEMONIC_JECXZ] = EncodeVariantsInfo{ true, 2, -1, 0 };
        data[ZYDIS_MNEMONIC_JRCXZ] = EncodeVariantsInfo{ true, 2, -1, 0 };
        data[ZYDIS_MNEMONIC_JL] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JLE] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JNB] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JNBE] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JNL] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JNLE] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JNO] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JNP] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JNS] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JNZ] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JO] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JP] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JS] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_JZ] = EncodeVariantsInfo{ true, 2, 6, 0 };
        data[ZYDIS_MNEMONIC_LOOP] = EncodeVariantsInfo{ true, 2, -1, 0 };
        data[ZYDIS_MNEMONIC_LOOPE] = EncodeVariantsInfo{ true, 2, -1, 0 };
        data[ZYDIS_MNEMONIC_LOOPNE] = EncodeVariantsInfo{ true, 2, -1, 0 };
        data[ZYDIS_MNEMONIC_CALL] = EncodeVariantsInfo{ true, -1, 5, 0 };
        // NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

        return data;
    }

    static constexpr auto encoderVariantData = buildEncodeVariantTable();

    static constexpr const EncodeVariantsInfo& getEncodeVariantInfo(ZydisMnemonic mnemonic) noexcept
    {
        return encoderVariantData[mnemonic]; // NOLINT
    }

    static bool isLabelExternal(detail::ProgramState* state, Label::Id labelId)
    {
        const auto idx = static_cast<std::size_t>(labelId);
        if (idx >= state->labels.size())
        {
            return false;
        }

        auto& data = state->labels[idx];
        return (data.flags & LabelFlags::External) != LabelFlags::None;
    }

    static constexpr int64_t getRelativeAddress(std::int64_t address, std::int64_t target, std::int32_t instrSize) noexcept
    {
        return target - (address + instrSize);
    }

    static constexpr bool hasAttrib(Instruction::Attribs attribs, Instruction::Attribs other) noexcept
    {
        return (attribs & other) != x86::Attribs::None;
    }

    static constexpr ZydisInstructionAttributes getAttribs(Instruction::Attribs attribs) noexcept
    {
        ZydisInstructionAttributes res{};

        const auto translateAttrib = [&res,
                                      &attribs](Instruction::Attribs other, ZydisInstructionAttributes newAttrib) noexcept {
            if (hasAttrib(attribs, other))
            {
                res |= newAttrib;
            }
        };

        translateAttrib(x86::Attribs::Lock, ZYDIS_ATTRIB_HAS_LOCK);
        translateAttrib(x86::Attribs::Rep, ZYDIS_ATTRIB_HAS_REP);
        translateAttrib(x86::Attribs::Repe, ZYDIS_ATTRIB_HAS_REPE);
        translateAttrib(x86::Attribs::Repne, ZYDIS_ATTRIB_HAS_REPNE);
        translateAttrib(x86::Attribs::Bnd, ZYDIS_ATTRIB_HAS_BND);
        translateAttrib(x86::Attribs::Xacquire, ZYDIS_ATTRIB_HAS_XACQUIRE);
        translateAttrib(x86::Attribs::Xrelease, ZYDIS_ATTRIB_HAS_XRELEASE);

        return res;
    }

    static constexpr std::pair<int64_t, ZydisBranchType> processRelAddress(
        const EncodeVariantsInfo& info, EncoderContext* ctx, int64_t targetAddress)
    {
        std::int64_t res{};
        auto desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE;

        if (ctx == nullptr)
        {
            if (!info.canEncodeRel32())
            {
                desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_SHORT;
                res = kTemporaryRel8Value;
            }
            else
            {
                desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NEAR;
                res = kTemporaryRel32Value;
            }
        }
        else
        {
            if (info.canEncodeRel8())
            {
                const auto rel = getRelativeAddress(ctx->va, targetAddress, info.encodeSizeRel8);
                if (std::abs(rel) <= std::numeric_limits<std::int8_t>::max())
                {
                    res = rel;
                    desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_SHORT;
                }
            }

            if (desiredBranchType == ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE && info.canEncodeRel32())
            {
                const auto rel = getRelativeAddress(ctx->va, targetAddress, info.encodeSizeRel32);
                if (std::abs(rel) <= std::numeric_limits<std::int32_t>::max())
                {
                    res = rel;
                    desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NEAR;
                }
            }
        }

        // If desiredBranchType is ZYDIS_BRANCH_TYPE_NONE it means we can not fit the address
        // into the instruction, this is an error and should be handled by the caller.

        return { res, desiredBranchType };
    }

    static Error buildOperand_(ZydisEncoderOperand& dst, [[maybe_unused]] EncoderState& state, const Reg& src) noexcept
    {
        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER;
        dst.reg.value = static_cast<ZydisRegister>(src.getId());

        return ErrorCode::None;
    }

    static int64_t getTemporaryRel(EncoderState& state, const EncodeVariantsInfo& encodeInfo) noexcept
    {
        auto* ctx = state.ctx;

        std::int64_t kTempRel = 0;

        if (encodeInfo.canEncodeRel32())
        {
            kTempRel = kTemporaryRel32Value;
        }
        else if (encodeInfo.canEncodeRel8())
        {
            kTempRel = kTemporaryRel8Value;
        }

        const std::int64_t immValue = ctx != nullptr ? ctx->va + kTempRel : kTempRel;
        return immValue;
    }

    static Error buildOperand_(ZydisEncoderOperand& dst, EncoderState& state, const Label& src)
    {
        auto* ctx = state.ctx;
        auto desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE;

        const auto& encodeInfo = getEncodeVariantInfo(state.req.mnemonic);

        // Initially a temporary placeholder.
        std::int64_t immValue = getTemporaryRel(state, encodeInfo);

        std::optional<std::int64_t> labelVA;
        if (ctx != nullptr && !isLabelExternal(ctx->program, src.getId()))
        {
            labelVA = ctx != nullptr ? ctx->getLabelAddress(src.getId()) : std::nullopt;
            if (!labelVA.has_value() && ctx != nullptr)
            {
                ctx->needsExtraPass = true;
            }
        }

        // Check if this operand is used as the control flow target.
        if (encodeInfo.isControlFlow && state.operandIndex == encodeInfo.cfOperandIndex)
        {
            const auto targetAddress = labelVA.has_value() ? *labelVA : immValue;

            const auto [addrRel, branchType] = processRelAddress(encodeInfo, ctx, targetAddress);
            if (branchType == ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE)
            {
                char msg[128];
                std::snprintf(msg, sizeof(msg), "Label out of range for operand %zu", state.operandIndex);

                return Error(ErrorCode::AddressOutOfRange, msg);
            }

            immValue = addrRel;
            desiredBranchType = branchType;
        }
        else
        {
            if (labelVA.has_value())
            {
                immValue = *labelVA;
            }

            // Mark relocatable, only mov is allowed to have a label.
            if (state.req.mnemonic == ZYDIS_MNEMONIC_MOV)
            {
                if (state.req.operands[0].type == ZydisOperandType::ZYDIS_OPERAND_TYPE_REGISTER)
                {
                    state.relocKind = RelocationType::Abs;
                    state.relocData = RelocationData::Immediate;
                    state.relocLabel = src.getId();
                }
            }
        }

        if (desiredBranchType != ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE)
        {
            state.req.branch_type = desiredBranchType;
        }

        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_IMMEDIATE;
        dst.imm.s = immValue;

        return ErrorCode::None;
    }

    static Error buildOperand_(ZydisEncoderOperand& dst, EncoderState& state, const Imm& src)
    {
        auto* ctx = state.ctx;

        auto desiredBranchType = ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE;
        auto immValue = src.value<std::int64_t>();

        // Check if this operand is used as the control flow target.
        const auto& encodeInfo = getEncodeVariantInfo(state.req.mnemonic);
        if (encodeInfo.isControlFlow && state.operandIndex == encodeInfo.cfOperandIndex)
        {
            const auto targetAddress = immValue;
            const auto [addrRel, branchType] = processRelAddress(encodeInfo, ctx, targetAddress);

            immValue = addrRel;
            desiredBranchType = branchType;
        }

        if (desiredBranchType != ZydisBranchType::ZYDIS_BRANCH_TYPE_NONE)
        {
            state.req.branch_type = desiredBranchType;
        }

        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_IMMEDIATE;
        dst.imm.s = immValue;

        return ErrorCode::None;
    }

    static Error buildOperand_(ZydisEncoderOperand& dst, EncoderState& state, const Mem& src)
    {
        auto* ctx = state.ctx;

        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_MEMORY;
        dst.mem.base = static_cast<ZydisRegister>(src.getBase().getId());
        dst.mem.index = static_cast<ZydisRegister>(src.getIndex().getId());
        dst.mem.scale = src.getScale();
        dst.mem.size = static_cast<uint16_t>(src.getByteSize());

        // Scale has to be zero if no index is assigned.
        if (dst.mem.index == ZydisRegister::ZYDIS_REGISTER_NONE)
        {
            dst.mem.scale = 0;
        }

        std::int64_t displacement = src.getDisplacement();

        const auto address = ctx != nullptr ? ctx->va : 0;

        bool usingLabel = false;
        bool externalLabel = false;
        bool isDisplacementValid = true;

        if (const auto labelId = src.getLabelId(); labelId != Label::Id::Invalid)
        {
            if (ctx != nullptr)
            {
                externalLabel = isLabelExternal(ctx->program, labelId);

                auto labelVA = ctx->getLabelAddress(labelId);
                if (labelVA.has_value())
                {
                    displacement += *labelVA;
                }
                else
                {
                    displacement += kTemporaryRel32Value;
                    isDisplacementValid = false;
                    if (!externalLabel)
                    {
                        ctx->needsExtraPass = true;
                    }
                }
            }
            else
            {
                displacement = kTemporaryRel32Value;
                isDisplacementValid = false;
            }
            usingLabel = true;
        }

        if (dst.mem.base == ZYDIS_REGISTER_NONE && dst.mem.index == ZYDIS_REGISTER_NONE)
        {
            // Memory ABS, mark relocatable.
            state.relocKind = RelocationType::Abs;
            state.relocData = RelocationData::Memory;
            if (usingLabel)
            {
                state.relocLabel = src.getLabelId();
            }
        }
        else if (dst.mem.base == ZydisRegister::ZYDIS_REGISTER_RIP)
        {
            // We require the exact instruction size to encode this correctly.
            const auto instrSize = ctx != nullptr ? ctx->instrSize : 0;
            if (instrSize == 0)
            {
                if (ctx != nullptr)
                {
                    // Causes to re-encode again with instruction size available.
                    ctx->instrSize = kHintRequiresSize;
                }

                // Ensure this encodes.
                displacement = kTemporaryRel32Value;
            }
            else
            {
                if (isDisplacementValid)
                {
                    displacement = displacement - (address + instrSize);
                    if (std::abs(displacement) > std::numeric_limits<std::int32_t>::max())
                    {
                        char msg[128];
                        std::snprintf(msg, sizeof(msg), "Displacement out of range for operand %zu", state.operandIndex);

                        return Error(ErrorCode::AddressOutOfRange, msg);
                    }
                }
            }

            if (externalLabel)
            {
                state.relocKind = RelocationType::Rel32;
                state.relocData = RelocationData::Memory;
                state.relocLabel = src.getLabelId();
            }
        }

        dst.mem.displacement = displacement;

        // Handling segment
        const auto segmentId = static_cast<ZydisRegister>(src.getSegment().getId());
        if (segmentId == ZYDIS_REGISTER_GS)
        {
            state.req.prefixes |= ZYDIS_ATTRIB_HAS_SEGMENT_GS;
        }
        else if (segmentId == ZYDIS_REGISTER_FS)
        {
            state.req.prefixes |= ZYDIS_ATTRIB_HAS_SEGMENT_FS;
        }

        return ErrorCode::None;
    }

    static Error buildOperand_(
        ZydisEncoderOperand& dst, [[maybe_unused]] EncoderState& state, [[maybe_unused]] const Operand::None& src) noexcept
    {
        dst.type = ZydisOperandType::ZYDIS_OPERAND_TYPE_UNUSED;
        return ErrorCode::None;
    }

    static Error buildOperand(ZydisEncoderOperand& dst, EncoderState& state, const Operand& src)
    {
        return src.visit([&dst, &state](auto&& src2) { return buildOperand_(dst, state, src2); });
    }

    static void fixupIs4Operands(ZydisEncoderRequest& req) noexcept
    {
        switch (req.mnemonic)
        {
            case ZYDIS_MNEMONIC_VBLENDVPD:
            case ZYDIS_MNEMONIC_VBLENDVPS:
            case ZYDIS_MNEMONIC_VFMADDPD:
            case ZYDIS_MNEMONIC_VFMADDPS:
            case ZYDIS_MNEMONIC_VFMADDSD:
            case ZYDIS_MNEMONIC_VFMADDSS:
            case ZYDIS_MNEMONIC_VFMADDSUBPD:
            case ZYDIS_MNEMONIC_VFMADDSUBPS:
            case ZYDIS_MNEMONIC_VFMSUBADDPD:
            case ZYDIS_MNEMONIC_VFMSUBADDPS:
            case ZYDIS_MNEMONIC_VFMSUBPD:
            case ZYDIS_MNEMONIC_VFMSUBPS:
            case ZYDIS_MNEMONIC_VFMSUBSD:
            case ZYDIS_MNEMONIC_VFMSUBSS:
            case ZYDIS_MNEMONIC_VFNMADDPD:
            case ZYDIS_MNEMONIC_VFNMADDPS:
            case ZYDIS_MNEMONIC_VFNMADDSD:
            case ZYDIS_MNEMONIC_VFNMADDSS:
            case ZYDIS_MNEMONIC_VFNMSUBPD:
            case ZYDIS_MNEMONIC_VPMACSSDD:
            case ZYDIS_MNEMONIC_VPMACSSDQH:
            case ZYDIS_MNEMONIC_VFNMSUBPS:
            case ZYDIS_MNEMONIC_VFNMSUBSD:
            case ZYDIS_MNEMONIC_VFNMSUBSS:
            case ZYDIS_MNEMONIC_VPBLENDVB:
            case ZYDIS_MNEMONIC_VPCMOV:
            case ZYDIS_MNEMONIC_VPERMIL2PD:
            case ZYDIS_MNEMONIC_VPERMIL2PS:
            case ZYDIS_MNEMONIC_VPMACSDD:
            case ZYDIS_MNEMONIC_VPMACSDQH:
            case ZYDIS_MNEMONIC_VPMACSDQL:
            case ZYDIS_MNEMONIC_VPMACSSDQL:
            case ZYDIS_MNEMONIC_VPMACSSWW:
            case ZYDIS_MNEMONIC_VPMACSSWD:
            case ZYDIS_MNEMONIC_VPMACSWD:
            case ZYDIS_MNEMONIC_VPMACSWW:
            case ZYDIS_MNEMONIC_VPMADCSSWD:
            case ZYDIS_MNEMONIC_VPMADCSWD:
            case ZYDIS_MNEMONIC_VPPERM:
                break;
            default:
                return;
        }

        const auto opType2 = req.operands[2].type;
        const auto opType3 = req.operands[3].type;
        if (opType2 == ZYDIS_OPERAND_TYPE_REGISTER && opType3 == ZYDIS_OPERAND_TYPE_MEMORY)
        {
            req.operands[2].reg.is4 = ZYAN_TRUE;
        }
        else if (
            (opType2 == ZYDIS_OPERAND_TYPE_REGISTER && opType3 == ZYDIS_OPERAND_TYPE_REGISTER)
            || (opType2 == ZYDIS_OPERAND_TYPE_MEMORY && opType3 == ZYDIS_OPERAND_TYPE_REGISTER))
        {
            req.operands[3].reg.is4 = ZYAN_TRUE;
        }
    }

    static constexpr bool validateMachineMode(MachineMode mode)
    {
        switch (mode)
        {
            case MachineMode::Invalid:
                return false;
            case MachineMode::I386:
            case MachineMode::AMD64:
                return true;
            default:
                break;
        }
        return false;
    }

    static Error encode_(
        EncoderResult& res, EncoderContext* ctx, MachineMode mode, Instruction::Attribs attribs, Instruction::Mnemonic mnemonic,
        size_t numOps, const Operand* operands)
    {
        if (!validateMachineMode(mode))
        {
            return ErrorCode::InvalidMode;
        }

        res.buffer.length = 0;

        EncoderState state{};
        state.ctx = ctx;

        ZydisEncoderRequest& req = state.req;
        if (mode == MachineMode::AMD64)
        {
            req.machine_mode = ZYDIS_MACHINE_MODE_LONG_64;
            req.allowed_encodings = kAllowedEncodingX64;
        }
        else if (mode == MachineMode::I386)
        {
            req.machine_mode = ZYDIS_MACHINE_MODE_LONG_COMPAT_32;
            req.allowed_encodings = kAllowedEncodingX86;
        }
        req.mnemonic = static_cast<ZydisMnemonic>(mnemonic.value());
        req.prefixes = getAttribs(attribs);

        if (hasAttrib(attribs, x86::Attribs::OperandSize8))
        {
            req.operand_size_hint = ZydisOperandSizeHint::ZYDIS_OPERAND_SIZE_HINT_8;
        }
        else if (hasAttrib(attribs, x86::Attribs::OperandSize16))
        {
            req.operand_size_hint = ZydisOperandSizeHint::ZYDIS_OPERAND_SIZE_HINT_16;
        }
        else if (hasAttrib(attribs, x86::Attribs::OperandSize32))
        {
            req.operand_size_hint = ZydisOperandSizeHint::ZYDIS_OPERAND_SIZE_HINT_32;
        }
        else if (hasAttrib(attribs, x86::Attribs::OperandSize64))
        {
            req.operand_size_hint = ZydisOperandSizeHint::ZYDIS_OPERAND_SIZE_HINT_64;
        }

        const auto numOperands = std::min<std::size_t>(ZYDIS_ENCODER_MAX_OPERANDS, numOps);
        for (state.operandIndex = 0; state.operandIndex < numOperands; ++state.operandIndex)
        {
            auto& dstOp = req.operands[state.operandIndex];   // NOLINT
            const auto& srcOp = operands[state.operandIndex]; // NOLINT
            if (auto opStatus = buildOperand(dstOp, state, srcOp); opStatus != ErrorCode::None)
            {
                return opStatus;
            }
            req.operand_count++;
        }

        fixupIs4Operands(req);

        std::size_t bufLen = res.buffer.data.size();
        switch (auto status = ZydisEncoderEncodeInstruction(&req, res.buffer.data.data(), &bufLen); status)
        {
            case ZYAN_STATUS_SUCCESS:
                break;
            case ZYDIS_STATUS_IMPOSSIBLE_INSTRUCTION:
            default:
                return ErrorCode::ImpossibleInstruction;
        }

        res.buffer.length = static_cast<std::uint8_t>(bufLen);
        res.relocKind = state.relocKind;
        res.relocData = state.relocData;
        res.relocLabel = state.relocLabel;

        return ErrorCode::None;
    }

    Expected<EncoderResult, Error> encode(
        MachineMode mode, Instruction::Attribs attribs, Instruction::Mnemonic mnemonic, std::size_t numOps,
        const Operand* operands)
    {
        EncoderResult res;
        if (auto err = encode_(res, nullptr, mode, attribs, mnemonic, numOps, operands); err != ErrorCode::None)
        {
            return makeUnexpected(err);
        }
        return res;
    }

    static Expected<EncoderResult, Error> encodeWithContext(
        EncoderContext& ctx, MachineMode mode, Instruction::Attribs prefixes, Instruction::Mnemonic mnemonic,
        std::size_t numOps, const Operand* operands)
    {
        EncoderResult res;

        // encode_ will set this to kHintRequiresSize in case a length is required for correct encoding.
        ctx.instrSize = 0;

        if (const auto encodeError = encode_(res, &ctx, mode, prefixes, mnemonic, numOps, operands);
            encodeError != ErrorCode::None)
        {
            return makeUnexpected(encodeError);
        }

        while (ctx.instrSize == kHintRequiresSize)
        {
            // Encode with now known size, instruction size can change again in this call.
            ctx.instrSize = res.buffer.length;
            if (const auto encodeError = encode_(res, &ctx, mode, prefixes, mnemonic, numOps, operands);
                encodeError != ErrorCode::None)
            {
                return makeUnexpected(encodeError);
            }

            // If the instruction size does not match what we previously specified
            // we need to re-encode it with the now known size, this can happen near
            // the limits of rel8/32 but is unlikely.
            if (res.buffer.length != ctx.instrSize)
            {
                ctx.instrSize = kHintRequiresSize;
            }
        }

        return res;
    }

    Expected<EncoderResult, Error> encode(EncoderContext& ctx, MachineMode mode, const Instruction& instr)
    {
        const auto& ops = instr.getOperands();
        return encodeWithContext(ctx, mode, instr.getAttribs(), instr.getMnemonic(), instr.getOperandCount(), ops.data());
    }

} // namespace zasm
