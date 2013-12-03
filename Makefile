CC = g++
CFLAGS = -O2 -Wall -g
LFLAGS = -lSDL

.PHONY: clean
run: main.cpp
	$(CC) $(CFLAGS) $(LFLAGS) -o run main.cpp

clean:
	rm -f run
