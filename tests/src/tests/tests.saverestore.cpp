#include "../testutils.hpp"

#include <gtest/gtest.h>
#include <sstream>
#include <zasm/core/memorystream.hpp>
#include <zasm/program/saverestore.hpp>
#include <zasm/testdata/x86/instructions.hpp>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    static void createTestInstructions(Program& program)
    {
        x86::Assembler assembler(program);

        std::size_t entries = 0;
        for (const auto& instrEntry : data::Instructions)
        {
            if (entries % 20 == 0)
            {
                auto label = assembler.createLabel();
                assembler.bind(label);
            }
            ASSERT_EQ(instrEntry.emitter(assembler), ErrorCode::None) << instrEntry.instrBytes << ", " << instrEntry.operation;
            entries++;
        }
    }

    static void compareNode(const Sentinel& lhs, const Sentinel& rhs)
    {
        // Nothing to do.
    }

    static void compareNode(const Label& lhs, const Label& rhs)
    {
        ASSERT_EQ(lhs, rhs);
    }

    static void compareNode(const Section& lhs, const Section& rhs)
    {
        ASSERT_EQ(lhs, rhs);
    }

    static void compareNode(const EmbeddedLabel& lhs, const EmbeddedLabel& rhs)
    {
        ASSERT_EQ(lhs, rhs);
    }

    static void compareNode(const Data& lhs, const Data& rhs)
    {
        ASSERT_EQ(lhs, rhs);
    }

    static void compareNode(const Align& lhs, const Align& rhs)
    {
        ASSERT_EQ(lhs, rhs);
    }

    static void compareNode(const Instruction& lhs, const Instruction& rhs)
    {
        ASSERT_EQ(lhs, rhs);
    }

    static void comparePrograms(const Program& lhs, const Program& rhs)
    {
        ASSERT_EQ(lhs.size(), rhs.size());
        ASSERT_EQ(lhs.getMode(), rhs.getMode());

        auto* nodeLhs = lhs.getHead();
        auto* nodeRhs = rhs.getHead();
        while (nodeLhs != nullptr)
        {
            ASSERT_EQ(nodeLhs->getId(), nodeRhs->getId());

            nodeLhs->visit([&](const auto& valLhs) {
                const auto& valRhs = nodeRhs->get<std::decay_t<decltype(valLhs)>>();
                compareNode(valLhs, valRhs);
            });

            nodeLhs = nodeLhs->getNext();
            nodeRhs = nodeRhs->getNext();
        }
    }

    TEST(SaveRestoreTests, SaveRestoreMemoryBuf)
    {
        Program outputProgram(MachineMode::AMD64);
        createTestInstructions(outputProgram);

        // Save Program.
        MemoryStream buf;
        ASSERT_EQ(save(outputProgram, buf), ErrorCode::None);

        // Read the serialized data back into a separate program.

        buf.seek(0, SeekType::Begin);
        auto inputProgram = load(buf);
        ASSERT_EQ(inputProgram.hasValue(), true);

        // Compare against base
        comparePrograms(outputProgram, *inputProgram);
    }

    TEST(SaveRestoreTests, SaveRestoreFile)
    {
        Program outputProgram(MachineMode::AMD64);
        createTestInstructions(outputProgram);

        // Save Program.
        const auto filePath = std::filesystem::temp_directory_path() / "saverestoretest.zasm";
        ASSERT_EQ(save(outputProgram, filePath), ErrorCode::None);

        // Read the serialized data back into a separate program.
        auto inputProgram = load(filePath);
        ASSERT_EQ(inputProgram.hasValue(), true);

        // Compare against base
        comparePrograms(outputProgram, *inputProgram);
    }

    TEST(SaveRestoreTests, SaveRestoreSymbols)
    {
        Program outputProgram(MachineMode::AMD64);

        auto label = outputProgram.createLabel("hello world");
        auto nodeRes = outputProgram.bindLabel(label);
        ASSERT_EQ(nodeRes.hasValue(), true);
        outputProgram.append(nodeRes.value());

        // Save Program.
        MemoryStream buf;
        ASSERT_EQ(save(outputProgram, buf), ErrorCode::None);

        // Read the serialized data back into a separate program.
        buf.seek(0, SeekType::Begin);
        auto inputProgram = load(buf);
        ASSERT_EQ(inputProgram.hasValue(), true);

        // Compare against base
        auto* headNode = inputProgram->getHead();
        ASSERT_NE(headNode, nullptr);
        auto* labelNode = headNode->getIf<Label>();
        ASSERT_NE(labelNode, nullptr);
        ASSERT_EQ(labelNode->getId(), label.getId());
        auto labelInfo = inputProgram->getLabelData(*labelNode);
        ASSERT_EQ(labelInfo.hasValue(), true);
        ASSERT_EQ(std::string(labelInfo->name), "hello world");
    }

} // namespace zasm::tests
