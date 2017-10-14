/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_LINK_TYPE_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_LINK_TYPE_H
#include "Hasher.hpp"
#include "attributes/AttributeValue.hpp"

namespace WebBinaryCompression::Attributes::Types {
/**
 * \brief Stores the informations regarding a LinkType AttributeValue.
 */
struct LinkType final: AttributeValue {
 protected:
  std::uint8_t Type() const override;

 public:
  /**
   * \brief Minimum length to be a valid link type.
   */
  static const std::uint8_t kShortest = 3;

  /**
   * \brief Maximum length to be a valid link type.
   */
  static const std::uint8_t kLongest = 13;

  /**
   * \copydoc Serializable(const std::uint8_t)
   */
  explicit LinkType(const std::uint8_t equivalent);

  virtual ~LinkType();
};

/**
 * \brief Helper class used for LinkTypes::elements population
 *
 * \sa Hasher::MurmurHash3_x86_32(const std::string_view&, const std::uint32_t,
 * const std::uint8_t)
 */
class LinkTypeHasher {
 private:
  /**
   * \copydoc AttributeHasher::kSeed
   */
  const std::uint32_t kSeed = 123774;

  /**
   * \copydoc AttributeHasher::kMaskSize
   */
  const std::uint8_t kMaskSize = 6;

  /**
   * \copydoc AttributeHasher::kSubtraction
   */
  const std::uint8_t kSubtraction = 28;
 public:
  LinkTypeHasher() {}

  ~LinkTypeHasher() {}

  /**
   * \copydoc AttributeHasher::operator()()
   */
  std::uint32_t operator()(const std::string_view& value) const {
    return Hasher::MurmurHash3_x86_32(value, kSeed, kMaskSize) - kSubtraction;
  }
};
}  // namespace WebBinaryCompression::Attributes::Types
#endif
