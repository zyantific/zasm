#pragma once

#include <vector>
#include <string>
#include <gtest/gtest.h>

namespace zasm::tests
{
    std::vector<uint8_t> hexDecode(std::string_view input);

    std::string hexEncode(const uint8_t* data, size_t N);

}