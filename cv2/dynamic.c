#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int (*f)(int, ...);

  void* dll = dlopen("libf.so", RTLD_NOW);

  if (!dll) {
    fprintf(stderr, "Chyba: %s\n", dlerror());
    exit(EXIT_FAILURE);
  }

  dlerror();

  f = dlsym(dll, "f");

  char* error = dlerror();
  if (error != NULL) {
    fprintf(stderr, "Chyba: %s\n", error);
    exit(EXIT_FAILURE);
  }

  printf("Max z 9, 4, 2: %d\n", f(3, 9, 4, 2));

  dlclose(dll);
  exit(EXIT_SUCCESS);
}
