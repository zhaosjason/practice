CC = gcc
CFLAGS = -Wall -g

main: main.o hashtable.o
	$(CC) $(CFLAGS) main.o hashtable.o -o main

main.o: hashtable.h

hashtable.o: hashtable.h

clean:
	rm *.o main

all: clean main

