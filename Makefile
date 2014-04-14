CFLAGS=-Wall -g

all: ex19
	cc ex1.c -o ex1
	cc ex3.c -o ex3

ex19: object.o

clean:
	rm -f ex1 ex3 ex19 object.o

