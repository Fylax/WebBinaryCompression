/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ARIA_H
#define WEB_BINARY_COMPRESSION_ARIA_H
#include "Serializable.hpp"

namespace WebBinaryCompression::Aria {
struct Aria: public Serializable {
 public:
   /**
    * \copydoc Serializable(const std::uint8)
    */
  explicit Aria(std::uint8_t equivalent);

  virtual ~Aria() = 0;
};
}  // namespace WebBinaryCompression::Aria
#endif
