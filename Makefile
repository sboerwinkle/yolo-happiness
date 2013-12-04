
CC = g++
CFLAGS = -O0 -g -Wall 

game: main.o 
	$(CC) $(CFLAGS) main.o -o game

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
	
clean:
	rm -rf ./*.o game
