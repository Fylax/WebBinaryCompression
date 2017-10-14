/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include "Constants.hpp"
#include "attributes/integers/Integer.hpp"

namespace WebBinaryCompression::Attributes::Integers {
template <AttributeTypes T>
std::uint8_t Integer<T>::Type() const { return T; }

/**
 * \brief Stores a single byte positive integer.
 * \param number Value to be stored.
 */
template <>
Integer<kPositiveInteger8>::Integer(const std::uint8_t number) :
  Types::Integer(number) { }

/**
 * \brief Stores a single byte negative integer.
 * \param number Value to be stored.
 */
template <>
Integer<kNegativeInteger8>::Integer(const std::uint8_t number) :
  Types::Integer(number) { }

/**
 * \brief Stores a double byte positive integer.
 * \param number Value to be stored.
 */
template <>
Integer<kPositiveInteger16>::Integer(const std::uint16_t number) :
  Types::Integer(number) { }

/**
 * \brief Stores a double byte negative integer.
 * \param number Value to be stored.
 */
template <>
Integer<kNegativeInteger16>::Integer(const std::uint16_t number) :
  Types::Integer(number) { }

/**
 * \brief Stores a 3 byte positive integer.
 * \param number Value to be stored.
 */
template <>
Integer<kPositiveInteger24>::Integer(const std::uint32_t number):
  Types::Integer(3, number) { }

/**
 * \brief Stores a 3 byte negative integer.
 * \param number Value to be stored.
 */
template <>
Integer<kNegativeInteger24>::Integer(const std::uint32_t number) :
  Types::Integer(3, number) { }

/**
 * \brief Stores a 4 byte positive integer.
 * \param number Value to be stored.
 */
template <>
Integer<kPositiveInteger32>::Integer(const std::uint32_t number) :
  Types::Integer(4, number) { }

/**
 * \brief Stores a 4 byte negative integer.
 * \param number Value to be stored.
 */
template <>
Integer<kNegativeInteger32>::Integer(const std::uint32_t number) :
  Types::Integer(4, number) { }

/**
 * \brief Stores a 5 byte positive integer.
 * \param number Value to be stored.
 */
template <>
Integer<kPositiveInteger40>::Integer(const std::uint64_t number) :
  Types::Integer(5, number) { }

/**
 * \brief Stores a 5 byte negative integer.
 * \param number Value to be stored.
 */
template <>
Integer<kNegativeInteger40>::Integer(const std::uint64_t number) :
  Types::Integer(5, number) { }

/**
 * \brief Stores a 6 byte positive integer.
 * \param number Value to be stored.
 */
template <>
Integer<kPositiveInteger48>::Integer(const std::uint64_t number) :
  Types::Integer(6, number) { }

/**
 * \brief Stores a 6 byte negative integer.
 * \param number Value to be stored.
 */
template <>
Integer<kNegativeInteger48>::Integer(const std::uint64_t number) :
  Types::Integer(6, number) { }

/**
 * \brief Stores a 7 byte positive integer.
 * \param number Value to be stored.
 */
template <>
Integer<kPositiveInteger56>::Integer(const std::uint64_t number) :
  Types::Integer(7, number) { }

/**
 * \brief Stores a 7 byte negative integer.
 * \param number Value to be stored.
 */
template <>
Integer<kNegativeInteger56>::Integer(const std::uint64_t number) :
  Types::Integer(7, number) { }

/**
 * \brief Stores a 8 byte positive integer.
 * \param number Value to be stored.
 */
template <>
Integer<kPositiveInteger64>::Integer(const std::uint64_t number) :
  Types::Integer(8, number) { }

/**
 * \brief Stores a 8 byte negative integer.
 * \param number Value to be stored.
 */
template <>
Integer<kNegativeInteger64>::Integer(const std::uint64_t number) :
  Types::Integer(8, number) { }

template <AttributeTypes T>
Integer<T>::~Integer() { }
} // namespace WebBinaryCompression::Attributes::Integers
