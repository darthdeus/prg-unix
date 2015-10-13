#include <unistd.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main() {
  int fd = open("foo.txt", O_RDWR | O_CREAT | O_APPEND);

  if (fd == -1)
    fatal("open()");

}
