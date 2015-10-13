.PHONY: tsan_test

# TODO - test tsan with posix threads
# SANITIZE=-fsanitize=thread
# SANITIZE=-fsanitize=address
#
SANITIZE=-fsanitize=address

CFLAGS=-std=c11 -Wall -Wextra -g3
LIBS=-lpthread

HELPERS=\
				error_functions.c \
				get_num.c \


.PHONY: opts
default: seek

tsan_test: tsan_test.o
	$(CC) $(LIBS) $(SANITIZE) $< -o $@
	./bin/$@

vg_test: vg_test.o
	$(CC) $(LIBS) $< -o bin/$@
	valgrind ./bin/$@

opts: opts.o
	$(CC) -lc $< -o $@
	./$@ -a -f 3

seek: seek.c
	$(CC) $(HELPERS) $< -o $@
	./$@
