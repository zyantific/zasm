#pragma once

#include <gtest/gtest.h>
#include <ostream>
#include <string>
#include <vector>
#include <zasm/core/bitsize.hpp>
#include <zasm/core/errors.hpp>

namespace zasm::tests
{
    std::vector<uint8_t> hexDecode(std::string_view input);

    std::string hexEncode(const uint8_t* data, size_t N);

    std::ostream& operator<<(std::ostream& os, const BitSize& s);
    std::ostream& operator<<(std::ostream& os, const Error& err);

} // namespace zasm::tests
