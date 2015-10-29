.PHONY: main dynamc libf.so

CFLAGS=-fPIC -Wall -Wextra -g3

default: dynamic

libf.so: varargs.c
	gcc $(CFLAGS) -shared -o libf.so varargs.c

main: main.c libf.so
	gcc $(CFLAGS) main.c -c -o main.o
	ld -R. -lf -L. -lc main.o -o main

	./main

dynamic: dynamic.c libf.so
	gcc $(CFLAGS) -ldl dynamic.c -o dynamic

clean:
	rm -f -- *.so *.o
