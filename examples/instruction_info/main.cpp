#include "examples.common.hpp"

#include <iostream>
#include <zasm/x86/meta.hpp>

static std::string getCPUFlagsString(zasm::InstrCPUFlags flags)
{
    namespace CPUFlags = zasm::x86::CPUFlags;

    std::string str;

    const auto appendFlag = [&](auto fl, const auto& name) {
        if ((flags & fl) != CPUFlags::None)
        {
            if (!str.empty())
                str += " | ";
            str += name;
        }
    };

    appendFlag(CPUFlags::CF, "CF");
    appendFlag(CPUFlags::PF, "PF");
    appendFlag(CPUFlags::AF, "AF");
    appendFlag(CPUFlags::ZF, "ZF");
    appendFlag(CPUFlags::SF, "SF");
    appendFlag(CPUFlags::TF, "TF");
    appendFlag(CPUFlags::IF, "IF");
    appendFlag(CPUFlags::DF, "DF");
    appendFlag(CPUFlags::OF, "OF");
    appendFlag(CPUFlags::IOPL1, "IOPL1");
    appendFlag(CPUFlags::IOPL2, "IOPL2");
    appendFlag(CPUFlags::NT, "NT");
    appendFlag(CPUFlags::RF, "RF");
    appendFlag(CPUFlags::VM, "VM");
    appendFlag(CPUFlags::AC, "AC");
    appendFlag(CPUFlags::VIF, "VIF");
    appendFlag(CPUFlags::VIP, "VIP");
    appendFlag(CPUFlags::ID, "ID");

    return str;
}

static void printInstructionInfo(zasm::MachineMode mode, const zasm::Instruction& instr)
{
    using namespace zasm;

    const auto info = instr.getDetail(mode);
    if (!info.hasValue())
    {
        std::cout << "Failed to get instruction info\n";
        return;
    }

    std::cout << "Instruction: " << formatter::toString(&instr) << " {\n";

    const auto& cpuFlags = info->getCPUFlags();
    std::cout << "  CPUFlags = {\n";
    if (cpuFlags.set0 != x86::CPUFlags::None)
        std::cout << "    Set 0 = " << getCPUFlagsString(cpuFlags.set0) << ",\n";
    if (cpuFlags.set1 != x86::CPUFlags::None)
        std::cout << "    Set 1 = " << getCPUFlagsString(cpuFlags.set1) << ",\n";
    if (cpuFlags.modified != x86::CPUFlags::None)
        std::cout << "    Modified = " << getCPUFlagsString(cpuFlags.modified) << ",\n";
    if (cpuFlags.tested != x86::CPUFlags::None)
        std::cout << "    Tested = " << getCPUFlagsString(cpuFlags.tested) << ",\n";
    if (cpuFlags.undefined != x86::CPUFlags::None)
        std::cout << "    Undefined = " << getCPUFlagsString(cpuFlags.undefined) << ",\n";
    std::cout << "  },\n";

    for (size_t i = 0; i < info->getOperandCount(); ++i)
    {
        const Operand& op = info->getOperand(i);

        std::cout << "  Operand[" << i << "] = {\n";
        
        std::cout << "    Size = " << getBitSize(op.getBitSize(mode)) << "b,\n";
        
        if (auto* opMem = op.getIf<Mem>(); opMem != nullptr)
        {
            std::cout << "    Type = Mem(\n";
            std::cout << "      Seg:   " << formatter::toString(opMem->getSegment()) << "\n";
            std::cout << "      Base:  " << formatter::toString(opMem->getBase()) << "\n";
            std::cout << "      Index: " << formatter::toString(opMem->getIndex()) << "\n";
            std::cout << "      Scale: " << (int)opMem->getScale() << "\n";
            std::cout << "      Disp:  " << opMem->getDisplacement() << "\n";
            std::cout << "    ),\n";
        }
        else if (auto* opReg = op.getIf<Reg>(); opReg != nullptr)
        {
            std::cout << "    Type = Reg(\n";
            std::cout << "      " << formatter::toString(*opReg) << "\n";
            std::cout << "    ),\n";
        }
        else if (auto* opImm = op.getIf<Imm>(); opImm != nullptr)
        {
            std::cout << "    Imm(\n";
            std::cout << "      " << opImm->value<int64_t>() << "\n";
            std::cout << "    ),\n";
        }
        else if (auto* opLabel = op.getIf<Label>(); opLabel != nullptr)
        {
            std::cout << "    Label(\n";
            std::cout << "      " << static_cast<int32_t>(opLabel->getId()) << "\n";
            std::cout << "    ),\n";
        }

        std::cout << "    Access = ";
        const auto opAccess = info->getOperandAccess(i);
        if (opAccess == Operand::Access::None)
            std::cout << "none\n";
        else
        {
            if ((opAccess & Operand::Access::CondRead) != Operand::Access::None)
                std::cout << "CondRead ";
            else if ((opAccess & Operand::Access::Read) != Operand::Access::None)
                std::cout << "Read ";

            if ((opAccess & Operand::Access::CondWrite) != Operand::Access::None)
                std::cout << "CondWrite ";
            else if ((opAccess & Operand::Access::Write) != Operand::Access::None)
                std::cout << "Write ";

            std::cout << ",\n";
        }

        std::cout << "    Visibility = ";
        const Operand::Visibility opVis = info->getOperandVisibility(i);
        switch (opVis)
        {
            case Operand::Visibility::Invalid:
                std::cout << "Invalid";
                break;
            case Operand::Visibility::Explicit:
                std::cout << "Explicit";
                break;
            case Operand::Visibility::Implicit:
                std::cout << "Implicit";
                break;
            case Operand::Visibility::Hidden:
                std::cout << "Hidden";
                break;
        }
        std::cout << ",\n";

        std::cout << "  },\n";
    }
    std::cout << "}\n";
}

int main()
{
    using namespace zasm;

    {
        const auto instr = Instruction()                        //
                               .setMnemonic(x86::Mnemonic::Sub) //
                               .addOperand(x86::rax)            //
                               .addOperand(Imm(1));             //
        printInstructionInfo(MachineMode::AMD64, instr);
    }

    {
        const auto instr = Instruction()                        //
                               .setMnemonic(x86::Mnemonic::Mov) //
                               .addOperand(x86::rax)            //
                               .addOperand(Imm(1));             //
        printInstructionInfo(MachineMode::AMD64, instr);
    }

    {
        const auto instr = Instruction()                         //
                               .setMnemonic(x86::Mnemonic::Call) //
                               .addOperand(Label(Label::Id(1))); //
        printInstructionInfo(MachineMode::AMD64, instr);
    }

    {
        const auto instr = Instruction()                         //
                               .setMnemonic(x86::Mnemonic::Call) //
                               .addOperand(Imm(0));              //
        printInstructionInfo(MachineMode::AMD64, instr);
    }

    {
        const auto instr = Instruction()                         //
                               .setMnemonic(x86::Mnemonic::Ret); //
        printInstructionInfo(MachineMode::AMD64, instr);
    }

    {
        const auto instr = Instruction(x86::Mnemonic::Inc)            //
                               .addAttribs(x86::Attribs::Lock)        //
                               .addOperand(x86::dword_ptr(x86::eax)); //
        printInstructionInfo(MachineMode::AMD64, instr);
    }
}
