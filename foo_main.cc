#include <dlfcn.h>

#include <iostream>
#include <string>

void call_foo(const std::string &_libraryName)
{
  void *handle = dlopen(_libraryName.c_str(), RTLD_LAZY);
  if (!handle) {
    std::cerr << "Cannot open library: " << dlerror() << std::endl;
    return;
  }

  typedef void (*foo_t)();
  foo_t foo = (foo_t) dlsym(handle, "foo");
  const char *dlsym_error = dlerror();
  if (dlsym_error) {
    std::cerr << "Cannot load symbol 'hello': " << dlsym_error << std::endl;
    dlclose(handle);
    return;
  }
  foo();
  dlclose(handle);
}


int main(int argc, char** argv)
{
  call_foo("./lib1/liblib1.so");
  call_foo("./lib2/liblib2.so");
}
