// To add your copyright and license header

#ifndef _MY_INTERFACE_H_
#define _MY_INTERFACE_H_

#include <node.h>
#include <v8.h>

#include <string>

#include "gen/generator_helper.h"
#include "gen/array_helper.h"

class Int8Array {
 public:
  Int8Array(int8_t* data, int32_t offset, int32_t length) {
    data_ = data;
    offset_ = offset;
    length_ = length;
  }

  // bool getOwnBuffer() const {
  // }

  // void setOwnBuffer(bool own) {
  // }

  ~Int8Array() {

  }

  operator v8::Local<v8::Value> () const {
    auto array_buffer = v8::ArrayBuffer::New(v8::Isolate::GetCurrent(), data_, length_);
    return v8::Int8Array::New(array_buffer, 0, length_);
  }

 private:
  int8_t* data_;
  int32_t offset_;
  int32_t length_;
};

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

  Int8Array asInt8Array();

  void SetJavaScriptThis(v8::Local<v8::Object> obj) {
    // Ignore this if you don't need it
    // Typical usage: emit an event on `obj`
  }

 private:
  int32_t length_;
  int8_t* data_;
};

#endif  // _MY_INTERFACE_H_
