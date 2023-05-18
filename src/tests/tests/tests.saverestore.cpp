#include "../testutils.hpp"

#include <gtest/gtest.h>
#include <sstream>
#include <testdata/instructions.hpp>
#include <zasm/core/memorystream.hpp>
#include <zasm/program/saverestore.hpp>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
#ifdef _DEBUG
    static constexpr size_t kTestDataRepeats = 1;
#else
    static constexpr size_t kTestDataRepeats = 100;
#endif

    static void createTestInstructions(Program& program, std::size_t repeats = 1)
    {
        x86::Assembler assembler(program);
        for (std::size_t i = 0; i < repeats; ++i)
        {
            for (const auto& instrEntry : data::Instructions)
            {
                ASSERT_EQ(instrEntry.emitter(assembler), Error::None) << instrEntry.instrBytes << ", " << instrEntry.operation;
            }
        }
        std::cout << "Program Size: " << program.size() << "\n";
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
        createTestInstructions(outputProgram, kTestDataRepeats);

        // Save Program.
        MemoryStream buf;
        ASSERT_EQ(save(outputProgram, buf), Error::None);

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
        createTestInstructions(outputProgram, kTestDataRepeats);

        // Save Program.
        const auto filePath = std::filesystem::temp_directory_path() / "saverestoretest.zasm";
        ASSERT_EQ(save(outputProgram, filePath), Error::None);

        // Read the serialized data back into a separate program.
        auto inputProgram = load(filePath);
        ASSERT_EQ(inputProgram.hasValue(), true);

        // Compare against base
        comparePrograms(outputProgram, *inputProgram);
    }

} // namespace zasm::tests
