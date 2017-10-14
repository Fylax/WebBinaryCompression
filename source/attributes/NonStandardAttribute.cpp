/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include <deque>
#include "Constants.hpp"
#include "attributes/NonStandardAttribute.hpp"

namespace WebBinaryCompression::Attributes {

std::uint8_t NonStandard::Type() const { return kNonStandard; }

NonStandard::NonStandard(const std::string_view& text): Attribute(kNonStandard),
                                                        text_(text) { }

NonStandard::~NonStandard() { }

void NonStandard::EmitEquivalent(std::deque<std::uint8_t>* output_stream) {
  output_stream->push_back(Type());
  output_stream->insert(output_stream->end(), text_.begin(), text_.end());
  output_stream->push_back(kEnd);
  value_->EmitEquivalent(output_stream);
}
}  // namespace WebBinaryCompression::Attributes
