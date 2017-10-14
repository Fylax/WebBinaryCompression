/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTE_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTE_H
#include <deque>
#include <memory>
#include "Hasher.hpp"
#include "Serializable.hpp"
#include "attributes/AttributeValue.hpp"

namespace WebBinaryCompression::Attributes {

/**
 * \brief A generic attribute.
 * 
 * It is a composite class which has the attribute per se and the value
 * associated to it.
 */
struct Attribute: public Serializable {
 protected:
  /**
   * \brief Value associated to the attribute.
   */
  std::shared_ptr<AttributeValue> value_ = nullptr;

  std::uint8_t Type() const override;

 public:
  /**
   * \copydoc Serializable(const std::uint8)
   */
  explicit Attribute(const std::uint8_t equivalent);

  ~Attribute();

  /**
   * \brief Parses a text to find an attribute.
   * 
   * Given a text, which must start at the beginning of the attribute (no
   * blank spaces allowed) and contain at least the attribute itself and its
   * value (it may containg all the remaining unparsed HTML), it looks for
   * an attribute and its value.
   * \param[in, out] string Input: unparsed attribute and associated value are
   * mandatory at the very beginning of the string. Output: input string
   * stripped of the parsed attribute and associated value.
   * \return Parsed attribute with associated value.
   */
  static std::unique_ptr<Attribute> Parse(std::string_view* string);

  void EmitEquivalent(std::deque<std::uint8_t>* output_stream) override;
};

/**
* \brief Helper class used for Attributes::elements population
*
* \sa Hasher::MurmurHash3_x86_32(const std::string_view&, const std::uint32_t,
* const std::uint8_t)
*/
class AttributeHasher {
 private:
  /**
   * \brief Seed for the Murmur3 algorithm.
   */
  const std::uint32_t kSeed = 159773;

  /**
   * \brief Mask used for reducing the amount of memory required by the hashing
   * algorithm.
   *
   * The mask is used in this way:
   * \f[
   *    hash = Murmur3\\
   *    mask = (1 << kMaskSize) - 1\\
   *    ((hash >> kMaskSize) \oplus hash) \land mask
   * \f]
   */
  const std::uint8_t kMaskSize = 7;

  /**
   * \brief As first result thrown by the hashing algorithm may be greater
   * than zero, through this parameter the resulting hash is forced to start
   * from zero.
   */
  const std::uint8_t kSubtraction = 0;

 public:
  AttributeHasher() {}

  ~AttributeHasher() {}

  /**
   * \brief Exposes the operator required for computing the hash.
   * \param value Name whose hash is required.
   * \return Required hash.
   */
  std::uint32_t operator()(const std::string_view& value) const {
    return Hasher::MurmurHash3_x86_32(value, kSeed, kMaskSize) - kSubtraction;
  }
};
}  // namespace WebBinaryCompression::Attributes
#endif
