/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include <locale>
#include <memory>
#include "Constants.hpp"
#include "NumericLiterals.hpp"
#include "Utils.hpp"
#include "attributes/dates/Dates.hpp"
#include "attributes/types/BasicDate.hpp"

namespace WebBinaryCompression::Attributes::Types {

bool Date::CheckDate(const unsigned month, const unsigned day,
                     const bool is_leap) {
  switch (month) {
    case 1: return day <= 31;
    case 2: return day <= 28 || (is_leap && day == 29);
    case 3: return day <= 31;
    case 4: return day <= 30;
    case 5: return day <= 31;
    case 6: return day <= 30;
    case 7: return day <= 31;
    case 8: return day <= 31;
    case 9: return day <= 30;
    case 10: return day <= 31;
    case 11: return day <= 30;
    case 12: return day <= 31;
    default: return false;
  }
}

unsigned Date::MonthToDays(const unsigned current_month, const bool is_leap) {
  unsigned result = 0;
  switch (current_month - 1) {
    case 11: result += 30;
    case 10: result += 31;
    case 9: result += 30;
    case 8: result += 31;
    case 7: result += 31;
    case 6: result += 30;
    case 5: result += 31;
    case 4: result += 30;
    case 3: result += 31;
    case 2: result += !is_leap * 28 + is_leap * 29;
    case 1: result += 31;
    default: break;
  }
  return result;
}

std::shared_ptr<Date> Date::ParseYearless(const std::string_view& text) {
  const bool invalid = !std::isdigit(text[3], locale) &&
      !std::isdigit(text[4], locale);

  const unsigned month = static_cast<unsigned>(StringViewToInt(text.substr(
    0, 2)));
  const unsigned day = static_cast<unsigned>(StringViewToInt(text.substr(
    3, 2)));
  const unsigned result = MonthToDays(month, true) + day;
  // YearlessDates are always considered as a leap year
  if (invalid || result > 366 || !CheckDate(month, day, true)) {
    return std::shared_ptr<Date>(nullptr);
  }
  return std::make_shared<Dates::Dates<kDateYearless>>(
    static_cast<std::uint16_t>(result));
}

std::shared_ptr<Date> Date::ParseWeek(const std::string_view& text) {
  using namespace std::string_view_literals;
  const size_t length = text.length();
  bool invalid = length < 8;

  unsigned i;
  for (i = 4; invalid && i < length - 4; ++i) {
    invalid = invalid || !std::isdigit(text[i], locale);
  }
  invalid = invalid || text.substr(i, 2) != "-W"sv ||
      !std::isdigit(text[i + 2], locale) || !std::isdigit(text[i + 3], locale);

  const unsigned year = static_cast<unsigned>(StringViewToInt(text.substr(
    0, i)));
  const unsigned week = static_cast<unsigned>(StringViewToInt(text.substr(
    i + 2, 2)));

  const uint32_t returns = (year << 8) | week;
  if (invalid || year > 65536 || week > 53) {
    return std::shared_ptr<Date>(nullptr);
  }
  return std::make_shared<Dates::Dates<kWeek>>(
    static_cast<std::uint32_t>(returns));
}

std::shared_ptr<Date> Date::ParseDate(const std::string_view& text) {
  const size_t length = text.length();
  bool invalid = length < 10;

  unsigned i = 4;
  while (invalid && i < length - 6 && !std::isdigit(text[i], locale)) {
    i += 1;
  }

  invalid = invalid || text[i] != '-' || !std::isdigit(text[i + 1], locale) ||
      !std::isdigit(text[i + 2], locale) || text[i + 3] != '-' ||
      !std::isdigit(text[i + 4], locale) || !std::isdigit(text[i + 5], locale);

  const unsigned year = static_cast<unsigned>(StringViewToInt(text.substr(
    0, i)));
  const unsigned month = static_cast<unsigned>(StringViewToInt(text.substr(
    i + 1, 2)));
  const unsigned day = static_cast<unsigned>(StringViewToInt(text.substr(
    i + 4, 2)));

  const bool is_leap = year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);

  const unsigned result = year * 365 +  // days (without leap years) up to now
      year / 4 - year / 100 + year / 400 +  // count of missing leap days
      MonthToDays(month, is_leap) + day;

  if (invalid || year > 45933 || month > 12 || day > 31 ||
    !CheckDate(month, day, is_leap) || result > 16777216) {
    return std::shared_ptr<Date>(nullptr);
  }

  if (length > i + 6 && (text[i + 6] == 'T' || text[i + 6] == ' ')) {
    return ParseTime(text.substr(i + 7), result);
  }
  return std::make_shared<Dates::Dates<kDateNoTime>>(
    static_cast<std::uint32_t>(result));
}

std::shared_ptr<Date> Date::ParseTime(const std::string_view& text) {
  return ParseTime(text, -1);
}

std::shared_ptr<Date> Date::ParseTime(const std::string_view& text,
                                      const std::int32_t date) {
  const size_t length = text.length();

  bool invalid = length < 5 ||
      length == 6 || length == 7 || length == 9;

  const unsigned hour = static_cast<unsigned>(StringViewToInt(text.substr(
    0, 2)));
  const unsigned minutes = static_cast<unsigned>(StringViewToInt(text.substr(
    3, 2)));

  invalid = invalid ||
      text[2] != ':' ||  // separator
      // minutes
      !std::isdigit(text[3], locale) || !std::isdigit(text[4], locale) ||
      hour > 23 || minutes > 59;

  const bool has_seconds = length >= 8 && text[5] == ':' &&  // spearator
      // check seconds
      std::isdigit(text[6], locale) && std::isdigit(text[7], locale);
  const unsigned seconds = static_cast<unsigned>(StringViewToInt(text.substr(
    6 * has_seconds, 2)));

  invalid = invalid || (has_seconds && seconds > 59);

  unsigned result = (hour * 60 + minutes) * 60000 +  // millisecond aligned
      (has_seconds * !invalid * seconds) * 1000;
  // if invalid (may be HH:MMZ), seconds do no influence the final result

  const bool has_decimals = has_seconds && length >= 10 && text[8] == '.' &&
      std::isdigit(text[9], locale);

  unsigned fractionals = has_decimals * std::isdigit(text[9 * has_decimals],
                                                     locale);  // first decimal
  fractionals += fractionals == 1 &&
      length >= 11 && std::isdigit(text[10], locale);  // second decimal
  fractionals += fractionals == 2 &&
      length >= 12 && std::isdigit(text[11], locale);  // third decimal

  switch (fractionals) {
    case 3: result += static_cast<unsigned>(StringViewToInt(text.substr(
        11, 1)));
    case 2: result += static_cast<unsigned>(StringViewToInt(text.substr(
        10, 1))) * 10;
    case 1: result += static_cast<unsigned>(StringViewToInt(text.substr(
        9, 1))) * 100;
      break;
    default: invalid = invalid || has_decimals;
  }

  invalid = invalid || (result > 86400000);

  const unsigned offset = 5 + (3 * has_seconds) +
      ((fractionals + 1) * has_decimals);

  if (length > offset &&
    (text[offset] == 'Z' || text[offset] == '+' || text[offset] == '-')) {
    return ParseTimezone(text.substr(offset), date, result);
  }

  if (invalid || length > offset) { return std::shared_ptr<Date>(nullptr); }

  if (date != -1) {
    return std::make_shared<Dates::Dates<kDateTime>>((
      static_cast<std::uint64_t>(date) << 32) | result);
  }
  return std::make_shared<Dates::Dates<kTime>>(
    static_cast<std::uint32_t>(result));
}

std::shared_ptr<Date> Date::ParseTimezone(const std::string_view& text,
                                          const int32_t date,
                                          const uint32_t time) {
  if (text[0] == 'Z') {
    if (date != -1) {
      return std::make_shared<Dates::Dates<kDateTimeAndUtc>>(
        (static_cast<std::uint64_t>(date) << 40) | (0b11_uint64 << 38) | time);
    }
    return std::make_shared<Dates::Dates<kTimeUtc>>((0b11 << 30) | time);
  }

  const std::size_t length = text.length();
  const bool is_negative = text[0] == '-';
  bool invalid = length < 3 || (text[0] != '+' && !is_negative) ||
      !std::isdigit(text[1], locale) || !std::isdigit(text[2], locale);

  const bool has_minutes = length == 6 && text[3] == ':' &&
      std::isdigit(text[4], locale) && std::isdigit(text[5], locale);

  const int hour = static_cast<unsigned>(StringViewToInt(text.substr(1, 2)));
  const unsigned minutes = has_minutes *
      static_cast<unsigned>(StringViewToInt(text.substr(has_minutes * 4, 2)));

  invalid = invalid || (!has_minutes && length != 3) || hour > 23 ||
    minutes > 59;

  if (invalid) { return std::shared_ptr<Date>(nullptr); }

  const unsigned flag = 0b10 * !is_negative + 0b01 * is_negative;
  const unsigned timezone = (flag << 14) | (hour * 60 + minutes);

  if (date != -1) {
    return std::make_shared<Dates::Dates<kDateTimeAndTimezone>>((
        static_cast<std::uint64_t>(date) << 40) |
      (static_cast<std::uint64_t>(timezone) << 24) | time);
  }
  return std::make_shared<Dates::Dates<kTimeAndTimeZone>>(
    static_cast<std::uint64_t>(timezone) << 24 | time);
}

Date::Date(const std::uint8_t equivalent):
  AttributeValue(equivalent) { }

Date::Date(const std::uint16_t equivalent):
  AttributeValue(equivalent) {}

Date::Date(const std::uint8_t bytes_required,
           const std::uint64_t equivalent):
  AttributeValue(bytes_required, equivalent) {}

std::shared_ptr<Date> Date::ParseMonth(const std::string_view& text) {
  using namespace std::string_view_literals;

  const unsigned year = static_cast<unsigned>(StringViewToInt(text.substr(
    0, 4)));
  const unsigned month = static_cast<unsigned>(StringViewToInt(text.substr(
    6, 2)));

  const unsigned result = (year - 1) * 12 + month - 1;

  if (result > 65535) { return std::shared_ptr<Date>(nullptr); }
  return std::make_shared<Dates::Dates<kDateMonthOnly>>(
    static_cast<std::uint16_t>(result));
}

std::shared_ptr<Date> Date::Parse(const std::string_view& text) {
  using namespace std::string_view_literals;
  const std::size_t length = text.length();
  unsigned type = text.substr(0, 2) == "--"sv;  // yearless = 1
  type += (type == 0 && std::isdigit(text[0], locale) &&
    std::isdigit(text[1], locale)) * 2;  // time = 2
  type += (type == 2 && text[2] == '-');  // yearless (no initial --) = 3
  type += (type == 2 && std::isdigit(text[2], locale) &&
    std::isdigit(text[3], locale)) * 2;  // date = 4
  type += (type == 4 &&
    text.find_first_of("-W"sv) != std::string_view::npos);  // week = 5
  type += (type == 4 && text[4] == '-' && std::isdigit(text[5], locale)
    && std::isdigit(text[6], locale) && length == 7) * 2;  // month only = 6
  switch (type) {
    case 1: return ParseYearless(text.substr(2));
    case 2: return ParseTime(text);
    case 3: return ParseYearless(text);
    case 4: return ParseDate(text);
    case 5: return ParseWeek(text);
    case 6: return ParseMonth(text);
    default: return std::shared_ptr<Date>(nullptr);
  }
}

Date::~Date() { }
}  // namespace WebBinaryCompression::Attributes::Types
