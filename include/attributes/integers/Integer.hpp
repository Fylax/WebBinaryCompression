/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_INTEGERS_INTEGER_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_INTEGERS_INTEGER_H
#include "Constants.hpp"
#include "attributes/types/BasicInteger.hpp"

/**
 * \brief Contains all possible \link Types::Integer \endlink derivations.
 */
namespace WebBinaryCompression::Attributes::Integers {
/**
  * \brief  Provides specialization for encoding all possible integers.
  * \tparam T Must be a valid \c AttributeTypes.
  * 
  * Specialized templates are the followings:
  * 1. kPositiveInteger8
  * 2. kPositiveInteger16
  * 3. kPositiveInteger24
  * 4. kPositiveInteger32
  * 5. kPositiveInteger40
  * 6. kPositiveInteger48
  * 7. kPositiveInteger56
  * 8. kPositiveInteger64
  * 9. kNegativeInteger8
  * 10. kNegativeInteger16
  * 11. kNegativeInteger24
  * 12. kNegativeInteger32
  * 13. kNegativeInteger40
  * 14. kNegativeInteger48
  * 15. kNegativeInteger56
  * 16. kNegativeInteger64
  */
template <AttributeTypes T>
struct Integer final: public Types::Integer {
 protected:
  std::uint8_t Type() const override;

 public:
  explicit Integer(const std::uint8_t number);

  explicit Integer(const std::uint16_t number);

  explicit Integer(const std::uint32_t number);

  explicit Integer(const std::uint64_t number);

  virtual ~Integer();
};
}  // namespace WebBinaryCompression::Attributes::Integers
#endif
