/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include "Constants.hpp"
#include "attributes/types/Enumerable.hpp"

namespace WebBinaryCompression::Attributes::Types {
std::uint8_t Enumerable::Type() const {
  return kEnumerable;
}

Enumerable::Enumerable(const std::uint8_t equivalent) :
  AttributeValue(equivalent) { }

Enumerable::Enumerable(const std::uint16_t equivalent):
  AttributeValue(equivalent) { }

Enumerable::~Enumerable() { }
}  // namespace WebBinaryCompression::Attributes::Types
