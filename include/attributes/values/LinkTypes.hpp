/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_VALUES_LINK_TYPES_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_VALUES_LINK_TYPES_H
#include <memory>
#include <unordered_map>
#include "NumericLiterals.hpp"
#include "attributes/types/LinkType.hpp"

namespace WebBinaryCompression::Attributes::Values::LinkTypes {
using namespace std::string_view_literals;
/**
 * \brief Maps all \link Types::LinkType \endlink names to their equivalent.
 */
const std::unordered_map<std::string_view, std::shared_ptr<Types::LinkType>,
                         Types::LinkTypeHasher> elements = {
  {
    "alternate"sv,
    std::make_shared<Types::LinkType>(0x06_uint8)
  },
  {
    "author"sv,
    std::make_shared<Types::LinkType>(0x07_uint8)
  },
  {
    "bookmark"sv,
    std::make_shared<Types::LinkType>(0x08_uint8)
  },
  {
    "dns-prefetch"sv,
    std::make_shared<Types::LinkType>(0x09_uint8)
  },
  {
    "external"sv,
    std::make_shared<Types::LinkType>(0x0A_uint8)
  },
  {
    "help"sv,
    std::make_shared<Types::LinkType>(0x0B_uint8)
  },
  {
    "icon"sv,
    std::make_shared<Types::LinkType>(0x0C_uint8)
  },
  {
    "license"sv,
    std::make_shared<Types::LinkType>(0x0D_uint8)
  },
  {
    "manifest"sv,
    std::make_shared<Types::LinkType>(0x0E_uint8)
  },
  {
    "next"sv,
    std::make_shared<Types::LinkType>(0x0F_uint8)
  },
  {
    "nofollow"sv,
    std::make_shared<Types::LinkType>(0x10_uint8)
  },
  {
    "noopener"sv,
    std::make_shared<Types::LinkType>(0x11_uint8)
  },
  {
    "noreferrer"sv,
    std::make_shared<Types::LinkType>(0x12_uint8)
  },
  {
    "pingback"sv,
    std::make_shared<Types::LinkType>(0x13_uint8)
  },
  {
    "preconnect"sv,
    std::make_shared<Types::LinkType>(0x14_uint8)
  },
  {
    "prefetch"sv,
    std::make_shared<Types::LinkType>(0x15_uint8)
  },
  {
    "preload"sv,
    std::make_shared<Types::LinkType>(0x16_uint8)
  },
  {
    "prerender"sv,
    std::make_shared<Types::LinkType>(0x17_uint8)
  },
  {
    "prev"sv,
    std::make_shared<Types::LinkType>(0x18_uint8)
  },
  {
    "search"sv,
    std::make_shared<Types::LinkType>(0x19_uint8)
  },
  {
    "sidebar"sv,
    std::make_shared<Types::LinkType>(0x1A_uint8)
  },
  {
    "stylesheet"sv,
    std::make_shared<Types::LinkType>(0x1B_uint8)
  },
  {
    "tag"sv,
    std::make_shared<Types::LinkType>(0x1C_uint8)
  }
};
}  // namespace WebBinaryCompression::Attributes::Values::LinkTypes
#endif
