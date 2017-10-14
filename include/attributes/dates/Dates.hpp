/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_DATES_DATES_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_DATES_DATES_H
#include "Constants.hpp"
#include "attributes/types/BasicDate.hpp"

/**
* \brief Contains all possible \link Types::Date \endlink derivations.
*/
namespace WebBinaryCompression::Attributes::Dates {
/**
 * \brief Provides specialization for encoding all possible dates.
 * \tparam T Must be a valid \c AttributeTypes.
 * 
 * Specialized templates are the followings:
 * 1. kDateMonthOnly
 * 2. kDateNoTime
 * 3. kWeek
 * 4. kDateYearless
 * 5. kTime
 * 6. kTimeUtc
 * 7. kTimeAndTimeZone
 * 8. kDateTime
 * 9. kDateTimeAndUtc
 * 10. kDateTimeAndTimezone
 */
template <AttributeTypes T>
struct Dates final: public Types::Date {
 protected:
  std::uint8_t Type() const override;

 public:
  explicit Dates(const std::uint16_t equivalent);

  explicit Dates(const std::uint32_t equivalent);

  explicit Dates(const std::uint64_t equivalent);

  virtual ~Dates();
};
}  // namespace WebBinaryCompression::Attributes::Dates
#endif
