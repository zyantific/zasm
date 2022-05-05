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
        int64_t offset{};
        BitSize size{};
        RelocationKind kind{};
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
        /// <param name="newBase">Virtual base address at where the code starts</param>
        /// <returns>If successful returns Error::None otherwise check Error value.</returns>
        Error serialize(const Program& program, int64_t newBase);

        /// <summary>
        /// Attempts to relocate the current serialized code to the new specified base address.
        /// </summary>
        /// <param name="newBase">Virtual base address at where the code starts</param>
        /// <returns>If successful returns Error::None otherwise check Error value.</returns>
        Error relocate(int64_t newBase);

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
        size_t getCodeSize() const noexcept;

        /// <summary>
        /// After a successful serialization this returns pointer to the current code buffer, this is a
        /// flat buffer containing all sections if multiple sections are used without any padding. If you
        /// require the per section basis data use the section functions.
        /// </summary>
        /// <returns>Pointer to code buffer</returns>
        const uint8_t* getCode() const noexcept;

        /// <summary>
        /// Returns the amount of encoded sections. By default there is always at least 1 section even if
        /// no section was explicitly created.
        /// </summary>
        /// <returns>Section count</returns>
        size_t getSectionCount() const noexcept;

        /// <summary>
        /// Returns the information about the section after serialization.
        /// </summary>
        /// <returns>Pointer to the section info, nullptr if the index is invalid</returns>
        const SectionInfo* getSectionInfo(size_t sectionIndex) const noexcept;

        /// <summary>
        /// Returns the offset of the label, the offset is the position in the code buffer.
        /// </summary>
        /// <param name="labelId"></param>
        /// <returns>Offset of label or -1 if the label is not bound or found</returns>
        int64_t getLabelOffset(const Label::Id labelId) const noexcept;

        /// <summary>
        /// Returns the address of the label, the address is the virtual address specified by base.
        /// </summary>
        /// <param name="labelId"></param>
        /// <returns>Address of label or -1 if the label is not bound or found.</returns>
        int64_t getLabelAddress(const Label::Id labelId) const noexcept;

        /// <summary>
        /// Returns the amount of relocation items.
        /// </summary>
        size_t getRelocationCount() const noexcept;

        /// <summary>
        /// Returns the relocation info of the specified index.
        /// </summary>
        /// <param name="index">Index of the relocation item</param>
        /// <returns>Pointer to relocation info or null in case the index does not exist</returns>
        const RelocationInfo* getRelocation(const size_t index) const noexcept;

        /// <summary>
        /// Clears the current serialized state.
        /// </summary>
        void clear();
    };

} // namespace zasm