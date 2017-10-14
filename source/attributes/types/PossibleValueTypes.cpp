/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include <memory>
#include "Constants.hpp"
#include "attributes/types/BasicDate.hpp"
#include "attributes/types/Charset.hpp"
#include "attributes/types/Enumerable.hpp"
#include "attributes/types/LinkType.hpp"
#include "attributes/types/MimeType.hpp"
#include "attributes/types/MimeTypeSuperset.hpp"
#include "attributes/types/PossibleValueTypes.hpp"

namespace WebBinaryCompression::Attributes::Types {

PossibleValueTypes::PossibleValueTypes(const std::bitset<8> bitmap) :
  bitmap_(bitmap) {}

std::unique_ptr<PossibleValueTypes> PossibleValueTypes::CheckTypes(
  const std::string_view& value,
  const std::string_view& attribute_name) {
  using namespace std::string_view_literals;
  const size_t value_length = value.length();
  bool possibly_boolean = value_length == attribute_name.length();
  bool possibly_charset = value_length - Charset::kShortest <=
      Charset::kLongest - Charset::kShortest;
  bool possibly_date = value_length - Date::kShortest <=
      Date::kLongest - Date::kShortest;
  bool possibly_linktype = value_length - LinkType::kShortest <=
      LinkType::kLongest - LinkType::kShortest;
  bool possibly_mimetype = value_length - MimeType::kShortest <=
      MimeType::kLongest - LinkType::kShortest;
  bool possibly_mimetype_superset = value_length - MimeTypeSuperset::kShortest
      <= MimeTypeSuperset::kLongest - MimeTypeSuperset::kShortest &&
      value.substr(value_length - 2) == "/*"sv;
  bool possibly_enumerable = value_length - Enumerable::kShortest <=
      Enumerable::kLongest - Enumerable::kShortest;
  bool possibly_int = true;

  for (unsigned i = 0; i < value_length && (possibly_boolean || possibly_charset
         || possibly_date || possibly_linktype || possibly_mimetype ||
         possibly_mimetype_superset || possibly_int); ++i) {
    const char cur_char = value[i];
    const bool is_digit = std::isdigit(cur_char, locale);
    const bool is_alpha = std::isalpha(cur_char, locale);
    possibly_boolean = possibly_boolean && is_alpha &&
        cur_char == attribute_name[i];
    possibly_charset = possibly_charset && (is_alpha || is_digit ||
      cur_char == '-' || cur_char == '_' || cur_char == '.' || cur_char == ':');
    possibly_int = possibly_int && (is_digit || (i == 0 &&
      (cur_char == '+' || cur_char == '-')));
    possibly_date = possibly_date && (is_digit || cur_char == '+' ||
      cur_char == '-' || cur_char == ' ' || cur_char == '.' || cur_char == ':'
      || cur_char == 'T' || cur_char == 'Z' || cur_char == 'W');
    possibly_enumerable = possibly_enumerable && (is_alpha || is_digit ||
      cur_char == '-' || cur_char == '_');
    possibly_linktype = possibly_linktype && (is_alpha || cur_char == '-');
    possibly_mimetype = possibly_mimetype && (is_alpha || is_digit ||
      cur_char == '+' || cur_char == '-' || cur_char == '/' || cur_char == '.');
    possibly_mimetype_superset = possibly_mimetype_superset && (is_alpha ||
      cur_char == '/' || cur_char == '*');
  }

  const unsigned integer = !possibly_boolean && possibly_int;
  const bool any_other = !possibly_boolean && !possibly_int;
  const unsigned charset = any_other && possibly_charset;
  const unsigned date = any_other && possibly_date;
  const unsigned linktype = any_other && possibly_linktype;
  const unsigned mimetype = any_other && possibly_mimetype;
  const unsigned mimetype_superset = any_other && possibly_mimetype_superset;
  const unsigned enumerable = any_other && possibly_enumerable;

  const unsigned long bitmap = ((((((((((((((
                  integer << 1) |
                enumerable) << 1) |
              mimetype_superset) << 1) |
            mimetype) << 1) |
          linktype) << 1) |
        date) << 1) |
      charset) << 1) |
    static_cast<unsigned>(possibly_boolean));

  return std::unique_ptr<PossibleValueTypes>(new PossibleValueTypes(bitmap));
}

PossibleValueTypes::~PossibleValueTypes() { }

bool PossibleValueTypes::Boolean() const { return bitmap_[0]; }

bool PossibleValueTypes::Charset() const { return bitmap_[1]; }

bool PossibleValueTypes::Date() const { return bitmap_[2]; }

bool PossibleValueTypes::LinkType() const { return bitmap_[3]; }

bool PossibleValueTypes::MimeType() const { return bitmap_[4]; }

bool PossibleValueTypes::MimeTypeSuperset() const { return bitmap_[5]; }

bool PossibleValueTypes::Enumerable() const { return bitmap_[6]; }

bool PossibleValueTypes::Integer() const { return bitmap_[7]; }

}  // namespace WebBinaryCompression::Attributes::Types
