/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_MIME_TYPE_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_MIME_TYPE_H
#include "Hasher.hpp"
#include "attributes/AttributeValue.hpp"

namespace WebBinaryCompression::Attributes::Types {
/**
 * \brief Stores the informations regarding a MimeType AttributeValue.
 */
struct MimeType final: AttributeValue {
 protected:
  std::uint8_t Type() const override;

 public:
  /**
   * \brief Minimum length to be a valid mime type.
   */
  static const std::uint8_t kShortest = 7;

  /**
   * \brief Maximum length to be a valid mime type.
   */
  static const std::uint8_t kLongest = 84;

  /**
   * \copydoc Serializable(const std::uint16_t)
   */
  explicit MimeType(const std::uint16_t equivalent);

  virtual ~MimeType();
};

/**
 * \brief Helper class used for MimeTypes::elements population
 *
 * \sa Hasher::MurmurHash3_x86_32(const std::string_view&, const std::uint32_t,
 * const std::uint8_t)
 */
class MimeTypeHasher {
 private:
   /**
    * \copydoc AttributeHasher::kSeed
    */
  const std::uint32_t kSeed = 996055;

  /**
   * \copydoc AttributeHasher::kMaskSize
   */
  const std::uint8_t kMaskSize = 11;

  /**
   * \copydoc AttributeHasher::kSubtraction
   */
  const std::uint8_t kSubtraction = 11;
 public:
  MimeTypeHasher() {}

  ~MimeTypeHasher() {}

  /**
   * \copydoc AttributeHasher::operator()()
   */
  std::uint32_t operator()(const std::string_view& value) const {
    return Hasher::MurmurHash3_x86_32(value, kSeed, kMaskSize) - kSubtraction;
  }
};
}  // namespace WebBinaryCompression::Attributes::Types
#endif
