/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include <deque>
#include <locale>
#include <memory>
#include <utility>
#include "Attribute.hpp"
#include "Constants.hpp"
#include "attributes/Attributes.hpp"
#include "attributes/NonStandardAttribute.hpp"
#include "attributes/types/BasicDate.hpp"
#include "attributes/types/BasicInteger.hpp"
#include "attributes/types/Boolean.hpp"
#include "attributes/types/List.hpp"
#include "attributes/types/PossibleValueTypes.hpp"
#include "attributes/types/TextAttribute.hpp"
#include "attributes/values/Charsets.hpp"
#include "attributes/values/Enumerables.hpp"
#include "attributes/values/LinkTypes.hpp"
#include "attributes/values/MimeTypes.hpp"
#include "attributes/values/MimeTypeSupersets.hpp"

namespace WebBinaryCompression::Attributes {

std::uint8_t Attribute::Type() const { return kAttribute; }

Attribute::Attribute(const std::uint8_t equivalent):
  Serializable(equivalent) { }

Attribute::~Attribute() { value_.reset(); }

std::unique_ptr<Attribute> Attribute::Parse(std::string_view* string) {
  using namespace std::string_view_literals;
  std::size_t attribute_name_length = 0;
  std::string_view& text = *string;
  while (std::isalpha(text[attribute_name_length], locale)) {
    ++attribute_name_length;
  }

  const auto iterator = Attributes::elements.find(text.substr(
    0, attribute_name_length));
  std::unique_ptr<Attribute> element;
  if (iterator == Attributes::elements.end()) {
    element = std::make_unique<NonStandard>(text.substr(0,
                                                        attribute_name_length));
  } else { element = std::make_unique<Attribute>(*iterator->second.get()); }

  const std::string_view attribute_name = text.substr(0, attribute_name_length);

  std::size_t gap = attribute_name_length;
  while (std::isspace(text[gap], locale)) { ++gap; }

  const bool boolean = text[gap] != '=';
  gap += !boolean;

  while (!boolean && std::isspace(text[gap], locale)) { ++gap; }

  const bool delimited = !boolean && (text[gap] == '"' || text[gap] == '\'');
  const char terminator = text[gap];

  gap += delimited;

  text = text.substr(gap);
  const std::size_t length = text.length();
  std::size_t attribute_value_length = 0;
  while (!boolean &&
    ((delimited && text[attribute_value_length] != terminator) ||
      (!delimited && (text[attribute_value_length] != ' ' &&
        text[attribute_value_length] != '>' &&
        (attribute_value_length + 1 < length &&
          text.substr(attribute_value_length, 2) != "/>"sv))))) {
    ++attribute_value_length;
  }

  const std::string_view attribute_value = text.substr(0,
                                                       attribute_value_length);
  auto allowed_types = Types::PossibleValueTypes::CheckTypes(attribute_value,
                                                             attribute_name);

  if (allowed_types->Boolean() || attribute_value.length() == 0 ||
    attribute_name == attribute_value) {
    element->value_ = std::make_shared<Types::Boolean>();
    return element;
  }

  bool completed = false;
  auto current_value = attribute_value;
  std::size_t current_value_start = 0;
  auto current_value_length = attribute_value_length;
  std::unique_ptr<Types::List> list = nullptr;
  do {
    std::shared_ptr<AttributeValue> value = nullptr;
    if (delimited) {
      const std::size_t separator_position =
          (!list)
            ? attribute_value.find_first_of(", "sv, current_value_start)
            : attribute_value.find_first_of(list->Separator(),
                                            current_value_start);
      if (separator_position != std::string_view::npos) {
        if (!list) {
          list = std::make_unique<Types::List>(
            attribute_value[separator_position]);
        }
        current_value_length = separator_position - current_value_start;
        current_value = attribute_value.substr(current_value_start,
                                               current_value_length);
        current_value_start = separator_position + 1;
        allowed_types = Types::PossibleValueTypes::CheckTypes(current_value,
                                                              attribute_name);
      } else {
        if (list) {
          if (!list->SingleElement()) {
            element->value_ = std::move(list);
            completed = true;
          } else {
            element->value_ = list->Pop();
            completed = true;
          }
        }
      }
    }
    if (!completed && allowed_types->Charset()) {
      const auto temp_value = Values::Charsets::elements.find(current_value);
      if (temp_value != Values::Charsets::elements.end()) {
        value = temp_value->second;
      }
    }
    if (!value && !completed && allowed_types->Enumerable()) {
      const auto temp_value = Values::Enumerables::elements.find(current_value);
      if (temp_value != Values::Enumerables::elements.end()) {
        value = temp_value->second;
      }
    }
    if (!value && !completed && allowed_types->MimeTypeSuperset()) {
      const auto temp_value = Values::MimeTypeSupersets::elements.
          find(current_value.substr(0, current_value_length - 2));
      if (temp_value != Values::MimeTypeSupersets::elements.end()) {
        value = temp_value->second;
      }
    }
    if (!value && !completed && allowed_types->MimeType()) {
      const auto temp_value = Values::MimeTypes::elements.find(current_value);
      if (temp_value != Values::MimeTypes::elements.end()) {
        value = temp_value->second;
      }
    }
    if (!value && !completed && allowed_types->LinkType()) {
      const auto temp_value = Values::LinkTypes::elements.find(current_value);
      if (temp_value != Values::LinkTypes::elements.end()) {
        value = temp_value->second;
      }
    }
    if (!value && !completed && allowed_types->Integer()) {
      value = Types::Integer::Parse(current_value);
    }
    if (!value && !completed && allowed_types->Date()) {
      if (delimited && list && text[current_value_start - 2] != ' ') {
        const std::size_t separator_position =
            attribute_value.find_first_of(" "sv, current_value_start);
        const std::size_t end = (separator_position != std::string_view::npos)
            * separator_position + (separator_position ==
                                    std::string_view::npos) *
            attribute_value.length();
        const std::string_view temp_value = attribute_value.
            substr(current_value_start - current_value_length - 1, end);;
        value = Types::Date::Parse(temp_value);
        if (value) {
          current_value_length = temp_value.length();
          current_value = temp_value;
          current_value_start = end;
        }
      } else { value = Types::Date::Parse(current_value); }
    }
    if (!value && !completed) {
      value = std::make_shared<Types::Text>(current_value);
    }
    if (list) {
      list->Add(value);
    } else if (!completed) {
      element->value_ = value;
      completed = true;
    }
  } while (!completed);
  text = text.substr(attribute_value_length + delimited);
  string = &text;
  return element;
}

void Attribute::EmitEquivalent(std::deque<std::uint8_t>* output_stream) {
  Serializable::EmitEquivalent(output_stream);
  value_->EmitEquivalent(output_stream);
}

}  // namespace WebBinaryCompression::Attributes
