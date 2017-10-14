/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include <deque>
#include "Constants.hpp"
#include "attributes/types/TextAttribute.hpp"

namespace WebBinaryCompression::Attributes::Types {
std::uint8_t Text::Type() const { return kText; }

Text::Text(const std::string_view& text): AttributeValue(
                                            static_cast<std::uint8_t>(kText)),
                                          text_(text) { }

Text::~Text() { }

void Text::EmitEquivalent(std::deque<std::uint8_t>* output_stream) {
  output_stream->push_back(Type());
  output_stream->insert(output_stream->end(), text_.begin(), text_.end());
  output_stream->push_back(kEnd);
}
}  // namespace WebBinaryCompression::Attributes::Types
