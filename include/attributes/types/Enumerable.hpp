/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_ENUMERABLE_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_ENUMERABLE_H
#include "Hasher.hpp"
#include "attributes/AttributeValue.hpp"

namespace WebBinaryCompression::Attributes::Types {
/**
 * \brief Stores the informations regarding an Enumerable AttributeValue.
 */
struct Enumerable final: public AttributeValue {
 protected:
  std::uint8_t Type() const override;

 public:
   /**
   * \brief Minimum length to be a valid enumerable.
   */
  static const std::uint8_t kShortest = 1;

  /**
   * \brief Maximum length to be a valid enumerable.
   */
  static const std::uint8_t kLongest = 26;

  /**
   * \copydoc Serializable(const std::uint8_t)
   */
  explicit Enumerable(const std::uint8_t equivalent);

  /**
   * \copydoc Serializable(const std::uint16_t)
   */
  explicit Enumerable(const std::uint16_t equivalent);

  ~Enumerable();
};

/**
* \brief Helper class used for Enumerables::elements population
*
* \sa Hasher::MurmurHash3_x86_32(const std::string_view&, const std::uint32_t,
* const std::uint8_t)
*/
class EnumerableHasher {
 private:
   /**
    * \copydoc AttributeHasher::kSeed
    */
  const std::uint32_t kSeed = 85933;

  /**
   * \copydoc AttributeHasher::kMaskSize
   */
  const std::uint8_t kMaskSize = 8;

  /**
   * \copydoc AttributeHasher::kSubtraction
   */
  const std::uint8_t kSubtraction = 4;
 public:
  EnumerableHasher() {}

  ~EnumerableHasher() {}

  /**
   * \copydoc AttributeHasher::operator()()
   */
  uint32_t operator()(const std::string_view& value) const {
    return Hasher::MurmurHash3_x86_32(value, kSeed, kMaskSize) - kSubtraction;
  }
};
}  // namespace WebBinaryCompression::Attributes::Types
#endif
