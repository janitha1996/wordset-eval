# Makefile for wordset project

CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = src/wordset.c
OUT = wordset

all: $(OUT)

wordset: src/wordset.o src/hashmap.o
	gcc -o wordset src/wordset.o src/hashmap.o

src/hashmap.o: src/hashmap.c src/hashmap.h
	gcc -c src/hashmap.c -o src/hashmap.o

src/wordset.o: src/wordset.c src/hashmap.h
	gcc -c src/wordset.c -o src/wordset.o

clean:
	rm -f src/*.o
	rm -f $(OUT)
