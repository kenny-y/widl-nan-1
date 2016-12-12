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

Int8ArrayHelper FakeImage::asInt8Array() {
  // TODO(widl-nan): fill your code here
}

Uint8ArrayHelper FakeImage::asUin86Array() {
  // TODO(widl-nan): fill your code here
}

Uint8ClampedArrayHelper FakeImage::asUint8ClampedArray() {
  // TODO(widl-nan): fill your code here
}

Int16ArrayHelper FakeImage::asInt16Array() {
  // TODO(widl-nan): fill your code here
}

Uint16ArrayHelper FakeImage::asUint16Array() {
  // TODO(widl-nan): fill your code here
}

Int32ArrayHelper FakeImage::asInt32Array() {
  // TODO(widl-nan): fill your code here
}

Uint32ArrayHelper FakeImage::asUint32Array() {
  // TODO(widl-nan): fill your code here
}

Float32ArrayHelper FakeImage::asFloat32Array() {
  // TODO(widl-nan): fill your code here
}

Float64ArrayHelper FakeImage::asFloat64Array() {
  // TODO(widl-nan): fill your code here
}

Float32ArrayHelper FakeImage::getStaticArray() {
  // TODO(widl-nan): fill your code here
}
