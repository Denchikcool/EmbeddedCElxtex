CC=gcc

all: task1 task2 task3 task4

task1: task1.o
	$(CC) task1.o -o task1
task1.o: task1.c
	$(CC) -c task1.c
task2: task2.o
	$(CC) task2.o -o task2
task2.o: task2.c
	$(CC) -c task2.c
task3: task3.o
	$(CC) task3.o -o task3
task3.o: task3.c
	$(CC) -c task3.c
task4: task4.o
	$(CC) task4.o -o task4
task4.o: task4.c
	$(CC) -c task4.c
	
clean:
	rm -f task1 task2 task3 task4 *.o
