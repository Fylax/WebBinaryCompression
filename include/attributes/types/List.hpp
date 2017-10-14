/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_LIST_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_TYPES_LIST_H
#include <deque>
#include <memory>
#include <queue>
#include "attributes/AttributeValue.hpp"

namespace WebBinaryCompression::Attributes::Types {
/**
 * \brief Stores the informations regarding a List AttributeValue.
 */
struct List final: AttributeValue {
 private:
  /**
   * \brief Queue containing all attribute values within this list.
   * 
   * Usually order of values in an attribute isn't important, nevertheless
   * a queue has been used so that an order costraint exists.
   */
  std::queue<std::shared_ptr<AttributeValue>> values_;

  /**
   * \brief in HTML list can be both comma or space separated, in order to
   * preserve this information, it is stored in this attribute.
   */
  const char separator_;

 protected:
  std::uint8_t Type() const override;

 public:
  /**
   * \brief Builds an empty list.
   * \param separator List separator (at the state of art only comma and space
   * are recognized by upper level parser.
   * \sa Attribute::Parse
   */
  explicit List(const char separator);

  virtual ~List();

  /**
   * \brief Append an AttributeValue to the end of the list
   * \param value Value to be appended.
   */
  void Add(std::shared_ptr<AttributeValue> value);

  /**
   * \brief Emits the equivalent for list attribute values.
   * 
   * The equivalent is at first a kList byte, followed by the equivalent of
   * each of the values contained in the list. Eventually a kEnd byte is
   * emitted.
   * \param[in, out] output_stream Stream where the output will be emitted
   * (it should be already pre-populated).
   */
  void EmitEquivalent(std::deque<std::uint8_t>* output_stream) override;

  /**
   * \brief Returns the separator
   * \return the separator
   */
  char Separator() const;

  /**
   * \brief Whether the list is a single element list.
   * 
   * This method is useful in cases in which at first try a list is detected
   * but then a single element is stored. In this case it is possible to
   * remove the list substrate.
   * \return \c true if the list contains a single element, \c false otherwise.
   */
  bool SingleElement() const;

  /**
   * \brief Removes the first element from the list and returns it.
   * \return The first element in the list.
   */
  std::shared_ptr<AttributeValue> Pop();
};
}  // namespace WebBinaryCompression::Attributes::Types
#endif
