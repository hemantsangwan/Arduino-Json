// Copyright Benoit Blanchon 2014
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

#include "NodeIterator.hpp"
#include "NodeConstIterator.hpp"
#include "../JsonBuffer.hpp"

namespace ArduinoJson {
namespace Internals {

template <typename T>
class List {
 public:
  typedef Node<T> node_type;
  typedef NodeIterator<T> iterator;
  typedef NodeConstIterator<T> const_iterator;

  List(JsonBuffer *buffer) : _buffer(buffer), _firstNode(NULL) {}

  bool success() const { return _buffer != NULL; }

  iterator begin() { return iterator(_firstNode); }
  iterator end() { return iterator(NULL); }

  const_iterator begin() const { return const_iterator(_firstNode); }
  const_iterator end() const { return const_iterator(NULL); }

 protected:
  JsonBuffer *_buffer;
  node_type *_firstNode;
};
}
}