CC=gcc

all: main

main: main.o
	$(CC) main.o -o main
main.o: main.c
	$(CC) -c main.c
	
clean:
	rm -f main *.o
