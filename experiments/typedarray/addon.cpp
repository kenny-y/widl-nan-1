// Add your copyright and license header

#include "gen/nan__my_interface.h"

void initModule(v8::Local<v8::Object> exports) {
  NanMyInterface::Init(exports);

}

NODE_MODULE(testAttributes, initModule);
