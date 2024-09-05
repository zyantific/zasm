#pragma once

#include "zasm/core/enumflags.hpp"
#include "zasm/core/objectpool.hpp"
#include "zasm/core/stringpool.hpp"
#include "zasm/encoder/encoder.hpp"
#include "zasm/program/data.hpp"
#include "zasm/program/labeldata.hpp"
#include "zasm/program/node.hpp"
#include "zasm/program/section.hpp"

#include <Zydis/Zydis.h>
#include <cstddef>
#include <tuple>
#include <vector>
#include <zasm/base/label.hpp>
#include <zasm/base/mode.hpp>

namespace zasm
{
    class Observer;
}

namespace zasm::detail
{
    struct LabelData
    {
        Label::Id id{ Label::Id::Invalid };
        LabelFlags flags{ LabelFlags::None };
        StringPool::Id nameId{ StringPool::Id::Invalid };
        StringPool::Id moduleId{ StringPool::Id::Invalid };

        // The node that holds/binds the label in the list.
        zasm::Node* node{};
    };

    struct SectionData
    {
        Section::Id id{ Section::Id::Invalid };
        StringPool::Id nameId{ StringPool::Id::Invalid };
        Section::Attribs attribs{};
        std::int32_t align{};

        // The node that holds/binds the label in the list.
        zasm::Node* node{};
    };

    namespace detail
    {
        template<typename T>
        struct PoolSize
        {
            static constexpr std::size_t kSize = 50'000;
        };

        template<> struct PoolSize<Instruction>
        {
            static constexpr std::size_t kSize = 30'000;
        };

        template<typename... TTypes> struct ObjectPools
        {
            std::tuple<ObjectPool<TTypes, PoolSize<TTypes>::kSize>...> pools;

            template<typename T> auto& get()
            {
                return std::get<ObjectPool<T, PoolSize<T>::kSize>>(pools);
            }

            void reset()
            {
                std::apply([](auto&... pool) { (pool.reset(), ...); }, pools);
            }
        };
    } // namespace detail

    using ObjectPools = detail::ObjectPools<zasm::Node, Sentinel, Instruction, Label, EmbeddedLabel, Data, Section, Align>;

    struct NodeList
    {
        Node* head{};
        Node* tail{};
        std::size_t nodeCount{};
    };

    struct Symbols
    {
        StringPool symbolNames;
    };

    struct ProgramState : NodeList, Symbols
    {
        MachineMode mode{};

        std::vector<LabelData> labels;
        std::vector<SectionData> sections;

        // Registered program observer.
        std::vector<Observer*> observer;

        // The index is the id of the node this allows for quick access to nodes by id.
        std::vector<Node*> nodeMap;

        Label entryPoint{ Label::Id::Invalid };

        ObjectPools objectPools;
        Node::Id nextNodeId{};

        ProgramState(MachineMode m)
            : mode(m)
        {
        }
    };

} // namespace zasm::detail
