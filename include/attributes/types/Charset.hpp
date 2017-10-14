/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_CHARSET_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_CHARSET_H
#include "Hasher.hpp"
#include "attributes/AttributeValue.hpp"

namespace WebBinaryCompression::Attributes::Types {
/**
 * \brief Stores the informations regarding a Charset AttributeValue.
 */
struct Charset final: public AttributeValue {
 protected:
  std::uint8_t Type() const override;

 public:
   /**
    * \brief Minimum length to be a valid charset.
    */
  static const std::uint8_t kShortest = 2;

  /**
  * \brief Maximum length to be a valid charset.
  */
  static const std::uint8_t kLongest = 30;

  /**
   * \copydoc Serializable(const std::uint8_t)
   */
  explicit Charset(const std::uint8_t equivalent);

  /**
   * \copydoc Serializable(const std::uint16_t)
   */
  explicit Charset(const std::uint16_t equivalent);

  ~Charset();
};

/**
 * \brief Helper class used for Charsets::elements population
 * 
 * \sa Hasher::MurmurHash3_x86_32(const std::string_view&, const std::uint32_t,
 * const std::uint8_t)
 */
class CharsetHasher {
 private:
   /**
    * \copydoc AttributeHasher::kSeed
    */
  const std::uint32_t kSeed = 184913;
  
  /**
   * \copydoc AttributeHasher::kMaskSize
   */
  const std::uint8_t kMaskSize = 8;

  /**
   * \copydoc AttributeHasher::kSubtraction
   */
  const std::uint8_t kSubtraction = 6;
 public:
  CharsetHasher() {}

  ~CharsetHasher() {}

  /**
   * \copydoc AttributeHasher::operator()()
   */
  std::uint32_t operator()(const std::string_view& value) const {
    return Hasher::MurmurHash3_x86_32(value, kSeed, kMaskSize) - kSubtraction;
  }
};
}  // namespace WebBinaryCompression::Attributes::Types
#endif
