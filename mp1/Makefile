CC = clang++
CFLAGS = -g -Wall

default: p_find

p_find: main.o algorithm.o
	$(CC) $(CFLAGS) main.o algorithm.o -o p_find

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

algorithm.o: algorithm.cpp algorithm.h
	$(CC) $(CFLAGS) -c algorithm.cpp

clean:
	-rm -f *.o