#pragma once

#include <array>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <zasm/decoder/decoder.hpp>
#include <zasm/formatter/formatter.hpp>
#include <zasm/serialization/serializer.hpp>
#include <zasm/zasm.hpp>

namespace zasm::examples::utils
{

    static std::string getHexDump(const uint8_t* buf, size_t len)
    {
        std::string res;
        for (size_t i = 0; i < len; i++)
        {
            char temp[3]{};
            int len = snprintf(temp, std::size(temp), "%02X", buf[i]);
            if (len < 0)
            {
                return {};
            }
            res.append(temp, static_cast<std::size_t>(len));
        }
        return res;
    }

    static std::string getFormattedAddress(uint64_t addr)
    {
        char buf[32]{};
        int len = snprintf(buf, sizeof(buf), "0x%.16llX", (unsigned long long)addr);
        if (len < 0)
        {
            return {};
        }
        return std::string(buf, static_cast<std::size_t>(len));
    }

    static std::string getDisassemblyDump(const zasm::Serializer& serializer, const zasm::MachineMode mode)
    {
        constexpr auto kCountColumns = 3U;
        constexpr auto kDefaultSecondColSize = 16U;

        struct Row
        {
            std::array<std::string, kCountColumns> values;
        };
        std::vector<Row> rows;

        std::array<std::size_t, kCountColumns> columnMaxLength{ 0U, kDefaultSecondColSize, 0U };

        const auto addRow = [&](const std::string& col0, const std::string& col1, const std::string& col2) {
            Row row;
            row.values[0] = col0;
            row.values[1] = col1;
            row.values[2] = col2;
            rows.push_back(std::move(row));
            columnMaxLength[0] = std::max(columnMaxLength[0], col0.size());
            columnMaxLength[1] = std::max(columnMaxLength[1], col1.size());
            columnMaxLength[2] = std::max(columnMaxLength[2], col2.size());
        };

        zasm::Decoder decoder(mode);

        for (size_t sectIdx = 0; sectIdx < serializer.getSectionCount(); ++sectIdx)
        {
            const auto* sect = serializer.getSectionInfo(sectIdx);
            const auto sectLen = sect->physicalSize;
            const auto* sectBuf = serializer.getCode() + sect->offset;

            addRow(getFormattedAddress(sect->address), ".section", sect->name);

            if ((sect->attribs & zasm::Section::Attribs::Exec) != zasm::Section::Attribs::None)
            {
                for (std::int64_t sectOffset = 0; sectOffset < sectLen;)
                {
                    const auto curAddress = sect->address + sectOffset;

                    auto res = decoder.decode(sectBuf + sectOffset, sectLen - sectOffset, curAddress);
                    if (!res.hasValue())
                    {
                        std::cout << "Decoder Error: " << res.error().getErrorName() << std::endl;
                        break;
                    }

                    const auto decodedInstr = res.value().getInstruction();
                    addRow(
                        getFormattedAddress(curAddress), getHexDump(sectBuf + sectOffset, res->getLength()),
                        zasm::formatter::toString(&decodedInstr));

                    sectOffset += res->getLength();
                }
            }
            else
            {
                const auto bytesPerLine = 16;

                for (std::int64_t sectOffset = 0; sectOffset < sectLen;)
                {
                    const auto curAddress = sect->address + sectOffset;
                    const auto rowLength = std::min<std::int64_t>(16, sectLen - sectOffset);

                    std::string bytesText;
                    for (std::int64_t i = 0; i < rowLength; i++)
                    {
                        char temp[4];
                        if (bytesText.empty())
                            snprintf(temp, sizeof(temp), "%02X", sectBuf[sectOffset + i]);
                        else
                            snprintf(temp, sizeof(temp), " %02X", sectBuf[sectOffset + i]);
                        bytesText += temp;
                    }

                    addRow(getFormattedAddress(curAddress), "", bytesText);

                    sectOffset += rowLength;
                }
            }
        }

        std::stringstream res;
        for (size_t i = 0; i < rows.size(); ++i)
        {
            const auto& row = rows[i];
            if (i > 0)
                res << "\n";
            res << row.values[0] << " | " << std::setw(columnMaxLength[1]) << std::setfill(' ') << row.values[1] << " | "
                << row.values[2];
        }

        return res.str();
    }
} // namespace zasm::examples::utils
