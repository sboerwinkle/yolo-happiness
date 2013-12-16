CC = g++
CFLAGS = -O0 -g -Wall 
LFLAGS = -lSDL -lm

.PHONY: clean windows

game: main.o math.o board.o pieces.o
	$(CC) $(CFLAGS) board.o pieces.o math.o main.o -o game $(WFLAGS) $(LFLAGS) 

windows:
	$(MAKE) WFLAGS="-lmingw32 -lSDLmain -lSDL -mwindows -o game.exe"

main.o: main.cpp board.hpp pieces.hpp
	$(CC) $(CFLAGS) -c main.cpp

math.o: math.cpp
	$(CC) $(CFLAGS) -c math.cpp
board.o: board.cpp board.hpp pieces.hpp
	$(CC) $(CFLAGS) -c board.cpp
pieces.o: pieces.cpp pieces.hpp board.hpp
	$(CC) $(CFLAGS) -c pieces.cpp
clean:
	rm -rf ./*.o game
