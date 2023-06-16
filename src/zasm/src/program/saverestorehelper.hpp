#pragma once

#include "zasm/core/errors.hpp"

#include <filesystem>
#include <istream>
#include <type_traits>

namespace zasm
{
    constexpr std::uint32_t kZasmSignature = 0x504D535A; // ZSMP

    class SaveRestore
    {
        static constexpr bool kEnableVariableLengthEncoding = true;

        IStream& _stream;
        bool _isLoad{};

    public:
        SaveRestore(IStream& stream, bool isLoad)
            : _stream(stream)
            , _isLoad(isLoad)
        {
        }

        IStream& getStream()
        {
            return _stream;
        }

        Error write(const void* src, size_t length)
        {
            if (_isLoad)
            {
                return Error::InvalidOperation;
            }
            _stream.write(src, length);
            return Error::None;
        }

        Error read(void* dst, size_t length)
        {
            if (!_isLoad || _stream.isEnd())
            {
                return Error::InvalidOperation;
            }
            _stream.read(dst, length);
            return Error::None;
        }

        template<typename T> SaveRestore& operator<<(const T& value)
        {
            if (_isLoad)
                throw Error::InvalidOperation;

            using ValueType = std::decay_t<T>;

            static_assert(std::is_pointer_v<ValueType> == false, "Saving pointers is not supported");

            if constexpr (kEnableVariableLengthEncoding && std::is_integral_v<ValueType>)
            {
                if (auto err = writeVariableInteger(value); err != Error::None)
                    throw err;
            }
            else if constexpr (kEnableVariableLengthEncoding && std::is_enum_v<ValueType>)
            {
                if (auto err = writeVariableInteger(static_cast<std::underlying_type_t<ValueType>>(value)); err != Error::None)
                    throw err;
            }
            else
            {
                if (auto err = write(&value, sizeof(T)); err != Error::None)
                    throw err;
            }

            return *this;
        }

        template<typename T> SaveRestore& operator>>(T& value)
        {
            if (!_isLoad)
                throw Error::InvalidOperation;

            using ValueType = std::decay_t<T>;

            static_assert(std::is_pointer_v<ValueType> == false, "Loading pointers is not supported");

            if constexpr (kEnableVariableLengthEncoding && std::is_integral_v<ValueType>)
            {
                if (auto err = readVariableInteger(value); err != Error::None)
                    throw err;
            }
            else if constexpr (kEnableVariableLengthEncoding && std::is_enum_v<ValueType>)
            {
                using T2 = std::underlying_type_t<ValueType>;

                T2 tmp{};
                if (auto err = readVariableInteger(tmp); err != Error::None)
                    throw err;

                value = static_cast<T>(tmp);
            }
            else
            {
                if (auto err = read(static_cast<void*>(&value), sizeof(T)); err != Error::None)
                    throw err;
            }

            return *this;
        }

    private:
        template<typename T> Error writeVariableInteger(const T& value)
        {
            std::uint8_t tempBuffer[10];
            std::size_t bytesUsed{};

            std::make_unsigned_t<T> tmp = static_cast<std::make_unsigned_t<T>>(value);
            while (tmp > 0x7F)
            {
                tempBuffer[bytesUsed] = static_cast<std::uint8_t>(tmp & 0x7F) | 0x80;
                tmp >>= 7;
                bytesUsed++;
            }
            tempBuffer[bytesUsed++] = static_cast<std::uint8_t>(tmp & 0x7F);

            if (auto err = write(tempBuffer, bytesUsed); err != Error::None)
                return err;

            return Error::None;
        }

        template<typename T> Error readVariableInteger(T& value)
        {
            std::make_unsigned_t<T> tmp{};
            for (std::size_t i = 0;; i++)
            {
                std::uint8_t byte;
                if (auto err = read(&byte, sizeof(byte)); err != Error::None)
                    return err;

                tmp |= (static_cast<T>(byte) & 0x7F) << (i * 7);
                if ((byte & 0x80) == 0)
                    break;
            }
            value = static_cast<T>(tmp);
            return Error::None;
        }
    };

} // namespace zasm
