/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include "Aria.hpp"
#include "Constants.hpp"

namespace WebBinaryCompression::Aria {

Aria::Aria(const std::uint8_t equivalent): Serializable(equivalent) {}

Aria::~Aria() { }
}  // namespace WebBinaryCompression::Aria
