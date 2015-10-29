#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>

#define TRUE 1
#define FALSE 0

int f(int n, ...) {
  va_list vl;
  va_start(vl, n);

  int loaded = FALSE;
  int max;
  while (n--) {
    int val = va_arg(vl, int);

    if (!loaded) {
      max = val;
      loaded = TRUE;
    } else {
      if (val > max) {
        max = val;
      }
    }
  }

  va_end(vl);

  return max;
}
