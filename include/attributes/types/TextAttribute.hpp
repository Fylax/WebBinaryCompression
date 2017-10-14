/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_TEXT_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_TEXT_H
#include <deque>
#include <string_view>
#include "attributes/AttributeValue.hpp"

namespace WebBinaryCompression::Attributes::Types {
/**
 * \brief Stores the informations regarding a Text AttributeValue.
 * 
 * An AttributeValue is Text if no other type is possible. This is a last
 * resort value type.
 */
struct Text final: public AttributeValue {
 private:
  /**
   * \brief Attribute value actual value.
   */
  const std::string_view text_;

 protected:
  std::uint8_t Type() const override;

 public:
  /**
   * \brief Sets the internal view to the correct object.
   *
   * Due to the fact that \0 strings cannot appear in UTF-8 (and due the fact
   * that it is the most common encoding together with ASCII), it has not been
   * escaped.
   * \param text Self explaining, isn't it?
   */
  explicit Text(const std::string_view& text);

  virtual ~Text();

  /**
   * \brief Emits the equivalent for text attribute values.
   *
   * The equivalent is at first a kText byte, followed by the characters of the
   * text. Eventually a kEnd byte is emitted.
   * \param[in, out] output_stream Stream where the output will be emitted
   * (it should be already pre-populated).
   */
  void EmitEquivalent(std::deque<std::uint8_t>* output_stream) override;
};
}  // namespace WebBinaryCompression::Attributes::Types
#endif
