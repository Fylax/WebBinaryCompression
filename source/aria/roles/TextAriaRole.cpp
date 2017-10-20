/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include <deque>
#include "Constants.hpp"
#include "aria/roles/TextAriaRole.hpp"

namespace WebBinaryCompression::Aria {

std::uint8_t Text::Type() const { return kTextRole; }

Text::Text(const std::string_view& text): Role(kTextRole), text_(text) { }

Text::~Text() { }

void Text::EmitEquivalent(std::deque<std::uint8_t>* output_stream) {
  output_stream->push_back(Type());
  output_stream->insert(output_stream->end(), text_.begin(), text_.end());
  output_stream->push_back(kEnd);
}
}  // namespace WebBinaryCompression::Aria
