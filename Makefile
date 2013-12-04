CC = g++
CFLAGS = -O0 -g -Wall 
LFLAGS = -lSDL -lm

.PHONY: clean

game: main.o math.o board.o pieces.o
	$(CC) $(CFLAGS) $(LFLAGS) board.o pieces.o math.o main.o -o game

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

math.o: math.cpp
	$(CC) $(CFLAGS) -c math.cpp
board.o: board.cpp
	$(CC) $(CFLAGS) -c board.cpp
pieces.o: pieces.cpp
	$(CC) $(CFLAGS) -c pieces.cpp
clean:
	rm -rf ./*.o game
