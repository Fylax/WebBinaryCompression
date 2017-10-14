/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include <deque>
#include <memory>
#include <queue>
#include "Constants.hpp"
#include "attributes/types/List.hpp"

namespace WebBinaryCompression::Attributes::Types {
std::uint8_t List::Type() const { return kList; }

List::List(const char separator): AttributeValue(static_cast<std::uint8_t>(
                                    kList)), separator_(separator) { }

List::~List() {
  auto empty = std::queue<std::shared_ptr<AttributeValue>>();
  values_.swap(empty);
}

void List::Add(const std::shared_ptr<AttributeValue> value) {
  values_.push(value);
}

void List::EmitEquivalent(std::deque<std::uint8_t>* output_stream) {
  output_stream->push_back(Type());
  output_stream->push_back(static_cast<std::uint8_t>(separator_));
  while (!values_.empty()) {
    std::shared_ptr<AttributeValue> value = values_.front();
    value->EmitEquivalent(output_stream);
    value.reset();
    values_.pop();
  }
  output_stream->push_back(kEnd);
}

char List::Separator() const { return separator_; }

bool List::SingleElement() const { return values_.size() == 1; }

std::shared_ptr<AttributeValue> List::Pop() {
  std::shared_ptr<AttributeValue> value = values_.front();
  values_.pop();
  return value;
}
}  // namespace WebBinaryCompression::Attributes::Types
