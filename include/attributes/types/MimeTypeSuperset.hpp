/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_MIME_TYPE_SUPERSET_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_MIME_TYPE_SUPERSET_H
#include "Hasher.hpp"
#include "attributes/AttributeValue.hpp"

namespace WebBinaryCompression::Attributes::Types {
/**
 * \brief Stores the informations regarding a MimeType AttributeValue.
 */
struct MimeTypeSuperset final: AttributeValue {
 protected:
  std::uint8_t Type() const override;

 public:
  /**
   * \brief Minimum length to be a valid mime type superset.
   */
  static const std::uint8_t kShortest = 6;

  /**
   * \brief Maximum length to be a valid mime type superset.
   */
  static const std::uint8_t kLongest = 13;

  /**
   * \copydoc Serializable(const std::uint8_t)
   */
  explicit MimeTypeSuperset(const std::uint8_t equivalent);

  virtual ~MimeTypeSuperset();
};

/**
 * \brief Helper class used for MimeTypeSupersets::elements population
 *
 * \sa Hasher::MurmurHash3_x86_32(const std::string_view&, const std::uint32_t,
 * const std::uint8_t)
*/
class MimeTypeSupersetHasher {
 private:
   /**
    * \copydoc AttributeHasher::kSeed
    */
  const std::uint32_t kSeed = 242;

  /**
   * \copydoc AttributeHasher::kMaskSize
   */
  const std::uint8_t kMaskSize = 4;

  /**
   * \copydoc AttributeHasher::kSubtraction
   */
  const std::uint8_t kSubtraction = 0;
 public:
  MimeTypeSupersetHasher() {}

  ~MimeTypeSupersetHasher() {}

  /**
   * \copydoc AttributeHasher::operator()()
   */
  std::uint32_t operator()(const std::string_view& value) const {
    return Hasher::MurmurHash3_x86_32(value, kSeed, kMaskSize) - kSubtraction;
  }
};
}  // namespace WebBinaryCompression::Attributes::Types
#endif
