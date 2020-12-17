CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z


all: example

example : sine.o oscillator.o main.o
	$(CC) -o $@ $(CFLAGS) sine.o oscillator.o main.o

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
