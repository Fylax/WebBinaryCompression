/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEBBINARYCOMPRESSION_INCLUDE_CONSTANTS_H_
#define WEBBINARYCOMPRESSION_INCLUDE_CONSTANTS_H_
#include <locale>

namespace WebBinaryCompression {
#ifdef _MSC_VER
  /**
   * \brief Global locale.
   */
  const std::locale locale = std::locale();
#else
  /**
   * \brief UTF-8 locale.
   */
  const std::locale locale = std::locale("en_US.UTF-8");
#endif

/**
 * \brief Contains all special values equivalent.
 * 
 * Special values are all those values that doesn't represent an HTML object
 * but a concept or an helper.
 */
enum SpecialValues: std::uint8_t {
  kEnd,
  kEscape,
  kText,
  kNonStandard,
  kAttribute,
  kEvent,
  kAria
};

/**
 * \brief Equivalent of all possible aria types.
 */
enum AriaTypes : std::uint8_t {
  kRole = 0x06,
  kTextRole,
  kProperty,
  kTextProperty
};

/**
 * \brief Equivalent of all possible attribute value types.
 */
enum AttributeTypes: std::uint8_t {
  kBoolean = 0x06,
  kCharset,
  kDateMonthOnly,
  kDateNoTime,
  kWeek,
  kDateYearless,
  kTime,
  kTimeUtc,
  kTimeAndTimeZone,
  kDateTime,
  kDateTimeAndUtc,
  kDateTimeAndTimezone,
  kEnumerable,
  kLinkType,
  kMimeType,
  kMimeTypeSuperset,
  kList,
  kPositiveInteger8,
  kPositiveInteger16,
  kPositiveInteger24,
  kPositiveInteger32,
  kPositiveInteger40,
  kPositiveInteger48,
  kPositiveInteger56,
  kPositiveInteger64,
  kNegativeInteger8,
  kNegativeInteger16,
  kNegativeInteger24,
  kNegativeInteger32,
  kNegativeInteger40,
  kNegativeInteger48,
  kNegativeInteger56,
  kNegativeInteger64
};
}  // namespace WebBinaryCompression
#endif
