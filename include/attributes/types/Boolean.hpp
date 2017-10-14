/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_BOOLEAN_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_BOOLEAN_H
#include <deque>
#include "attributes/AttributeValue.hpp"

namespace WebBinaryCompression::Attributes::Types {
/**
 * \brief Stores the informations regarding a Boolean AttributeValue.
 */
struct Boolean final: public AttributeValue {
 protected:
  std::uint8_t Type() const override;

 public:
  /**
   * \brief Empty constructor. Not really required as booleans just emit a
   * \c kBoolean type.
   */
  Boolean();

  virtual ~Boolean();

  /**
   * \brief Emits the equivalent for boolean attribute values.
   * 
   * The equivalent is just one single byte containing the kBoolean type,
   * no futher information is required.
   * \param[in, out] output_stream Stream where the output will be emitted
   * (it should be already pre-populated).
   */
  void EmitEquivalent(std::deque<std::uint8_t>* output_stream) override;
};
}  // namespace WebBinaryCompression::Attributes::Types
#endif
