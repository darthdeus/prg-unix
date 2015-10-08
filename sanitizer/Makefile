.PHONY: asan_test

SANITIZE=-fsanitize=address
CFLAGS=-std=c11 -Wall -Wextra -g

default: asan_test

asan_test: asan_test.c
	$(CC) $(CFLAGS) $(SANITIZE) $< -o $@
	./$@
