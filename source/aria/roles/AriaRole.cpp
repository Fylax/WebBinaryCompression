/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#include <memory>
#include "Constants.hpp"
#include "aria/roles/AriaRole.hpp"
#include "aria/roles/TextAriaRole.hpp"
#include "aria/roles/values/Roles.hpp"

namespace WebBinaryCompression::Aria {

std::uint8_t Role::Type() const { return kRole; }

Role::Role(const std::uint8_t equivalent): Aria(equivalent) {}

Role::~Role() { }

std::shared_ptr<Role> Role::Parse(const std::string_view& text) {
  const auto role = Values::Roles::elements.find(text);
  if (role == Values::Roles::elements.end()) {
    return std::make_shared<Text>(text);
  }
  return role->second;
}
}  // namespace WebBinaryCompression::Aria
