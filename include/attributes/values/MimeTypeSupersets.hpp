/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_VALUES_MIME_TYPE_SUPERSETS_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_VALUES_MIME_TYPE_SUPERSETS_H
#include <memory>
#include <unordered_map>
#include "NumericLiterals.hpp"
#include "attributes/types/MimeTypeSuperset.hpp"

namespace WebBinaryCompression::Attributes::Values::MimeTypeSupersets {
using namespace std::string_view_literals;
/**
 * \brief Maps all \link Types::MimeTypeSuperset \endlink names to their 
 * equivalent.
 */
const std::unordered_map<std::string_view,
                         std::shared_ptr<Types::MimeTypeSuperset>,
                         Types::MimeTypeSupersetHasher> elements = {
  {
    "application"sv,
    std::make_shared<Types::MimeTypeSuperset>(0x06_uint8)
  },
  {
    "audio"sv,
    std::make_shared<Types::MimeTypeSuperset>(0x07_uint8)
  },
  {
    "example"sv,
    std::make_shared<Types::MimeTypeSuperset>(0x08_uint8)
  },
  {
    "font"sv,
    std::make_shared<Types::MimeTypeSuperset>(0x09_uint8)
  },
  {
    "image"sv,
    std::make_shared<Types::MimeTypeSuperset>(0x0A_uint8)
  },
  {
    "message"sv,
    std::make_shared<Types::MimeTypeSuperset>(0x0B_uint8)
  },
  {
    "model"sv,
    std::make_shared<Types::MimeTypeSuperset>(0x0C_uint8)
  },
  {
    "multipart"sv,
    std::make_shared<Types::MimeTypeSuperset>(0x0D_uint8)
  },
  {
    "text"sv,
    std::make_shared<Types::MimeTypeSuperset>(0x0E_uint8)
  },
  {
    "video"sv,
    std::make_shared<Types::MimeTypeSuperset>(0x0F_uint8)
  }
};
}  // namespace WebBinaryCompression::Attributes::Values::MimeTypeSupersets
#endif
