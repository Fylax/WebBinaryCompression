/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include <algorithm>
#include <utility>
#include "Endianess.hpp"

namespace WebBinaryCompression {

Endianess& Endianess::Instance() {
  static Endianess instance{};
  return instance;
}

Endianess::Endianess() {
  uint32_t endian = 0x1;
  if (*reinterpret_cast<uint8_t *>(&endian) == 0x00)
    this->type_ = kBigEndian;
  else
    this->type_ = kLittleEndian;
}

uint16_t Endianess::ConvertToLittleEndian(const std::uint16_t
  number_to_convert) {
  Endianess& instance = Instance();
  std::uint16_t temp_number = number_to_convert;
  if (instance.type_ == kBigEndian) {
    uint8_t (&number)[2] = *reinterpret_cast<uint8_t(*)[2]>(&temp_number);
    std::swap(number[0], number[1]);
  }
  return temp_number;
}

std::uint32_t Endianess::ConvertToLittleEndian(const std::uint32_t
  number_to_convert) {
  Endianess& instance = Instance();
  std::uint16_t temp_number = number_to_convert;
  if (instance.type_ == kBigEndian) {
    uint8_t (&number)[4] = *reinterpret_cast<uint8_t(*)[4]>(&temp_number);
    std::swap(number[0], number[3]);
    std::swap(number[1], number[2]);
  }
  return temp_number;
}

std::uint64_t Endianess::ConvertToLittleEndian(const unsigned number_of_bytes,
                                               const std::uint64_t
                                               number_to_convert) {
  Endianess& instance = Instance();
  std::uint64_t temp_number = number_to_convert;
  if (instance.type_ == kBigEndian) {
    uint8_t* number = reinterpret_cast<uint8_t*>(&temp_number);
    for (unsigned i = 0, j = number_of_bytes; i < number_of_bytes / 2; i++) {
      std::swap(number[i], number[j]);
    }
  }
  return temp_number;
}
}  // namespace WebBinaryCompression
