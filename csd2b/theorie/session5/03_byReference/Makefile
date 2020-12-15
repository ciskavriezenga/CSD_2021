CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z


all: example

example : main.o
	$(CC) -o $@ $(CFLAGS) main.o 

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
