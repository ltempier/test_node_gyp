// hello.cc
#include <node.h>

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Number;
using v8::Value;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  long int result = 0;
  long int max = args[0]->NumberValue();

  for( long int a = 0; a < max; a = a + 1 ) {
        if(a%2)
            result += 1;
  }

  Local<Number> num = Number::New(isolate, result);
  args.GetReturnValue().Set(num);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "test", Method);
  NODE_SET_METHOD(exports, "otherTest", Method);
}

NODE_MODULE(addon, init)

}  // namespace demo
