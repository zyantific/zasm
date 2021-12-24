#include "testutils.hpp"

namespace zasm::tests
{

    std::vector<uint8_t> hexDecode(std::string_view input)
    {
        if (input.size() % 2 != 0)
        {
            throw std::runtime_error("Invalid hex format");
        }

        std::vector<uint8_t> res;
        res.resize(input.size() / 2);

        char temp[3]{};
        for (size_t i = 0; i < input.size(); i += 2)
        {
            temp[0] = input[i + 0];
            temp[1] = input[i + 1];
            res[i / 2] = static_cast<uint8_t>(std::stoul(temp, nullptr, 16));
        }

        return res;
    }

    std::string hexEncode(const uint8_t* data, size_t size)
    {
        std::string res;
        res.reserve(size * 2);
        char temp[3]{};
        for (size_t i = 0; i < size; i++)
        {
            snprintf(temp, std::size(temp), "%02X", data[i]);
            res += temp;
        }
        return res;
    }

}