#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv) {
  int i = 2;
  while (i--) {
    int res = getopt(argc, argv, "af:");

    if (res < 0) {
      printf("chyba %d %d\n", res, opterr);
      perror(strerror(opterr));
      break;
    } else {
      printf("res=%d (%c): %c %s\n", res, (char)res, optopt, optarg);
    }
  }
}
