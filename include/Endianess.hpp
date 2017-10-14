/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ENDIANESS_H
#define WEB_BINARY_COMPRESSION_ENDIANESS_H
#include<cstdint>

namespace WebBinaryCompression {

/**
 * \brief Singleton class used for managing the Endianess.
 */
class Endianess final {
  /**
   * \brief Supported endianess types.
   */
  enum EndianessType {
    kLittleEndian,
    kBigEndian
  };

  /**
   * \brief Singleton instance.
   * \return Singleton instance.
   */
  static Endianess& Instance();

  /**
   * \brief Endianess type, determined only once
   */
  EndianessType type_;

  Endianess();

 public:
  Endianess(Endianess const&) = delete;

  /**
   * \brief Special purpose conversion to little endian.
   * \param number_to_convert 16 bit number to be converted to little endian.
   * \return Little endian conversion.
   */
  static std::uint16_t ConvertToLittleEndian(
    const std::uint16_t number_to_convert);

  /**
  * \brief Special purpose conversion to little endian.
  * \param number_to_convert 32 bit number to be converted to little endian.
  * \return Little endian conversion.
  */
  static std::uint32_t ConvertToLittleEndian(
    const std::uint32_t number_to_convert);

  /**
   * \brief General purpose conversion to little endian.
   * \param number_of_bytes Size of the number to be converted.
   * \param number_to_convert Number to convert.
   * \return Little endian conversion.
   */
  static std::uint64_t ConvertToLittleEndian(
    const unsigned number_of_bytes,
    const std::uint64_t number_to_convert);
};
}  // namespace WebBinaryCompression
#endif
