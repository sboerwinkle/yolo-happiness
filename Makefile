CC = g++
CFLAGS = -O0 -g -Wall 
LFLAGS = -lSDL

.PHONY: clean

game: main.o math.o 	
	$(CC) $(CFLAGS) $(LFLAGS) math.o main.o -o game

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

math.o: math.cpp
	$(CC) $(CFLAGS) -c math.cpp
	
clean:
	rm -rf ./*.o game
