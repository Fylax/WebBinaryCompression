/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#include <deque>
#include "AriaRole.hpp"

namespace WebBinaryCompression::Aria {
/**
 * \brief Stores the informations regarding a Text Aria Role.
 * 
 * An AriaRiole is Text if non standard equivalent has been found.
 */
class Text final: public Role {
 private:
  /**
   * \brief Aria Role value actual value.
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

  ~Text();

  /**
   * \brief Emits the equivalent for text aria roles.
   *
   * The equivalent is at first a kTextRole byte, followed by the characters of
   * the text. Eventually a kEnd byte is emitted.
   * \param[in, out] output_stream Stream where the output will be emitted
   * (it should be already pre-populated).
   */
  void EmitEquivalent(std::deque<std::uint8_t>* output_stream) override;
};
}  // namespace WebBinaryCompression::Aria
