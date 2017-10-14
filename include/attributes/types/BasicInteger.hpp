/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_BASIC_INTEGER_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_BASIC_INTEGER_H
#include <memory>
#include "attributes/AttributeValue.hpp"

namespace WebBinaryCompression::Attributes::Types {

/**
 * \brief Parses an integer and return correct object in case of success.
 * 
 * All integers are unsigned, so that it is internal representation indipendent.
 * In case a number in negative, its type is set to negative.
 */
class Integer: public AttributeValue {
 private:
  /**
   * \brief De Bruijin sequence, used to determine the minumum number of bytes
   * required to represent a number.
   */
  static const std::uint8_t kDeBruijn[64];

  /**
   * \brief Determines the minimum number of bytes to represent a number.
   * \param value Number to check.
   * \return MInimum number of bytes required.
   * \sa kDeBruijn
   */
  static std::size_t ByteSize(std::uint64_t value);

 public:
   /**
    * \copydoc Serializable(const std::uint8_t)
    */
  explicit Integer(const std::uint8_t equivalent);

  /**
   * \copydoc Serializable(const std::uint16_t)
   */
  explicit Integer(const std::uint16_t equivalent);

  /**
   * \copydoc Serializable(const std::uint8_t, const std::uint64_t)
   */
  Integer(const std::uint8_t bytes_required,
          const std::uint_fast64_t equivalent);

  /**
   * \brief Parses a text to obtain an integer.
   * \param text Text to parse.
   * \return Integer (with type correctly set).
   * \remarks In order to work, this method requires that the text argument is
   * exacly the number to parse (it may contain the sign as first character as
   * well). If this condition is not respected, it may lead to undefined
   * behaviour.
   */
  static std::shared_ptr<Integer> Parse(const std::string_view text);

  ~Integer();
};
}  // namespace WebBinaryCompression::Attributes::Types
#endif
