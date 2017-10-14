/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include <deque>
#include "Constants.hpp"
#include "NumericLiterals.hpp"
#include "attributes/types/Boolean.hpp"

namespace WebBinaryCompression::Attributes::Types {
std::uint8_t Boolean::Type() const { return kBoolean; }

Boolean::Boolean(): AttributeValue(0_uint8) { }

Boolean::~Boolean() { }

void Boolean::EmitEquivalent(std::deque<std::uint8_t>* output_stream) {
  output_stream->push_back(Type());
}
}  // namespace WebBinaryCompression::Attributes::Types
