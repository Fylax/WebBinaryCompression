/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#include <memory>
#include "Aria.hpp"
#include "Hasher.hpp"

namespace WebBinaryCompression::Aria {
/**
 * \brief Stores the informations regarding an aria role.
 */
struct Role: Aria {
 protected:
  std::uint8_t Type() const override;

 public:
  /**
   * \copydoc Serializable(const std::uint8_t)
   */
  explicit Role(const std::uint8_t equivalent);

  ~Role();

  static std::shared_ptr<Role> Parse(const std::string_view& text);
};

/**
 * \brief Helper class used for Roles::elements population
 *
 * \sa Hasher::MurmurHash3_x86_32(const std::string_view&, const std::uint32_t,
 * const std::uint8_t)
 */
class AriaRoleHasher {
 private:
  /**
  * \copydoc WebBinaryCompresison::Attributes::AttributeHasher::kSeed
  */
  const std::uint32_t kSeed = 556522;

  /**
  * \copydoc WebBinaryCompresison::Attributes::AttributeHasher::kMaskSize
  */
  const std::uint8_t kMaskSize = 6;

  /**
  * \copydoc WebBinaryCompresison::Attributes::AttributeHasher::kSubtraction
  */
  const std::uint8_t kSubtraction = 1;

 public:
  AriaRoleHasher() {}

  ~AriaRoleHasher() {}

  /**
  * \copydoc WebBinaryCompresison::Attributes::AttributeHasher::operator()()
  */
  std::uint32_t operator()(const std::string_view& value) const {
    return Hasher::MurmurHash3_x86_32(value, kSeed, kMaskSize) - kSubtraction;
  }
};
}  // namespace WebBinaryCompression::Aria
