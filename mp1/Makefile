CC = clang++
CFLAGS = -g -Wall

default: p_find

p_find: main.o a_star.o algorithm.o
	$(CC) $(CFLAGS) main.o a_star.o algorithm.o -o p_find

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

a_star.o: a_star.cpp a_star.h
	$(CC) $(CFLAGS) -c a_star.cpp
	
algorithm.o: algorithm.cpp algorithm.h
	$(CC) $(CFLAGS) -c algorithm.cpp

clean:
	-rm -f *.o