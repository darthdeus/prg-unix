.PHONY: main dynamc libf.so

CFLAGS=-fPIC -Wall -Wextra -g3

default: dynamic

libf.so: varargs.c
	gcc $(CFLAGS) -shared -o libf.so varargs.c

main: main.c libf.so
	gcc $(CFLAGS) -Wl,-rpath=$(PWD) -L. -lf main.c -o main

	./main

dynamic: dynamic.c libf.so
	gcc $(CFLAGS) -Wl,-rpath=$(PWD) -ldl dynamic.c -o dynamic

clean:
	rm -f -- *.so *.o
	rm -f dynamic libf.so
