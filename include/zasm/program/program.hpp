#pragma once

#include "data.hpp"
#include "label.hpp"
#include "node.hpp"

#include <cstdint>
#include <zasm/core/errors.hpp>

namespace zasm
{
    namespace detail
    {
        struct ProgramState;
    }

    class Program
    {
        detail::ProgramState* _state;

    public:
        Program(ZydisMachineMode mode);
        ~Program();

        ZydisMachineMode getMode() const;

    public:
        const Node* getHead() const;
        const Node* getTail() const;

        const Node* prepend(const Node* node);
        const Node* append(const Node* node);

        const Node* insertBefore(const Node* pos, const Node* node);
        const Node* insertAfter(const Node* pos, const Node* node);

        size_t size() const;

    public:
        const Node* createNode(const Instruction& instr);
        const Node* createNode(const Label& label);
        const Node* createNode(const Data& data);
        const Node* createNode(Data&& data);

    public:
        const Label createLabel(const char* name = nullptr);
        const Node* bindLabel(const Label& label);

        const Data createData(const void* ptr, size_t len);

    public:
        Error serialize(int64_t newBase);

        size_t getCodeSize() const;
        const uint8_t* getCode() const;
    };

} // namespace zasm