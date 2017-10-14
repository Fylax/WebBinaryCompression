/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include "Constants.hpp"
#include "attributes/types/Charset.hpp"

namespace WebBinaryCompression::Attributes::Types {
std::uint8_t Charset::Type() const {
  return kCharset;
}

Charset::Charset(const std::uint8_t equivalent):
  AttributeValue(equivalent) {}

Charset::Charset(const std::uint16_t equivalent):
  AttributeValue(equivalent) {}

Charset::~Charset() { }
}  // namespace WebBinaryCompression::Attributes::Types
