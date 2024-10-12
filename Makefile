CC=gcc
CFLAGS=-O3 -Wall

OBJECTS=src/quicksort.o src/selection.o src/utilities.o

.PHONY: clean

all: compile
	./main

compile: $(src/main.o)
	$(CC) $(CFLAGS) src/main.c -o main

clean:
	rm -f src/*.o main