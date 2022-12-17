#include <gtest/gtest.h>
#include <zasm/program/observer.hpp>
#include <zasm/zasm.hpp>

namespace zasm::tests
{
    
    struct TestObserver final : zasm::Observer
    {
        size_t nodesCreated{};
        size_t nodesInserted{};
        size_t nodesDestroyed{};
        size_t nodesDetached{};
        
        void onNodeCreated(Node* node) override
        {
            nodesCreated++;
        }
        void onNodeDestroy(Node* node) override
        {
            nodesDestroyed++;
        }
        void onNodeInserted(Node* node) override
        {
            nodesInserted++;
        }
        void onNodeDetach(Node* node) override
        {
            nodesDetached++;
        }
    };
    
    TEST(ObserverTests, TestNodeCreate)
    {
        Program program(MachineMode::AMD64);

        TestObserver observer;
        program.addObserver(observer);
        
        x86::Assembler assembler(program);
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeA = assembler.getCursor();
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeB = assembler.getCursor();
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeC = assembler.getCursor();
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeD = assembler.getCursor();
        
        ASSERT_EQ(observer.nodesCreated, 4);
        ASSERT_EQ(observer.nodesInserted, 4);
        ASSERT_EQ(observer.nodesDestroyed, 0);
        ASSERT_EQ(observer.nodesDetached, 0);
    }
    
    TEST(ObserverTests, TestNodeDestroy)
    {
        Program program(MachineMode::AMD64);

        TestObserver observer;
        program.addObserver(observer);

        x86::Assembler assembler(program);
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeA = assembler.getCursor();
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeB = assembler.getCursor();
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeC = assembler.getCursor();
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeD = assembler.getCursor();

        program.destroy(nodeC);

        ASSERT_EQ(observer.nodesCreated, 4);
        ASSERT_EQ(observer.nodesInserted, 4);
        ASSERT_EQ(observer.nodesDestroyed, 1);
        ASSERT_EQ(observer.nodesDetached, 0);
    }

    TEST(ObserverTests, TestNodeDetach)
    {
        Program program(MachineMode::AMD64);

        TestObserver observer;
        program.addObserver(observer);

        x86::Assembler assembler(program);
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeA = assembler.getCursor();
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeB = assembler.getCursor();
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeC = assembler.getCursor();
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeD = assembler.getCursor();

        program.detach(nodeC);

        ASSERT_EQ(observer.nodesCreated, 4);
        ASSERT_EQ(observer.nodesInserted, 4);
        ASSERT_EQ(observer.nodesDestroyed, 0);
        ASSERT_EQ(observer.nodesDetached, 1);
    }

    
    TEST(ObserverTests, TestNodeDetachInsert)
    {
        Program program(MachineMode::AMD64);

        TestObserver observer;
        program.addObserver(observer);

        x86::Assembler assembler(program);
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeA = assembler.getCursor();
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeB = assembler.getCursor();
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeC = assembler.getCursor();
        assembler.mov(x86::rax, x86::rbx);
        auto* nodeD = assembler.getCursor();

        program.detach(nodeC);
        program.insertAfter(nodeB, nodeC);
        
        ASSERT_EQ(observer.nodesCreated, 4);
        ASSERT_EQ(observer.nodesInserted, 5);
        ASSERT_EQ(observer.nodesDestroyed, 0);
        ASSERT_EQ(observer.nodesDetached, 1);
    }

} // namespace zasm::tests
