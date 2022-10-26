#include <sys/times.h>
#include <sys/resource.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/timerfd.h>
#include <sys/wait.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <spin.h>

namespace spin {
namespace system {

void clock_gettimeSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  timespec* v1 = reinterpret_cast<timespec*>((uint64_t)args[1]->NumberValue(context).ToChecked());
  int32_t rc = clock_gettime(v0, v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t clock_gettimeFast(void* p, int32_t p0, void* p1) {
  int32_t v0 = p0;
  timespec* v1 = reinterpret_cast<timespec*>(p1);
  return clock_gettime(v0, v1);
}

void exitSlow(const FunctionCallbackInfo<Value> &args) {
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  exit(v0);
}

void exitFast(void* p, int32_t p0, struct FastApiTypedArray* const p_ret) {
  int32_t v0 = p0;
  exit(v0);
}

void usleepSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  uint32_t v0 = Local<Integer>::Cast(args[0])->Value();
  int32_t rc = usleep(v0);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t usleepFast(void* p, uint32_t p0) {
  uint32_t v0 = p0;
  return usleep(v0);
}

void getpidSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  uint32_t rc = getpid();
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

uint32_t getpidFast(void* p) {

  return getpid();
}

void getrusageSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  struct rusage* v1 = reinterpret_cast<struct rusage*>((uint64_t)args[1]->NumberValue(context).ToChecked());
  int32_t rc = getrusage(v0, v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t getrusageFast(void* p, int32_t p0, void* p1) {
  int32_t v0 = p0;
  struct rusage* v1 = reinterpret_cast<struct rusage*>(p1);
  return getrusage(v0, v1);
}

void dlopenSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  const char* v0 = reinterpret_cast<const char*>((uint64_t)args[0]->NumberValue(context).ToChecked());
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  void* rc = dlopen(v0, v1);
  args.GetReturnValue().Set(Number::New(isolate, reinterpret_cast<uint64_t>(rc)));
}

void dlopenFast(void* p, void* p0, int32_t p1, struct FastApiTypedArray* const p_ret) {
  const char* v0 = reinterpret_cast<const char*>(p0);
  int32_t v1 = p1;
  void* r = dlopen(v0, v1);
  ((void**)p_ret->data)[0] = r;

}

void dlsymSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  void* v0 = reinterpret_cast<void*>((uint64_t)args[0]->NumberValue(context).ToChecked());
  const char* v1 = reinterpret_cast<const char*>((uint64_t)args[1]->NumberValue(context).ToChecked());
  void* rc = dlsym(v0, v1);
  args.GetReturnValue().Set(Number::New(isolate, reinterpret_cast<uint64_t>(rc)));
}

void dlsymFast(void* p, void* p0, void* p1, struct FastApiTypedArray* const p_ret) {
  void* v0 = reinterpret_cast<void*>(p0);
  const char* v1 = reinterpret_cast<const char*>(p1);
  void* r = dlsym(v0, v1);
  ((void**)p_ret->data)[0] = r;

}

void dlcloseSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  void* v0 = reinterpret_cast<void*>((uint64_t)args[0]->NumberValue(context).ToChecked());
  int32_t rc = dlclose(v0);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t dlcloseFast(void* p, void* p0) {
  void* v0 = reinterpret_cast<void*>(p0);
  return dlclose(v0);
}

void timerfd_createSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  int32_t rc = timerfd_create(v0, v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t timerfd_createFast(void* p, int32_t p0, int32_t p1) {
  int32_t v0 = p0;
  int32_t v1 = p1;
  return timerfd_create(v0, v1);
}

void sleepSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  uint32_t v0 = Local<Integer>::Cast(args[0])->Value();
  uint32_t rc = sleep(v0);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

uint32_t sleepFast(void* p, uint32_t p0) {
  uint32_t v0 = p0;
  return sleep(v0);
}

void timerfd_settimeSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  const struct itimerspec* v2 = reinterpret_cast<const struct itimerspec*>((uint64_t)args[2]->NumberValue(context).ToChecked());
  struct itimerspec* v3 = reinterpret_cast<struct itimerspec*>((uint64_t)args[3]->NumberValue(context).ToChecked());
  int32_t rc = timerfd_settime(v0, v1, v2, v3);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t timerfd_settimeFast(void* p, int32_t p0, int32_t p1, void* p2, void* p3) {
  int32_t v0 = p0;
  int32_t v1 = p1;
  const struct itimerspec* v2 = reinterpret_cast<const struct itimerspec*>(p2);
  struct itimerspec* v3 = reinterpret_cast<struct itimerspec*>(p3);
  return timerfd_settime(v0, v1, v2, v3);
}

void forkSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  int32_t rc = fork();
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t forkFast(void* p) {

  return fork();
}

void waitpidSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  int* v1 = reinterpret_cast<int*>((uint64_t)args[1]->NumberValue(context).ToChecked());
  int32_t v2 = Local<Integer>::Cast(args[2])->Value();
  int32_t rc = waitpid(v0, v1, v2);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t waitpidFast(void* p, int32_t p0, void* p1, int32_t p2) {
  int32_t v0 = p0;
  int* v1 = reinterpret_cast<int*>(p1);
  int32_t v2 = p2;
  return waitpid(v0, v1, v2);
}

void execvpSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  char* v0 = reinterpret_cast<char*>((uint64_t)args[0]->NumberValue(context).ToChecked());
  char* const* v1 = reinterpret_cast<char* const*>((uint64_t)args[1]->NumberValue(context).ToChecked());
  int32_t rc = execvp(v0, v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t execvpFast(void* p, void* p0, void* p1) {
  char* v0 = reinterpret_cast<char*>(p0);
  char* const* v1 = reinterpret_cast<char* const*>(p1);
  return execvp(v0, v1);
}

void sysconfSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  uint32_t rc = sysconf(v0);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

uint32_t sysconfFast(void* p, int32_t p0) {
  int32_t v0 = p0;
  return sysconf(v0);
}

void pidfd_openSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  uint32_t v2 = Local<Integer>::Cast(args[2])->Value();
  int32_t rc = syscall(v0, v1, v2);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t pidfd_openFast(void* p, int32_t p0, int32_t p1, uint32_t p2) {
  int32_t v0 = p0;
  int32_t v1 = p1;
  uint32_t v2 = p2;
  return syscall(v0, v1, v2);
}

void getrlimitSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  struct rlimit* v1 = reinterpret_cast<struct rlimit*>((uint64_t)args[1]->NumberValue(context).ToChecked());
  int32_t rc = getrlimit(v0, v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t getrlimitFast(void* p, int32_t p0, void* p1) {
  int32_t v0 = p0;
  struct rlimit* v1 = reinterpret_cast<struct rlimit*>(p1);
  return getrlimit(v0, v1);
}

void setrlimitSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  const struct rlimit* v1 = reinterpret_cast<const struct rlimit*>((uint64_t)args[1]->NumberValue(context).ToChecked());
  int32_t rc = setrlimit(v0, v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t setrlimitFast(void* p, int32_t p0, void* p1) {
  int32_t v0 = p0;
  const struct rlimit* v1 = reinterpret_cast<const struct rlimit*>(p1);
  return setrlimit(v0, v1);
}

void strerror_rSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  char* v1 = reinterpret_cast<char*>((uint64_t)args[1]->NumberValue(context).ToChecked());
  uint32_t v2 = Local<Integer>::Cast(args[2])->Value();
  int32_t rc = strerror_r(v0, v1, v2);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t strerror_rFast(void* p, int32_t p0, void* p1, uint32_t p2) {
  int32_t v0 = p0;
  char* v1 = reinterpret_cast<char*>(p1);
  uint32_t v2 = p2;
  return strerror_r(v0, v1, v2);
}

void timesSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  struct tms* v0 = reinterpret_cast<struct tms*>((uint64_t)args[0]->NumberValue(context).ToChecked());
  int32_t rc = times(v0);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t timesFast(void* p, void* p0) {
  struct tms* v0 = reinterpret_cast<struct tms*>(p0);
  return times(v0);
}

void get_avphys_pagesSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  uint32_t rc = get_avphys_pages();
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

uint32_t get_avphys_pagesFast(void* p) {

  return get_avphys_pages();
}

void signalSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  sighandler_t v1 = reinterpret_cast<sighandler_t>((uint64_t)args[1]->NumberValue(context).ToChecked());
  sighandler_t rc = signal(v0, v1);
  args.GetReturnValue().Set(Number::New(isolate, reinterpret_cast<uint64_t>(rc)));
}

void signalFast(void* p, int32_t p0, void* p1, struct FastApiTypedArray* const p_ret) {
  int32_t v0 = p0;
  sighandler_t v1 = reinterpret_cast<sighandler_t>(p1);
  sighandler_t r = signal(v0, v1);
  ((sighandler_t*)p_ret->data)[0] = r;

}

void Init(Isolate* isolate, Local<ObjectTemplate> target) {
  Local<ObjectTemplate> module = ObjectTemplate::New(isolate);

  v8::CTypeInfo* cargsclock_gettime = (v8::CTypeInfo*)calloc(3, sizeof(v8::CTypeInfo));
  cargsclock_gettime[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargsclock_gettime[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargsclock_gettime[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CTypeInfo* rcclock_gettime = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infoclock_gettime = new v8::CFunctionInfo(*rcclock_gettime, 3, cargsclock_gettime);
  v8::CFunction* pFclock_gettime = new v8::CFunction((const void*)&clock_gettimeFast, infoclock_gettime);
  SET_FAST_METHOD(isolate, module, "clock_gettime", pFclock_gettime, clock_gettimeSlow);

  v8::CTypeInfo* cargsexit = (v8::CTypeInfo*)calloc(2, sizeof(v8::CTypeInfo));
  cargsexit[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargsexit[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CTypeInfo* rcexit = new v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
  v8::CFunctionInfo* infoexit = new v8::CFunctionInfo(*rcexit, 2, cargsexit);
  v8::CFunction* pFexit = new v8::CFunction((const void*)&exitFast, infoexit);
  SET_FAST_METHOD(isolate, module, "exit", pFexit, exitSlow);

  v8::CTypeInfo* cargsusleep = (v8::CTypeInfo*)calloc(2, sizeof(v8::CTypeInfo));
  cargsusleep[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargsusleep[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint32);
  v8::CTypeInfo* rcusleep = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infousleep = new v8::CFunctionInfo(*rcusleep, 2, cargsusleep);
  v8::CFunction* pFusleep = new v8::CFunction((const void*)&usleepFast, infousleep);
  SET_FAST_METHOD(isolate, module, "usleep", pFusleep, usleepSlow);

  v8::CTypeInfo* cargsgetpid = (v8::CTypeInfo*)calloc(1, sizeof(v8::CTypeInfo));
  cargsgetpid[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);

  v8::CTypeInfo* rcgetpid = new v8::CTypeInfo(v8::CTypeInfo::Type::kUint32);
  v8::CFunctionInfo* infogetpid = new v8::CFunctionInfo(*rcgetpid, 1, cargsgetpid);
  v8::CFunction* pFgetpid = new v8::CFunction((const void*)&getpidFast, infogetpid);
  SET_FAST_METHOD(isolate, module, "getpid", pFgetpid, getpidSlow);

  v8::CTypeInfo* cargsgetrusage = (v8::CTypeInfo*)calloc(3, sizeof(v8::CTypeInfo));
  cargsgetrusage[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargsgetrusage[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargsgetrusage[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CTypeInfo* rcgetrusage = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infogetrusage = new v8::CFunctionInfo(*rcgetrusage, 3, cargsgetrusage);
  v8::CFunction* pFgetrusage = new v8::CFunction((const void*)&getrusageFast, infogetrusage);
  SET_FAST_METHOD(isolate, module, "getrusage", pFgetrusage, getrusageSlow);

  v8::CTypeInfo* cargsdlopen = (v8::CTypeInfo*)calloc(3, sizeof(v8::CTypeInfo));
  cargsdlopen[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargsdlopen[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  cargsdlopen[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CTypeInfo* rcdlopen = new v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CFunctionInfo* infodlopen = new v8::CFunctionInfo(*rcdlopen, 3, cargsdlopen);
  v8::CFunction* pFdlopen = new v8::CFunction((const void*)&dlopenFast, infodlopen);
  SET_FAST_METHOD(isolate, module, "dlopen", pFdlopen, dlopenSlow);

  v8::CTypeInfo* cargsdlsym = (v8::CTypeInfo*)calloc(3, sizeof(v8::CTypeInfo));
  cargsdlsym[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargsdlsym[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  cargsdlsym[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CTypeInfo* rcdlsym = new v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CFunctionInfo* infodlsym = new v8::CFunctionInfo(*rcdlsym, 3, cargsdlsym);
  v8::CFunction* pFdlsym = new v8::CFunction((const void*)&dlsymFast, infodlsym);
  SET_FAST_METHOD(isolate, module, "dlsym", pFdlsym, dlsymSlow);

  v8::CTypeInfo* cargsdlclose = (v8::CTypeInfo*)calloc(2, sizeof(v8::CTypeInfo));
  cargsdlclose[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargsdlclose[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CTypeInfo* rcdlclose = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infodlclose = new v8::CFunctionInfo(*rcdlclose, 2, cargsdlclose);
  v8::CFunction* pFdlclose = new v8::CFunction((const void*)&dlcloseFast, infodlclose);
  SET_FAST_METHOD(isolate, module, "dlclose", pFdlclose, dlcloseSlow);

  v8::CTypeInfo* cargstimerfd_create = (v8::CTypeInfo*)calloc(3, sizeof(v8::CTypeInfo));
  cargstimerfd_create[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargstimerfd_create[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargstimerfd_create[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CTypeInfo* rctimerfd_create = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infotimerfd_create = new v8::CFunctionInfo(*rctimerfd_create, 3, cargstimerfd_create);
  v8::CFunction* pFtimerfd_create = new v8::CFunction((const void*)&timerfd_createFast, infotimerfd_create);
  SET_FAST_METHOD(isolate, module, "timerfd_create", pFtimerfd_create, timerfd_createSlow);

  v8::CTypeInfo* cargssleep = (v8::CTypeInfo*)calloc(2, sizeof(v8::CTypeInfo));
  cargssleep[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargssleep[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint32);
  v8::CTypeInfo* rcsleep = new v8::CTypeInfo(v8::CTypeInfo::Type::kUint32);
  v8::CFunctionInfo* infosleep = new v8::CFunctionInfo(*rcsleep, 2, cargssleep);
  v8::CFunction* pFsleep = new v8::CFunction((const void*)&sleepFast, infosleep);
  SET_FAST_METHOD(isolate, module, "sleep", pFsleep, sleepSlow);

  v8::CTypeInfo* cargstimerfd_settime = (v8::CTypeInfo*)calloc(5, sizeof(v8::CTypeInfo));
  cargstimerfd_settime[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargstimerfd_settime[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargstimerfd_settime[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargstimerfd_settime[3] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  cargstimerfd_settime[4] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CTypeInfo* rctimerfd_settime = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infotimerfd_settime = new v8::CFunctionInfo(*rctimerfd_settime, 5, cargstimerfd_settime);
  v8::CFunction* pFtimerfd_settime = new v8::CFunction((const void*)&timerfd_settimeFast, infotimerfd_settime);
  SET_FAST_METHOD(isolate, module, "timerfd_settime", pFtimerfd_settime, timerfd_settimeSlow);

  v8::CTypeInfo* cargsfork = (v8::CTypeInfo*)calloc(1, sizeof(v8::CTypeInfo));
  cargsfork[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);

  v8::CTypeInfo* rcfork = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infofork = new v8::CFunctionInfo(*rcfork, 1, cargsfork);
  v8::CFunction* pFfork = new v8::CFunction((const void*)&forkFast, infofork);
  SET_FAST_METHOD(isolate, module, "fork", pFfork, forkSlow);

  v8::CTypeInfo* cargswaitpid = (v8::CTypeInfo*)calloc(4, sizeof(v8::CTypeInfo));
  cargswaitpid[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargswaitpid[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargswaitpid[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  cargswaitpid[3] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CTypeInfo* rcwaitpid = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infowaitpid = new v8::CFunctionInfo(*rcwaitpid, 4, cargswaitpid);
  v8::CFunction* pFwaitpid = new v8::CFunction((const void*)&waitpidFast, infowaitpid);
  SET_FAST_METHOD(isolate, module, "waitpid", pFwaitpid, waitpidSlow);

  v8::CTypeInfo* cargsexecvp = (v8::CTypeInfo*)calloc(3, sizeof(v8::CTypeInfo));
  cargsexecvp[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargsexecvp[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  cargsexecvp[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CTypeInfo* rcexecvp = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infoexecvp = new v8::CFunctionInfo(*rcexecvp, 3, cargsexecvp);
  v8::CFunction* pFexecvp = new v8::CFunction((const void*)&execvpFast, infoexecvp);
  SET_FAST_METHOD(isolate, module, "execvp", pFexecvp, execvpSlow);

  v8::CTypeInfo* cargssysconf = (v8::CTypeInfo*)calloc(2, sizeof(v8::CTypeInfo));
  cargssysconf[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargssysconf[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CTypeInfo* rcsysconf = new v8::CTypeInfo(v8::CTypeInfo::Type::kUint32);
  v8::CFunctionInfo* infosysconf = new v8::CFunctionInfo(*rcsysconf, 2, cargssysconf);
  v8::CFunction* pFsysconf = new v8::CFunction((const void*)&sysconfFast, infosysconf);
  SET_FAST_METHOD(isolate, module, "sysconf", pFsysconf, sysconfSlow);

  v8::CTypeInfo* cargspidfd_open = (v8::CTypeInfo*)calloc(4, sizeof(v8::CTypeInfo));
  cargspidfd_open[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargspidfd_open[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargspidfd_open[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargspidfd_open[3] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint32);
  v8::CTypeInfo* rcpidfd_open = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infopidfd_open = new v8::CFunctionInfo(*rcpidfd_open, 4, cargspidfd_open);
  v8::CFunction* pFpidfd_open = new v8::CFunction((const void*)&pidfd_openFast, infopidfd_open);
  SET_FAST_METHOD(isolate, module, "pidfd_open", pFpidfd_open, pidfd_openSlow);

  v8::CTypeInfo* cargsgetrlimit = (v8::CTypeInfo*)calloc(3, sizeof(v8::CTypeInfo));
  cargsgetrlimit[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargsgetrlimit[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargsgetrlimit[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CTypeInfo* rcgetrlimit = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infogetrlimit = new v8::CFunctionInfo(*rcgetrlimit, 3, cargsgetrlimit);
  v8::CFunction* pFgetrlimit = new v8::CFunction((const void*)&getrlimitFast, infogetrlimit);
  SET_FAST_METHOD(isolate, module, "getrlimit", pFgetrlimit, getrlimitSlow);

  v8::CTypeInfo* cargssetrlimit = (v8::CTypeInfo*)calloc(3, sizeof(v8::CTypeInfo));
  cargssetrlimit[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargssetrlimit[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargssetrlimit[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CTypeInfo* rcsetrlimit = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infosetrlimit = new v8::CFunctionInfo(*rcsetrlimit, 3, cargssetrlimit);
  v8::CFunction* pFsetrlimit = new v8::CFunction((const void*)&setrlimitFast, infosetrlimit);
  SET_FAST_METHOD(isolate, module, "setrlimit", pFsetrlimit, setrlimitSlow);

  v8::CTypeInfo* cargsstrerror_r = (v8::CTypeInfo*)calloc(4, sizeof(v8::CTypeInfo));
  cargsstrerror_r[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargsstrerror_r[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargsstrerror_r[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  cargsstrerror_r[3] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint32);
  v8::CTypeInfo* rcstrerror_r = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infostrerror_r = new v8::CFunctionInfo(*rcstrerror_r, 4, cargsstrerror_r);
  v8::CFunction* pFstrerror_r = new v8::CFunction((const void*)&strerror_rFast, infostrerror_r);
  SET_FAST_METHOD(isolate, module, "strerror_r", pFstrerror_r, strerror_rSlow);

  v8::CTypeInfo* cargstimes = (v8::CTypeInfo*)calloc(2, sizeof(v8::CTypeInfo));
  cargstimes[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargstimes[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CTypeInfo* rctimes = new v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  v8::CFunctionInfo* infotimes = new v8::CFunctionInfo(*rctimes, 2, cargstimes);
  v8::CFunction* pFtimes = new v8::CFunction((const void*)&timesFast, infotimes);
  SET_FAST_METHOD(isolate, module, "times", pFtimes, timesSlow);

  v8::CTypeInfo* cargsget_avphys_pages = (v8::CTypeInfo*)calloc(1, sizeof(v8::CTypeInfo));
  cargsget_avphys_pages[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);

  v8::CTypeInfo* rcget_avphys_pages = new v8::CTypeInfo(v8::CTypeInfo::Type::kUint32);
  v8::CFunctionInfo* infoget_avphys_pages = new v8::CFunctionInfo(*rcget_avphys_pages, 1, cargsget_avphys_pages);
  v8::CFunction* pFget_avphys_pages = new v8::CFunction((const void*)&get_avphys_pagesFast, infoget_avphys_pages);
  SET_FAST_METHOD(isolate, module, "get_avphys_pages", pFget_avphys_pages, get_avphys_pagesSlow);

  v8::CTypeInfo* cargssignal = (v8::CTypeInfo*)calloc(3, sizeof(v8::CTypeInfo));
  cargssignal[0] = v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value);
  cargssignal[1] = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
  cargssignal[2] = v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CTypeInfo* rcsignal = new v8::CTypeInfo(v8::CTypeInfo::Type::kUint64);
  v8::CFunctionInfo* infosignal = new v8::CFunctionInfo(*rcsignal, 3, cargssignal);
  v8::CFunction* pFsignal = new v8::CFunction((const void*)&signalFast, infosignal);
  SET_FAST_METHOD(isolate, module, "signal", pFsignal, signalSlow);
  SET_MODULE(isolate, target, "system", module);
}
} // namespace system
} // namespace spin

extern "C" {
  void* _register_system() {
    return (void*)spin::system::Init;
  }
}
