/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include "Constants.hpp"
#include "attributes/types/MimeTypeSuperset.hpp"

namespace WebBinaryCompression::Attributes::Types {

std::uint8_t MimeTypeSuperset::Type() const { return kMimeTypeSuperset; }

MimeTypeSuperset::MimeTypeSuperset(const std::uint8_t equivalent):
  AttributeValue(equivalent) { }

MimeTypeSuperset::~MimeTypeSuperset() { }
}  // namespace WebBinaryCompression::Attributes::Types
