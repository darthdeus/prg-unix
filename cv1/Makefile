SANITIZE=-fsanitize=address
SANITIZE=

CFLAGS=-std=gnu11 -Wall -Wextra -g3 -O0
LIBS=

.PHONY: ex1
default: ex1

CC=clang

ex1:
	$(CC) $(CFLAGS) ex1.c -o ex1
	./ex1 < test.in

clean:
	rm -f -- ex1.o ex1
