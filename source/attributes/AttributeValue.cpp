/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include "attributes/AttributeValue.hpp"

namespace WebBinaryCompression::Attributes {
AttributeValue::AttributeValue(const std::uint8_t equivalent):
  Serializable(equivalent) { }

AttributeValue::AttributeValue(const std::uint16_t equivalent):
  Serializable(equivalent) { }

AttributeValue::~AttributeValue() { }

AttributeValue::AttributeValue(const std::uint8_t bytes_required,
                               const std::uint64_t equivalent) :
  Serializable(bytes_required, equivalent) { }
}  // namespace WebBinaryCompression::Attributes
