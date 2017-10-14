/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include "Constants.hpp"
#include "attributes/types/MimeType.hpp"

namespace WebBinaryCompression::Attributes::Types {

std::uint8_t MimeType::Type() const {
  return kMimeType;
}

MimeType::MimeType(const std::uint16_t equivalent):
  AttributeValue(equivalent) { }

MimeType::~MimeType() { }
}  // namespace WebBinaryCompression::Attributes::Types
