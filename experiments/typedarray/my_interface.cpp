// To add your copyright and license header

#include "my_interface.h"

MyInterface::MyInterface() {
  data_ = new int8_t[1024];
  for (int i = 0 ; i < 1024 ; ++ i) {
    if (i % 2 == 1) {
      data_[i] = 0xAA;
    } else {
      data_[i] = 0x55;
    }
  }
  length_ = 1024;
}

MyInterface::MyInterface(const MyInterface& rhs) {
  // TODO(widl-nan): copy from rhs if you want this behavior
  // Or mark ctor = delete in my_interface.h
}

MyInterface::~MyInterface() {
  // TODO(widl-nan): do cleanup if necessary
}

MyInterface& MyInterface::operator = (const MyInterface& rhs) {
  if (&rhs != this) {
    // TODO(widl-nan): copy members from rhs
  }
  return *this;
}

void MyInterface::setData(const int32_t& offset, const int8_t& data) {
  data_[offset] = data;
}

int8_t MyInterface::getData(const int32_t& offset) {
  return data_[offset];
}

HelperType MyInterface::asInt8Array() {
  auto ret = HelperType(data_, 0, length_);
  auto array(ret);
  array = ret;
  if (array == ret) {
    return array;
  }
  return array;
}
