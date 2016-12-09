// To add your copyright and license header

#include "fake_image.h"

FakeImage::FakeImage() {
  // TODO(widl-nan): init your members
}

FakeImage::FakeImage(const FakeImage& rhs) {
  // TODO(widl-nan): copy from rhs if you want this behavior
  // Or mark ctor = delete in fake_image.h
}

FakeImage::~FakeImage() {
  // TODO(widl-nan): do cleanup if necessary
}

FakeImage& FakeImage::operator = (const FakeImage& rhs) {
  if (&rhs != this) {
    // TODO(widl-nan): copy members from rhs
  }
  return *this;
}

void FakeImage::setData(const int32_t& offset, const int8_t& data) {
  // TODO(widl-nan): fill your code here
}

int8_t FakeImage::getData(const int32_t& offset) {
  // TODO(widl-nan): fill your code here
}

Int8Array FakeImage::asInt8Array() {
  // TODO(widl-nan): fill your code here
}

Uint8Array FakeImage::asUin86Array() {
  // TODO(widl-nan): fill your code here
}

Uint8ClampedArray FakeImage::asUint8ClampedArray() {
  // TODO(widl-nan): fill your code here
}

Int16Array FakeImage::asInt16Array() {
  // TODO(widl-nan): fill your code here
}

Uint16Array FakeImage::asUint16Array() {
  // TODO(widl-nan): fill your code here
}

Int32Array FakeImage::asInt32Array() {
  // TODO(widl-nan): fill your code here
}

Uint32Array FakeImage::asUint16Array() {
  // TODO(widl-nan): fill your code here
}

Float32Array FakeImage::asFloat32Array() {
  // TODO(widl-nan): fill your code here
}

Float64Array FakeImage::asFloat64Array() {
  // TODO(widl-nan): fill your code here
}

