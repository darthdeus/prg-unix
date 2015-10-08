#include <stdlib.h>
#include <stdio.h>

int main() {
  char* buffer = (char*)malloc(10);

  buffer[0] = 3;
  buffer[10] = 4;
  return 0;
}
