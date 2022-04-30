#pragma once

#include <cstdint>
#include <zasm/core/errors.hpp>
#include <zasm/core/expected.hpp>
#include <zasm/encoder/encoder.hpp>
#include <zasm/program/program.hpp>

namespace zasm
{

    namespace detail
    {
        struct SerializerState;
    }

    struct SectionInfo
    {
        size_t index{};
        const char* name{};
        Section::Attribs attribs{};
        int64_t va{};
        const uint8_t* buffer{};
        size_t physicalSize{};
        size_t virtualSize{};
    };

    struct RelocationInfo
    {
        uint32_t offset{};
        uint32_t size{};
        RelocKind kind{};
    };

    class Serializer
    {
        detail::SerializerState* _state;

    public:
        Serializer();
        ~Serializer();

        /// <summary>
        /// Serializes the all the nodes in the Program to the encoder and
        /// resolves the address of each label.
        /// </summary>
        /// <param name="newBase">The starting address of the program</param>
        /// <returns>If successful returns Error::None otherwise check Error value.</returns>
        Error serialize(const Program& program, int64_t newBase);

        /// <summary>
        /// Returns the last base address used in a successful serialize call.
        /// </summary>
        /// <returns>Current base address</returns>
        int64_t getBase() const noexcept;

        /// <summary>
        /// After a successful serialization this will return the total size of all encoded nodes not
        /// including section alignment. This is the size of the flat buffer used to encode every node,
        /// this may be primarily useful if no sections are used.
        /// </summary>
        /// <returns>Size of code in bytes</returns>
        size_t getCodeSize() const;

        /// <summary>
        /// After a successful serialization this returns pointer to the current code buffer, this is a
        /// flat buffer containing all sections if multiple sections are used without any padding. If you
        /// require the per section basis data use the section functions.
        /// </summary>
        /// <returns>Pointer to code buffer</returns>
        const uint8_t* getCode() const;

        /// <summary>
        /// Returns the amount of encoded sections. By default there is always at least 1 section even if
        /// no section was explicitly created.
        /// </summary>
        /// <returns>Section count</returns>
        size_t getSectionCount() const;

        /// <summary>
        /// Returns the information about the section after serialization.
        /// </summary>
        /// <returns>Pointer to the section info, nullptr if the index is invalid</returns>
        const SectionInfo* getSectionInfo(size_t sectionIndex) const;

        void clear();
    };

} // namespace zasm