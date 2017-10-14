/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_SERIALIZABLE_H
#define WEB_BINARY_COMPRESSION_SERIALIZABLE_H
#include <cstdint>
#include <deque>

namespace WebBinaryCompression {
/**
 * \brief Core class for the algorithm.
 * 
 * Provides a basic interface for all HTML objects which will be serialized.
 */
struct Serializable {
 protected:
  /**
   * \brief Represents the type of the concrete class.
   * \return The type of the concrete class.
   */
  virtual std::uint8_t Type() const = 0;

 public:
  /**
  * \brief Number of bytes required for representing the element.
  *
  * This field specifies how many bytes should be taken into account of the
  * \c binary_equivalent field.
  */
  const std::uint8_t bytes_required;

  /**
  * \brief Binary representation of the element.
  *
  * This field stores byte(s) representation (accordingly with the specs).
  */
  const std::uint64_t equivalent;

  /**
   * \brief Constructs the object shortcutting the \c Endianess check.
   * 
   * Due to the fact that endianess is a non-sense for single byte values, a
   * specific constructor has been provided.
   * \param equivalent Byte value for the searched element.
   */
  explicit Serializable(const std::uint8_t equivalent);

  /**
  * \brief Constructs the object proviging a special-case \c Endianess check.
  *
  * Due to the fact that most of equivalent serializations doesn't exceed two
  * bytes, a special-case constructor has been provided.
  * \param equivalent Two-byte value for the searched element.
  */
  explicit Serializable(const std::uint16_t equivalent);

  /**
   * \brief General purpose constructor.
   * 
   * All the object that doesn't adhere the single or two-byte constructor,
   * use this one.
   * \param bytes_required Number of bytes required for representing the element,
   * in range \f$ [1, 8] \f$.
   * \param equivalent N-Byte value for the searched element.
   */
  Serializable(const std::uint8_t bytes_required,
               const std::uint64_t equivalent);


  /**
   * \brief Generates the byte stream that will be the final outcome
   * \param[in,out] output_stream Stream where the output will be emitted
   * (it can be already pre-populated).
   */
  virtual void EmitEquivalent(std::deque<std::uint8_t>* output_stream);

  virtual ~Serializable();
};
}  // namespace WebBinaryCompression
#endif
