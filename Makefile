.PHONY: tsan_test

# TODO - test tsan with posix threads
# SANITIZE=-fsanitize=thread
# SANITIZE=-fsanitize=address

CFLAGS=-std=c11 -Wall -Wextra -g
LIBS=-lpthread

default: tsan_test

tsan_test: tsan_test.o
	$(CC) $(LIBS) $(SANITIZE) $< -o $@
	./bin/$@

vg_test: vg_test.o
	$(CC) $(LIBS) $< -o bin/$@
	valgrind ./bin/$@

	


