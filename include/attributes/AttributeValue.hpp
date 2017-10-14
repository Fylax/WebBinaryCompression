/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_ATTRIBUTE_VALUE_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_ATTRIBUTE_VALUE_H
#include "Serializable.hpp"

namespace WebBinaryCompression::Attributes {
/**
 * \brief Base class for each attribute value.
 * 
 * This is a pure virtual class; it exists only to have a polymorphic attribute
 * value into an \link Attribute \endlink
 */
struct AttributeValue: public Serializable {
  /**
   * \copydoc Serializable(const std::uint8_t)
   */
  explicit AttributeValue(const std::uint8_t equivalent);
 
  /**
  * \copydoc Serializable(const std::uint16_t)
  */
  explicit AttributeValue(const std::uint16_t equivalent);

  /**
  * \copydoc Serializable(const std::uint8_t, const std::uint64_t)
  */
  AttributeValue(const std::uint8_t bytes_required,
                 const std::uint64_t equivalent);

  virtual ~AttributeValue();
};
}  // namespace WebBinaryCompression::Attributes
#endif
