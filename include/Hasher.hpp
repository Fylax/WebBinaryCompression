/***************************************************************************
* MurmurHash3 was written by Austin Appleby, and is placed in the public   *
*  domain. The author hereby disclaims copyright to this source code.      *
*                                                                          *
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_HASHER_H
#define WEB_BINARY_COMPRESSION_HASHER_H
#include <string_view>
#include "ArchitectureChecker.hpp"
#if __BYTE_ORDER != __LITTLE_ENDIAN
#include "Endianess.hpp"
#endif

namespace WebBinaryCompression {
//-----------------------------------------------------------------------------
// Platform-specific functions and macros
#ifdef _MSC_VER
#define FORCE_INLINE __forceinline
#elif __GNUC__
    #define FORCE_INLINE __attribute__((always_inline)) inline
#else
    #define FORCE_INLINE inline
#endif

/**
 * \brief Implements the Austin Appleby's Murmur3 hashing algorithm.
 * 
 * Only MurmurHash3_x86_32 is used and then implemented. It is slightly
 * modified from the original as it handles only strings as keys.
 */
struct Hasher final {
 private:
  /**
   * \brief Left rotation.
   * \param x Value to rotate.
   * \param r Shift amount.
   * \return Rotated value.
   */
  static FORCE_INLINE std::uint32_t Rotl32(const std::uint32_t x,
                                           const std::int8_t r) {
    return (x << r) | (x >> (32 - r));
  }

  /**
   * \brief Returns a requested block, correctly managing endianess.
   * \param p Blocks.
   * \param i Requested block offset.
   * \return Requested block.
   */
  static FORCE_INLINE std::uint32_t Getblock(const std::uint32_t* p,
                                             const std::uint32_t i) {
    #if __BYTE_ORDER == __LITTLE_ENDIAN
    return p[i];
    #else
    return Endianess::ConvertToLittleEndian(p[i]);
    #endif
  }

  /**
   * \brief Finalization mix.
   * \param h Hash.
   * \return All bits of a hash block forced to avalanche.
   */
  static FORCE_INLINE uint32_t fmix32(uint32_t h) {
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;

    return h;
  }

 public:
  /**
   * \brief Computes the Murmur3 (x86-32 version)
   * \param str Key string.
   * \param seed Seed used for hash computation.
   * \param mask_size Mask size used for keeping the final result in a given
   * range (mask size is equal to number of bytes required for storing the hash)
   * \return Computed hash.
   */
  static uint32_t MurmurHash3_x86_32(const std::string_view& str,
                                     const uint32_t seed,
                                     const uint8_t mask_size) {
    const size_t len = str.length();
    const uint8_t* data = reinterpret_cast<const uint8_t*>(str.data());
    const int nblocks = static_cast<int>(len / 4);

    uint32_t h1 = seed;

    const uint32_t c1 = 0xcc9e2d51U;
    const uint32_t c2 = 0x1b873593U;

    const uint32_t* blocks = reinterpret_cast<const uint32_t *>(data +
                                                                nblocks * 4);

    for (auto i = -nblocks; i; ++i) {
      uint32_t k1 = Getblock(blocks, i);

      k1 *= c1;
      k1 = Rotl32(k1, 15);
      k1 *= c2;

      h1 ^= k1;
      h1 = Rotl32(h1, 13);
      h1 = h1 * 5 + 0xe6546b64;
    }

    const uint8_t* tail = static_cast<const uint8_t*>(data + nblocks * 4);

    uint32_t k1 = 0;

    switch (len & 3) {
      case 3: k1 ^= tail[2] << 16;
      case 2: k1 ^= tail[1] << 8;
      case 1: k1 ^= tail[0];
        k1 *= c1;
        k1 = Rotl32(k1, 15);
        k1 *= c2;
        h1 ^= k1;
      default: break;
    }

    h1 ^= len;

    h1 = fmix32(h1);
    return ((h1 >> mask_size) ^ h1) & ((1UL << mask_size) - 1);
  }
};
}  // namespace WebBinaryCompression
#endif
