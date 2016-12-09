// To add your copyright and license header

#ifndef _MY_INTERFACE_H_
#define _MY_INTERFACE_H_

#include <node.h>
#include <v8.h>

#include <string>

#include "gen/generator_helper.h"
#include "gen/array_helper.h"

template <class T>
class TypedArrayHelper {
 public:
  typedef T typed_array_t;

  TypedArrayHelper(void* data, int32_t offset, int32_t length, bool external = true) {
    data_ = data;
    offset_ = offset;
    length_ = length;
    external_buffer_ = external;
  }

  TypedArrayHelper(const TypedArrayHelper& rhs) {
    CopyFrom(rhs);
  }

  ~TypedArrayHelper() {}

  TypedArrayHelper& operator = (const TypedArrayHelper& rhs) {
    CopyFrom(rhs);
    return *this;
  }

  bool getExternalBufferMode() const {
    return external_buffer_;
  }

  void setExternalBufferMode(bool external) {
    external_buffer_ = external;
  }

  v8::Local<v8::Value> GetTypedArray() const {
    auto mode = external_buffer_ ?
        v8::ArrayBufferCreationMode::kExternalized :
        v8::ArrayBufferCreationMode::kInternalized;

    auto array_buffer = v8::ArrayBuffer::New(
        v8::Isolate::GetCurrent(), data_, length_, mode);

    return typed_array_t::New(array_buffer, offset_, length_);
  }

  operator v8::Local<v8::Value> () const {
    return GetTypedArray();
  }

  bool operator == (const TypedArrayHelper& rhs) {
    if (this != &rhs) {
      return data_ == rhs.data_ &&
          offset_ == rhs.offset_ &&
          length_ == rhs.length_ &&
          external_buffer_ == rhs.external_buffer_;
    }
    return true;
  }

 private:
  void CopyFrom(const TypedArrayHelper& rhs) {
    if (this != &rhs) {
      data_ = rhs.data_;
      offset_ = rhs.offset_;
      length_ = rhs.length_;
      external_buffer_ = rhs.external_buffer_;
    }
  }

 private:
  void* data_;
  int32_t offset_;
  int32_t length_;
  bool external_buffer_;
};

typedef TypedArrayHelper<v8::Int8Array> HelperType;

class MyInterface {
 public:
  MyInterface();

  MyInterface(const MyInterface& rhs);

  ~MyInterface();

  MyInterface& operator = (const MyInterface& rhs);

 public:
  int32_t get_length() const {
    return this->length_;
  }

  void setData(const int32_t& offset, const int8_t& data);

  int8_t getData(const int32_t& offset);

  HelperType asInt8Array();

  void SetJavaScriptThis(v8::Local<v8::Object> obj) {
    // Ignore this if you don't need it
    // Typical usage: emit an event on `obj`
  }

 private:
  int32_t length_;
  int8_t* data_;
};

#endif  // _MY_INTERFACE_H_
