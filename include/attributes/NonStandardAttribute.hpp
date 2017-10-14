/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_NON_STANDARD_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_NON_STANDARD_H
#include <deque>
#include "Attribute.hpp"

namespace WebBinaryCompression::Attributes {
/**
 * \brief Stores the informations regarding a \link NonStandard \endlink 
 * \link Attribute \endlink
 *
 * An Attribute is NoStandard if no match is possible. This is a last
 * resort value type.
 */
class NonStandard final: public Attribute {
 private:
   /**
    * \brief Attribute actual value.
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
  explicit NonStandard(const std::string_view& text);

  ~NonStandard();

  /**
   * \brief Emits the equivalent for non-standard attribute.
   *
   * The equivalent is at first a kText byte, followed by the characters of the
   * text. Eventually a kEnd byte is emitted.
   * \param[in, out] output_stream Stream where the output will be emitted
   * (it should be already pre-populated).
   */
  void EmitEquivalent(std::deque<std::uint8_t>* output_stream) override;
};
#endif
}  // namespace WebBinaryCompression::Attributes
