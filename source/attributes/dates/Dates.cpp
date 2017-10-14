/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include "attributes/dates/Dates.hpp"

namespace WebBinaryCompression::Attributes::Dates {

template <AttributeTypes T>
std::uint8_t Dates<T>::Type() const { return T; }

/**
 * \brief Stores a Month Only date (<tt>YYYY-MM</tt> format).
 * \param equivalent Number of months since 0000-01.
 *  
 * \code{.unparsed}
 * +----------+----------+
 * | nnnnnnnn | nnnnnnnn |
 * +----------+----------+
 * \endcode
 * 
 * \remarks If value is greater than \f$ 2^{16}-1 \f$ (around \f$ 5458\ years\f$)
 * parsing will fail.
 */
template <>
Dates<kDateMonthOnly>::Dates(const std::uint16_t equivalent) :
  Types::Date(equivalent) { }

/**
* \brief Stores a Yearless date (<tt>(--)?MM-DD</tt> format).
* \param equivalent Number of days since <tt>01/01</tt>, considering the year as leap.
*
* \code{.unparsed}
* +----------+----------+
* | 0000000n | nnnnnnnn |
* +----------+----------+
* \endcode
*
* \remarks If the result is greater than \f$ 366 \f$ or the pair
* \f$ (month, day) \f$ is invalid (e.g.: 02-30), parsing will fail.
*/
template <>
Dates<kDateYearless>::Dates(const std::uint16_t equivalent) :
  Types::Date(equivalent) { }

/**
* \brief Stores a Week date (<tt>YYYY-Www</tt> format).
* \param equivalent Highest two bytes for year, lowest byte for week.
*
* \code{.unparsed}
* +----------+----------+----------+
* | yyyyyyyy | yyyyyyyy | 00wwwwww |
* +----------+----------+----------+
* \endcode
*
* \remarks If year is greater than \f$ 2^{16}-1 \f$ or week is greater than
* \f$ 53 \f$ parsing will fail.
*/
template <>
Dates<kWeek>::Dates(const std::uint32_t equivalent) :
  Types::Date(3, equivalent) { }

/**
* \brief Stores a simple Date (<tt>YYYY-MM-DD</tt> format).
* \param equivalent Number of days since 0000/01/01
*
* \code{.unparsed}
* +----------+----------+----------+
* | dddddddd | dddddddd | dddddddd |
* +----------+----------+----------+
* \endcode
*
* \remarks If year is greater than \f$ 2^{24}-1 \f$ (around \f$ 45933\ years \f$
* or the pair \f$ (month, day) \f$ is invalid (e.g.: 02-30), parsing will fail.
*/
template <>
Dates<kDateNoTime>::Dates(const std::uint32_t equivalent) :
  Types::Date(3, equivalent) { }

/**
* \brief Stores a Time (<tt>hh:mm(:ss(.mm?m?)?)?</tt> format).
* \param equivalent Number milliseconds since 00:00:00.000
*
* \code{.unparsed}
* +----------+----------+----------+----------+
* | 00000nnn | nnnnnnnn | nnnnnnnn | nnnnnnnn |
* +----------+----------+----------+----------+
* \endcode
*
* \remarks If the value is greater than \f$ 86400000 \f$ (milliseconds in a day)
* or one between hour, minutes, seconds and milliseconds are invalid values,
* parsing wil fail.
*/
template <>
Dates<kTime>::Dates(const std::uint32_t equivalent) :
  Types::Date(4, equivalent) { }

/**
* \brief Stores a Time (<tt>hh:mm(:ss(.mm?m?)?)?</tt> format).
* \param equivalent Number milliseconds since 00:00:00.000 with UTC flag (11)
*
* \code{.unparsed}
* +----------+----------+----------+----------+
* | 11000nnn | nnnnnnnn | nnnnnnnn | nnnnnnnn |
* +----------+----------+----------+----------+
* \endcode
*
* \remarks If the value is greater than \f$ 86400000 \f$ (milliseconds in a day)
* or one between hour, minutes, seconds and milliseconds are invalid values,
* parsing wil fail.
*/
template <>
Dates<kTimeUtc>::Dates(const std::uint32_t equivalent) :
  Types::Date(4, equivalent) { }

/**
* \brief Stores a Time (hh:mm(:ss(.mm?m?)?)? format).
* \param equivalent Number milliseconds since 00:00:00.000 with timezone flag
* (01 for negative, 10 for positive) and a timezone expressed as minutes since 
* 00:00
*
* \code{.unparsed}
* +----------+----------+----------+----------+----------+
* | ffzzzzzz | zzzzznnn | nnnnnnnn | nnnnnnnn | nnnnnnnn |
* +----------+----------+----------+----------+----------+
* \endcode
*
* \remarks If the value \c n is greater than \f$ 86400000 \f$ (milliseconds in 
* a day) or value \c z is greater than \f$ 1440 \f$ (minutes in a day) or one 
* between hour, minutes, seconds and milliseconds are invalid values, parsing
* wil fail.
*/
template <>
Dates<kTimeAndTimeZone>::Dates(const std::uint64_t equivalent) :
  Types::Date(5, equivalent) { }

/**
 * \copydoc Dates<kDateNoTime>::Dates(const std::uint16_t equivalent)	
 * \copydoc Dates<kTime>::Dates(const std::uint16_t equivalent)	
 */
template <>
Dates<kDateTime>::Dates(const std::uint64_t equivalent) :
  Types::Date(7, equivalent) { }

/**
* \copydoc Dates<kDateNoTime>::Dates(const std::uint16_t equivalent)
* \copydoc Dates<kTimeUtc>::Dates(const std::uint16_t equivalent)
*/
template <>
Dates<kDateTimeAndUtc>::Dates(const std::uint64_t equivalent) :
  Types::Date(7, equivalent) { }

/**
* \copydoc Dates<kDateNoTime>::Dates(const std::uint16_t equivalent)
* \copydoc Dates<kTimeAndTimezone>::Dates(const std::uint16_t equivalent)
*/
template <>
Dates<kDateTimeAndTimezone>::Dates(const std::uint64_t equivalent) :
  Types::Date(8, equivalent) { }

template <AttributeTypes T>
Dates<T>::~Dates() { }
}  // namespace WebBinaryCompression::Attributes::Dates
