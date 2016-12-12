// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <node.h>
#include <v8.h>

#include <string>

#include "gen/generator_helper.h"

class Buffer {
 public:
  Buffer();
  ~Buffer();

 public:
  ArrayBufferHelper getArrayBuffer() const;

  ArrayBufferHelper get_data() const {
    return getArrayBuffer();
  }

  void set_data(const ArrayBufferHelper& new_value) {
  }

  std::string buffer2String(const ArrayBufferHelper& arrayBuffer) {
    return std::string((const char*)arrayBuffer.GetData(),
      arrayBuffer.GetLength());
  }

  static ArrayBufferHelper getCommonData();

 private:
};

#endif  // _BUFFER_H_
