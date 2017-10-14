/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include <memory>
#include "Utils.hpp"
#include "NumericLiterals.hpp"
#include "attributes/integers/Integer.hpp"
#include "attributes/types/BasicInteger.hpp"

namespace WebBinaryCompression::Attributes::Types {

const std::uint8_t Integer::kDeBruijn[] = {
  8, 1, 8, 1, 8, 6, 7, 1,
  8, 5, 6, 4, 7, 5, 6, 1,
  8, 7, 5, 5, 7, 3, 4, 3,
  7, 4, 5, 2, 6, 2, 3, 1,
  8, 8, 6, 7, 5, 4, 4, 6,
  7, 5, 3, 3, 4, 2, 2, 3,
  7, 6, 4, 4, 5, 2, 2, 2,
  6, 3, 2, 1, 3, 1, 1, 1
};

std::size_t Integer::ByteSize(std::uint64_t value) {
  value |= value >> 1;
  value |= value >> 2;
  value |= value >> 4;
  value |= value >> 8;
  value |= value >> 16;
  value |= value >> 32;
  return kDeBruijn[static_cast<std::uint64_t>((value - (value >> 1)) *
    0x07EDD5E59A4E28C2_uint64) >> 58];
}

Integer::Integer(const std::uint8_t equivalent): AttributeValue(equivalent) { }

Integer::Integer(const std::uint16_t equivalent): AttributeValue(equivalent) { }

Integer::Integer(const std::uint8_t bytes_required,
                 const std::uint_fast64_t equivalent):
  AttributeValue(bytes_required, equivalent) { }

std::shared_ptr<Integer> Integer::Parse(const std::string_view text) {
  using namespace std::string_view_literals;
  const bool is_negative = text[0] == '-';
  const bool has_sign = text[0] == '+' || is_negative;
  const auto number = StringViewToInt(text.substr(has_sign));
  const std::size_t size = ByteSize(number) + 8 * (has_sign && is_negative);
  switch (size) {
    case 1: return std::make_shared<Integers::Integer<kPositiveInteger8>>(
        static_cast<std::uint8_t>(number));
    case 2: return std::make_shared<Integers::Integer<kPositiveInteger16>>(
        static_cast<std::uint16_t>(number));
    case 3: return std::make_shared<Integers::Integer<kPositiveInteger24>>(
        static_cast<std::uint32_t>(number));
    case 4: return std::make_shared<Integers::Integer<kPositiveInteger32>>(
        static_cast<std::uint32_t>(number));
    case 5: return std::make_shared<Integers::Integer<kPositiveInteger40>>(
        static_cast<std::uint64_t>(number));
    case 6: return std::make_shared<Integers::Integer<kPositiveInteger48>>(
        static_cast<std::uint64_t>(number));
    case 7: return std::make_shared<Integers::Integer<kPositiveInteger56>>(
        static_cast<std::uint64_t>(number));
    case 8: return std::make_shared<Integers::Integer<kPositiveInteger64>>(
        static_cast<std::uint64_t>(number));
    case 9: return std::make_shared<Integers::Integer<kNegativeInteger8>>(
        static_cast<std::uint8_t>(number));
    case 10: return std::make_shared<Integers::Integer<kNegativeInteger16>>(
        static_cast<std::uint16_t>(number));
    case 11: return std::make_shared<Integers::Integer<kNegativeInteger24>>(
        static_cast<std::uint32_t>(number));
    case 12: return std::make_shared<Integers::Integer<kNegativeInteger32>>(
        static_cast<std::uint32_t>(number));
    case 13: return std::make_shared<Integers::Integer<kNegativeInteger40>>(
        static_cast<std::uint64_t>(number));
    case 14: return std::make_shared<Integers::Integer<kNegativeInteger48>>(
        static_cast<std::uint64_t>(number));
    case 15: return std::make_shared<Integers::Integer<kNegativeInteger56>>(
        static_cast<std::uint64_t>(number));
    case 16: return std::make_shared<Integers::Integer<kNegativeInteger64>>(
        static_cast<std::uint64_t>(number));
    default: return nullptr;
  }
}

Integer::~Integer() { }
}  // namespace WebBinaryCompression::Attributes::Types
