/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include <deque>
#include "ArchitectureChecker.hpp"
#if __BYTE_ORDER != __LITTLE_ENDIAN
#include "Endianess.hpp"
#endif
#include "Serializable.hpp"

namespace WebBinaryCompression {
  Serializable::Serializable(const std::uint8_t equivalent) :
    bytes_required(1),
    equivalent(equivalent) { }

#if __BYTE_ORDER == __LITTLE_ENDIAN
  Serializable::Serializable(const std::uint16_t equivalent) :
    bytes_required(2),
    equivalent(equivalent) {}

  Serializable::Serializable(const std::uint8_t bytes_required,
    const std::uint64_t equivalent) :
    bytes_required(bytes_required),
    equivalent(equivalent) {}
#else
  Serializable::Serializable(const std::uint16_t equivalent) :
    bytes_required(2),
    binary_equivalent(Endianess::ConvertToLittleEndian(equivalent)) {}

  Serializable::Serializable(const std::uint8_t bytes_required,
    const std::uint64_t equivalent) :
    bytes_required(bytes_required),
    binary_equivalent(Endianess::ConvertToLittleEndian(bytes_required,
      equivalent)) {}
#endif

void Serializable::EmitEquivalent(std::deque<std::uint8_t>* output_stream) {
    output_stream->push_back(Type());
    const std::uint8_t* equivalent = static_cast<const uint8_t*>(
      static_cast<const void*>(&equivalent));
    output_stream->insert(output_stream->end(), equivalent,
      equivalent + bytes_required);
  }
  Serializable::~Serializable() { }
}  // namespace WebBinaryCompression
