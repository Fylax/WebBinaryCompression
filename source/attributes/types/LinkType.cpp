/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include "Constants.hpp"
#include "attributes/types/LinkType.hpp"

namespace WebBinaryCompression::Attributes::Types {
std::uint8_t LinkType::Type() const {
  return kLinkType;
}

LinkType::LinkType(const std::uint8_t equivalent):
  AttributeValue(equivalent) { }

LinkType::~LinkType() {}
}  // namespace WebBinaryCompression::Attributes::Types
