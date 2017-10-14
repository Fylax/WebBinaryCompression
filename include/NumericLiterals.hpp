/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_NUMERIC_LITERALS_H
#define WEB_BINARY_COMPRESSION_NUMERIC_LITERALS_H
#include <cstdint>

namespace WebBinaryCompression {
/**
 * \brief Makes an unsigned integer on 8 bits
 * \param v Unsigned integer
 * \return 8 bit unsigned integer of requested value
 */
constexpr std::uint8_t operator"" _uint8(const unsigned long long v) {
  return static_cast<std::uint8_t>(v);
}

/**
 * \brief Makes an unsigned integer on 16 bits
 * \param v Unsigned integer
 * \return 16 bit unsigned integer of requested value
 */
constexpr std::uint16_t operator"" _uint16(const unsigned long long v) {
  return static_cast<std::uint16_t>(v);
}

/**
 * \brief Makes an unsigned integer on 32 bits
 * \param v Unsigned integer
 * \return 32 bit unsigned integer of requested value
 */
constexpr std::uint32_t operator"" _uint32(const unsigned long long v) {
  return static_cast<std::uint32_t>(v);
}

/**
 * \brief Makes an unsigned integer on 64 bits
 * \param v Unsigned integer
 * \return 64 bit unsigned integer of requested value
 */
constexpr std::uint64_t operator"" _uint64(const unsigned long long v) {
  return static_cast<std::uint64_t>(v);
}
}  // namespace WebBinaryCompression
#endif
