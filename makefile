cc = gcc
cflags = -std=c99 -pedantic -Wall -g
srcpath = ./src/
outputpath = ./bin/

main:
	$(cc) $(cflags) $(srcpath)main.c $(srcpath)BSTApi.c -Iinclude -o $(outputpath)program

test:

	$(CC) $(CFLAGS) bin/BinarySearchTreeAPI.o src/BinarySearchTreeAPI.c
	$(CC) $(CFLAGS) bin/testMain.o src/testMain.c
	$(CC) $(CFLAGS) bin/Rule.o src/Rule.c
	$(CC) bin/testMain.o bin/BinarySearchTreeAPI.o bin/Rule.o -o bin/runMe

run:
	clear; $(outputpath)program ./assets/input.txt


remove:
	rm $(outputpath)