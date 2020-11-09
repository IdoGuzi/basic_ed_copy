CC=g++
CFLAGS=-Wall -g

all: run

run: main.o Editor.o Document.o
	$(CC) $(CFLAGS) -o run main.o Editor.o Document.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Editor.o: Editor.cpp Editor.h
	$(CC) $(CFLAGS) -c Editor.cpp

Document.o: Document.cpp Document.h
	$(CC) $(CFLAGS) -c Document.cpp

.PHONY: all clean

clean:
	rm *.o run