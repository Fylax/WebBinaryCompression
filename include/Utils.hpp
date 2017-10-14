/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_UTILS_H
#define WEB_BINARY_COMPRESSION_UTILS_H
#include <string_view>

namespace WebBinaryCompression {
/**
 * \brief Internal namespace which contains useful costants.
 * 
 * This namespace exists so that its internal constants are not included all
 * the time by others.
 */
namespace Utils {
/**
 * \brief Pre-computed powers of ten.
 */
constexpr std::uint_fast64_t kPowersOf10[20] = {
  1ULL,
  10ULL,
  100ULL,
  1000ULL,
  10000ULL,
  100000ULL,
  1000000ULL,
  10000000ULL,
  100000000ULL,
  1000000000ULL,
  10000000000ULL,
  100000000000ULL,
  1000000000000ULL,
  10000000000000ULL,
  100000000000000ULL,
  1000000000000000ULL,
  10000000000000000ULL,
  100000000000000000ULL,
  1000000000000000000ULL,
  10000000000000000000ULL
};
}  // namespace Utils

/**
 * \brief Converts a string_view to integer.
 * \param text String to be converted.
 * \return Converted integer.
 */
inline std::uint_fast64_t StringViewToInt(const std::string_view& text) {
  std::uint_fast64_t result = 0;
  const std::size_t length = text.length();
  std::size_t exponent = length;
  while (exponent) {
    result += (text[length - exponent] - '0') *
        Utils::kPowersOf10[exponent - 1];
    exponent -= 1;
  }
  return result;
}
}  // namespace WebBinaryCompression
#endif
