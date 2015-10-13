#include <unistd.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

void sync(void);

int main() {
  int fd = open("foo.txt", O_RDWR | O_CREAT, 0644);

  if (fd == -1)
    err_exit("open()");

  char* buf = "hello";

  ssize_t count;

  count = write(fd, buf, sizeof(buf));
  if (count == -1)
    err_exit("write()");

  // This should create a hole
  if (lseek(fd, 200, SEEK_SET) == -1)
    err_exit("seek()");

  char* buf2 = "world";
  count = write(fd, buf2, sizeof(buf2));
  if (count == -1)
    err_exit("write()");

  if (close(fd) == -1)
    err_exit("close()");

  sync();

  int f2 = open("foo.txt", O_RDONLY);

#define READ_SIZE (200 + sizeof(buf) + sizeof(buf2))
  char rd_buf[READ_SIZE];
  int rd = read(f2, rd_buf, READ_SIZE);

  if (rd < READ_SIZE)
    printf("read only %d, instead of %d\n", rd, READ_SIZE);

  for (int i = 0; i < rd; ++i) {
    printf("%c", rd_buf[i]);
    if (i % 21 == 0) printf("\n");
  }

  close(f2);
}
