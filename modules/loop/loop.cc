
#include <sys/epoll.h>
#include <unistd.h>
#include <spin.h>

namespace spin {
namespace loop {

void createSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  Local<Context> context = isolate->GetCurrentContext();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  int32_t rc = epoll_create1(v0);
  args.GetReturnValue().Set(Integer::New(isolate, rc));
}  

int32_t createFast(void* p, int32_t p0) {
  int32_t v0 = p0;
  return epoll_create1(v0);
}

void modifySlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  Local<Context> context = isolate->GetCurrentContext();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  int32_t v2 = Local<Integer>::Cast(args[2])->Value();
  struct epoll_event * v3 = reinterpret_cast<struct epoll_event *>((uint64_t)args[3]->NumberValue(context).ToChecked());
  int32_t rc = epoll_ctl(v0, v1, v2, v3);
  args.GetReturnValue().Set(Integer::New(isolate, rc));
}  

int32_t modifyFast(void* p, int32_t p0, int32_t p1, int32_t p2, uint64_t p3) {
  int32_t v0 = p0;
  int32_t v1 = p1;
  int32_t v2 = p2;
  struct epoll_event * v3 = reinterpret_cast<struct epoll_event *>(p3);
  return epoll_ctl(v0, v1, v2, v3);
}

void waitSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  Local<Context> context = isolate->GetCurrentContext();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  struct epoll_event * v1 = reinterpret_cast<struct epoll_event *>((uint64_t)args[1]->NumberValue(context).ToChecked());
  int32_t v2 = Local<Integer>::Cast(args[2])->Value();
  int32_t v3 = Local<Integer>::Cast(args[3])->Value();
  int32_t rc = epoll_wait(v0, v1, v2, v3);
  args.GetReturnValue().Set(Integer::New(isolate, rc));
}  

int32_t waitFast(void* p, int32_t p0, uint64_t p1, int32_t p2, int32_t p3) {
  int32_t v0 = p0;
  struct epoll_event * v1 = reinterpret_cast<struct epoll_event *>(p1);
  int32_t v2 = p2;
  int32_t v3 = p3;
  return epoll_wait(v0, v1, v2, v3);
}

void closeSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  Local<Context> context = isolate->GetCurrentContext();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  int32_t rc = close(v0);
  args.GetReturnValue().Set(Integer::New(isolate, rc));
}  

int32_t closeFast(void* p, int32_t p0) {
  int32_t v0 = p0;
  return close(v0);
}

void Init(Isolate* isolate, Local<ObjectTemplate> target) {
  Local<ObjectTemplate> module = ObjectTemplate::New(isolate);

  v8::CTypeInfo* cargscreate = (v8::CTypeInfo*)calloc(8, sizeof(v8::CTypeInfo));
  cargscreate[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargscreate[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CTypeInfo* rccreate = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infocreate = new v8::CFunctionInfo(*rccreate, 2, cargscreate);
  v8::CFunction* pFcreate = new v8::CFunction((const void*)&createFast, infocreate);
  SET_FAST_METHOD(isolate, module, "create", pFcreate, createSlow);

  v8::CTypeInfo* cargsmodify = (v8::CTypeInfo*)calloc(8, sizeof(v8::CTypeInfo));
  cargsmodify[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargsmodify[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargsmodify[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargsmodify[3] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargsmodify[4] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CTypeInfo* rcmodify = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infomodify = new v8::CFunctionInfo(*rcmodify, 5, cargsmodify);
  v8::CFunction* pFmodify = new v8::CFunction((const void*)&modifyFast, infomodify);
  SET_FAST_METHOD(isolate, module, "modify", pFmodify, modifySlow);

  v8::CTypeInfo* cargswait = (v8::CTypeInfo*)calloc(8, sizeof(v8::CTypeInfo));
  cargswait[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargswait[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargswait[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  cargswait[3] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargswait[4] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CTypeInfo* rcwait = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infowait = new v8::CFunctionInfo(*rcwait, 5, cargswait);
  v8::CFunction* pFwait = new v8::CFunction((const void*)&waitFast, infowait);
  SET_FAST_METHOD(isolate, module, "wait", pFwait, waitSlow);

  v8::CTypeInfo* cargsclose = (v8::CTypeInfo*)calloc(8, sizeof(v8::CTypeInfo));
  cargsclose[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargsclose[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CTypeInfo* rcclose = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infoclose = new v8::CFunctionInfo(*rcclose, 2, cargsclose);
  v8::CFunction* pFclose = new v8::CFunction((const void*)&closeFast, infoclose);
  SET_FAST_METHOD(isolate, module, "close", pFclose, closeSlow);
  SET_MODULE(isolate, target, "loop", module);
}
} // namespace loop
} // namespace spin

extern "C" {
  void* _register_loop() {
    return (void*)spin::loop::Init;
  }
}


