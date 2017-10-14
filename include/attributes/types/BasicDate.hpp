/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_BASIC_DATE_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_BASIC_DATE_H
#include <memory>
#include "attributes/AttributeValue.hpp"

namespace WebBinaryCompression::Attributes::Types {

/**
 * \brief Parses a date and return correct object in case of success.
 */
class Date: public AttributeValue {
 private:
   /**
   * \brief Checks whether a date is valid.
   * 
   * This method has an internal table through which compares the current day
   * with maximum number of days for current month. If the day's argument
   * is less or equale than the days a month can have, the outcome will be
   * positive.
   * 
   * Examples:
   * \code
   * CheckDate(02, 29, false) -> false
   * \endcode
   * 
   * \code
   * CheckDate(02, 29, true) -> true
   * \endcode
   * \param month Current month, in range \f$ [1, 12] \f$
   * \param day Current day.
   * \param is_leap Whether the current year is leap or not.
   * \return True if the current day is less or equal to the number of days
   * that a month can have.
   */
  static bool CheckDate(unsigned month, unsigned day, bool is_leap);

  /**
   * \brief Computes the number of day which occurred from the beginning of the
   * year to the beginning of the current month.
   * 
   * Examples:
   * \code
   * MonthToDays(2, false) -> 31
   * \endcode
   * 
   * \code
   * MonthToDays(3, true) -> 31 + 29 = 60
   * \endcode
   * \param current_month Current month, in range \f$ [1, 12] \f$
   * \param is_leap Whether the current year is leap or not.
   * \return Number of days occurrend since the beginning of the year up to
   * the beginning of the current month.
   */
  static unsigned MonthToDays(unsigned current_month, bool is_leap);

  /**
   * \brief Parses a Yearless %Date.
   * 
   * Every date in format <tt>(--)?MM-DD</tt> can be a valid, as long as it is
   * a valid date.
   * \param text Input string.
   * \return Dates::Dates<kDateYearless>(const std::uint16_t) in case of
   * success, \c nullptr otherwise.
   */
  static std::shared_ptr<Date> ParseYearless(const std::string_view& text);

  /**
  * \brief Parses a Week %Date.
  *
  * Every date in format <tt>YYYY-Www</tt> can be a valid, as long as the
  * week is less than \f$ 53 \f$
  * \param text Input string.
  * \return Dates::Dates<kWeek>(const std::uint32_t) in case of
  * success, \c nullptr otherwise.
  */
  static std::shared_ptr<Date> ParseWeek(const std::string_view& text);

  /**
  * \brief Parses a %Date.
  *
  * Every date in format <tt>YYYY-MM-DD</tt> can be a valid, as long as it is
  * a valid date. A time (which can contain a Timezone) can be appended to the
  * string as well.
  * \param text Input string.
  * \return Dates::Dates<kDateNoTime>(const std::uint32_t) in case of a date
  * without a time, \c nullptr in case of failure. If a time is present, see 
  * \link ParseTime(const std::string_view&, const std::int32_t) \endlink
  */
  static std::shared_ptr<Date> ParseDate(const std::string_view& text);

  /**
  * \brief Parses a Time without a date.
  *
  * Every time in format <tt>hh:mm(:ss(.mm?m?)?)?</tt> can be a valid, 
  * as long as it is a valid time. A Timezone can be present as well.
  * \param text Input string.
  * \return Dates::Dates<kTime>(const std::uint32_t) in case of a time without
  * a timezone, \c nullptr in case of failure. If a timezone is present, see
  * \link ParseTimezone(const std::string_view&, const std::int32_t, 
    const std::uint32_t) \endlink
  */
  static inline std::shared_ptr<Date> ParseTime(const std::string_view& text);

  /**
  * \brief Parses a Time which may be the following of a date.
  *
  * Every time in format <tt>hh:mm(:ss(.mm?m?)?)?</tt> can be a valid, 
  * as long as it is a valid time. A Timezone can be present as well.
  * \param text Input string.
  * \param date %Date parsed by \link ParseDate \endlink if any, -1 otherwise.
  * \return Dates::Dates<kTime>(const std::uint32_t) in case of a time without
  * a timezone which does not follow a date,
  * Dates::Dates<kDateTime>(const std::uint64_t) in case a time without a
  * timezone which follow a date, \c nullptr in case of failure. If a timezone
  * is present, see \link ParseTimezone(const std::string_view&,
    const std::int32_t, const std::uint32_t) \endlink
  */
  static std::shared_ptr<Date> ParseTime(const std::string_view& text,
                                         const std::int32_t date);

  /**
  * \brief Parses a Timezone.
  *
  * Every Timezone in format \c Z which stands for UTC or
  * <tt>(+|-)hh(:mm)?</tt> can be a valid, as long as it is a valid timezone.
  * \param text Input string.
  * \param date %Date parsed by \link ParseDate \endlink if any, -1 otherwise.
  * \param time Time parsed by \link ParseTime \endlink
  * \return Various returns are possible, depending on the presence of the date
  * and if the timezone is UTC or not.
  * -# date is not present (i.e.: date = -1)
  *   -# timezone is UTC -> Dates::Dates<kTimeUtc>(const std::uint32_t)
  *   -# timezone is non UTC -> Dates::Dates<kTimeAndTimezone>(const std::uint64_t)
  * -# date is present
  *   -# timezone is UTC -> Dates::Dates<kDateTimeAndUtc>(const std::uint64_t)
  *   -# timezone is non UTC -> Dates::Dates<kDateTimeAndTimezone>(const std::uint64_t)
  * -# \c nullptr otherwise.
  */
  static std::shared_ptr<Date> ParseTimezone(const std::string_view& text,
                                             const std::int32_t date,
                                             const std::uint32_t time);

  /**
  * \brief Parses a Month Only %Date.
  *
  * Every date in format <tt>YYYY-MM</tt> can be a valid, as long as it is
  * a valid date.
  * \param text Input string.
  * \return Dates::Dates<kDateMonthOnly>(const std::uint16_t) in case of
  * success, \c nullptr otherwise.
  */
  static std::shared_ptr<Date> ParseMonth(const std::string_view& text);

 public:
  /**
   * \brief Minimum length to be a valid date.
   */
  static const std::uint8_t kShortest = 5;


  /**
   * \brief Maximum length to be a valid date.
   */
  static const std::uint8_t kLongest = 31;

  /**
   * \copydoc Serializable(const std::uint8_t)
   */
  explicit Date(const std::uint8_t equivalent);

  /**
   * \copydoc Serializable(const std::uint16_t)
   */
  explicit Date(const std::uint16_t equivalent);

  /**
   * \copydoc Serializable(const std::uint8_t, const std::uint64_t)
   */
  Date(const std::uint8_t bytes_required,
       const std::uint64_t equivalent);

  static std::shared_ptr<Date> Parse(const std::string_view& text);

  virtual ~Date();
};
}  // namespace WebBinaryCompression::Attributes::Types
#endif
