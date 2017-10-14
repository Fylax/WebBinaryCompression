/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_POSSIBLE_VALUE_TYPES_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_POSSIBLE_VALUE_TYPES_H
#include <bitset>
#include <memory>
#include "Attribute.hpp"

namespace WebBinaryCompression::Attributes::Types {

/**
 * \brief Evaluates the possible types for a given attribute value.
 */
class PossibleValueTypes final {
 private:
  /**
   * \brief Integer exposing all posible types.
   *
   * Values (from least significant bit) are:
   * 1. Boolean
   * 2. Charset
   * 3. Date
   * 4. Link Type
   * 5. Mime Type
   * 6. Mime Type Superset
   * 7. Enumerable
   * 8. Integer
   */
  const std::bitset<8> bitmap_;

  explicit PossibleValueTypes(std::bitset<8> bitmap);

 public:
  /**
   * \brief Evaluates the possible types for a given attribute value.
   * 
   * Given an attribute value, it checks it character by character to see if
   * they are in a given range of legal values.
   * \param value Attribute value to be parsed
   * \param attribute_name Attribute name
   * \return Possible types for the given attribute value. Please do note that,
   * while for booleans (empty string or string equal to attribute_name) and
   * for integers (optional signl followed by only digits) it is an exact
   * evaluation, while for all the others is just a suggestion.
   */
  static std::unique_ptr<PossibleValueTypes>
  CheckTypes(const std::string_view& value,
             const std::string_view& attribute_name);

  ~PossibleValueTypes();

  /**
   * \brief Whether the attribute value is a \link Boolean \endlink
   * \return \c true if the value is Boolean, \c false otherwise.
   */
  bool Boolean() const;

  /**
   * \brief Whether the attribute value may be a \link Charset \endlink
   * \return \c true if the value may be a Charset, \c false otherwise.
   */
  bool Charset() const;

  /**
   * \brief Whether the attribute value may be a \link Date \endlink
   * \return \c true if the value may be a Date, \c false otherwise.
   */
  bool Date() const;

  /**
   * \brief Whether the attribute value may be a \link LinkType \endlink
   * \return \c true if the value may be a LinkType, \c false otherwise.
   */
  bool LinkType() const;

  /**
   * \brief Whether the attribute value may be a \link MimeType \endlink
   * \return \c true if the value may be a MimeType, \c false otherwise.
   */
  bool MimeType() const;

  /**
   * \brief Whether the attribute value may be a \link MimeTypeSuperset \endlink
   * \return \c true if the value may be a MimeTypeSuperset, \c false otherwise.
   */
  bool MimeTypeSuperset() const;

  /**
   * \brief Whether the attribute value may be an \link Enumerable \endlink
   * \return \c true if the value may be an Enumerable, \c false otherwise.
   */
  bool Enumerable() const;

  /**
   * \brief Whether the attribute value is an \link Integer \endlink
   * \return \c true if the value is an Integer, \c false otherwise.
   */
  bool Integer() const;
};
}  // namespace WebBinaryCompression::Attributes::Types
#endif
