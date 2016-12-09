// To add your copyright and license header

#ifndef _FAKE_IMAGE_H_
#define _FAKE_IMAGE_H_

#include <node.h>
#include <v8.h>

#include <string>

#include "gen/generator_helper.h"
#include "gen/array_helper.h"

class FakeImage {
 public:
  FakeImage();

  FakeImage(const FakeImage& rhs);

  ~FakeImage();

  FakeImage& operator = (const FakeImage& rhs);

 public:
  Uint8Array get_rawBuffer() const {
    return this->rawBuffer_;
  }

  int32_t get_length() const {
    return this->length_;
  }

  void setData(const int32_t& offset, const int8_t& data);

  int8_t getData(const int32_t& offset);

  Int8Array asInt8Array();

  Uint8Array asUin86Array();

  Uint8ClampedArray asUint8ClampedArray();

  Int16Array asInt16Array();

  Uint16Array asUint16Array();

  Int32Array asInt32Array();

  Uint32Array asUint16Array();

  Float32Array asFloat32Array();

  Float64Array asFloat64Array();

  void SetJavaScriptThis(v8::Local<v8::Object> obj) {
    // Ignore this if you don't need it
    // Typical usage: emit an event on `obj`
  }

 private:
  Uint8Array rawBuffer_;

  int32_t length_;
};

#endif  // _FAKE_IMAGE_H_
