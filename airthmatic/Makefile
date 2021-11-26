CC = gcc
all : projbin

projbin : add.o sub.o main.o
	$(CC) -o projbin main.o add.o sub.o

main.o : main.c
	$(CC) -c -o main.o main.c

add.o : add.c
	$(CC) -c -o add.o add.c

sub.o : sub.c
	$(CC) -c -o sub.o sub.c

clear:
		rm -rf *.o projbin