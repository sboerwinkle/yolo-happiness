CC = g++
CFLAGS = -O0 -g -Wall 
LFLAGS = -lSDL

.PHONY: clean

game: main.o 
	$(CC) $(CFLAGS) $(LFLAGS) main.o -o game

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
	
clean:
	rm -rf ./*.o game
