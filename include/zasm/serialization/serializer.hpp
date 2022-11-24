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
        std::size_t index{};
        const char* name{};
        Section::Attribs attribs{};
        std::int32_t offset{};
        std::int64_t address{};
        std::int64_t physicalSize{};
        std::int64_t virtualSize{};
    };

    struct RelocationInfo
    {
        std::int32_t offset{};
        std::int64_t address{};
        BitSize size{};
        RelocationType kind{};
        Label::Id label{ Label::Id::Invalid };
    };

    class Serializer
    {
        detail::SerializerState* _state{};

    public:
        Serializer();
        Serializer(const Serializer&) = delete;
        Serializer(Serializer&& other) noexcept;
        ~Serializer();

        Serializer& operator=(const Serializer&) = delete;
        Serializer& operator=(Serializer&& other) noexcept;

        /// <summary>
        /// Serializes the all the nodes in the Program to the encoder and
        /// resolves the address of each label.
        /// </summary>
        /// <param name="newBase">Virtual base address at where the code starts</param>
        /// <returns>If successful returns Error::None otherwise check Error value.</returns>
        Error serialize(const Program& program, std::int64_t newBase);

        /// <summary>
        /// Serializes the specified range in the Program to the encoder and
        /// resolves the address of each label.
        /// </summary>
        /// <param name="program"></param>
        /// <param name="newBase">Virtual base address at where the code starts</param>
        /// <param name="first">First node to encode</param>
        /// <param name="last">Last node to encode</param>
        /// <returns>If successful returns Error::None otherwise check Error value.</returns>
        Error serialize(const Program& program, std::int64_t newBase, const Node* first, const Node* last);

        /// <summary>
        /// Attempts to relocate the current serialized code to the new specified base address.
        /// </summary>
        /// <param name="newBase">Virtual base address at where the code starts</param>
        /// <returns>If successful returns Error::None otherwise check Error value.</returns>
        Error relocate(std::int64_t newBase);

        /// <summary>
        /// Returns the last base address used in a successful serialize call.
        /// </summary>
        /// <returns>Current base address</returns>
        std::int64_t getBase() const noexcept;

        /// <summary>
        /// After a successful serialization this will return the total size of all encoded nodes not
        /// including section alignment. This is the size of the flat buffer used to encode every node,
        /// this may be primarily useful if no sections are used.
        /// </summary>
        /// <returns>Size of code in bytes</returns>
        std::size_t getCodeSize() const noexcept;

        /// <summary>
        /// After a successful serialization this returns pointer to the current code buffer, this is a
        /// flat buffer containing all sections if multiple sections are used without any padding. If you
        /// require the per section basis data use the section functions.
        /// </summary>
        /// <returns>Pointer to code buffer</returns>
        const std::uint8_t* getCode() const noexcept;

        /// <summary>
        /// Returns the amount of encoded sections. By default there is always at least 1 section even if
        /// no section was explicitly created.
        /// </summary>
        /// <returns>Section count</returns>
        std::size_t getSectionCount() const noexcept;

        /// <summary>
        /// Returns the information about the section after serialization.
        /// </summary>
        /// <returns>Pointer to the section info, nullptr if the index is invalid</returns>
        const SectionInfo* getSectionInfo(std::size_t sectionIndex) const noexcept;

        /// <summary>
        /// Returns the offset of the label, the offset is the position in the code buffer.
        /// </summary>
        /// <param name="labelId"></param>
        /// <returns>Offset of label or -1 if the label is not bound or found</returns>
        std::int32_t getLabelOffset(Label::Id labelId) const noexcept;

        /// <summary>
        /// Returns the address of the label, the address is the virtual address specified by base.
        /// </summary>
        /// <param name="labelId"></param>
        /// <returns>Address of label or -1 if the label is not bound or found.</returns>
        std::int64_t getLabelAddress(Label::Id labelId) const noexcept;

        /// <summary>
        /// Returns the amount of relocation items.
        /// </summary>
        std::size_t getRelocationCount() const noexcept;

        /// <summary>
        /// Returns the relocation info of the specified index.
        /// </summary>
        /// <param name="index">Index of the relocation item</param>
        /// <returns>Pointer to relocation info or null in case the index does not exist</returns>
        const RelocationInfo* getRelocation(std::size_t index) const noexcept;

        /// <summary>
        /// Returns the amount of external relocation items.
        /// </summary>
        std::size_t getExternalRelocationCount() const noexcept;

        /// <summary>
        /// Returns the external relocation info of the specified index.
        /// </summary>
        /// <param name="index">Index of the relocation item</param>
        /// <returns>Pointer to relocation info or null in case the index does not exist</returns>
        const RelocationInfo* getExternalRelocation(std::size_t index) const noexcept;

        /// <summary>
        /// Clears the current serialized state.
        /// </summary>
        void clear() noexcept;
    };

} // namespace zasm
