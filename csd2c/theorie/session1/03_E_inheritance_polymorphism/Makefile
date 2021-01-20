CC = g++ -g
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -L/usr/local/lib -lbear-audio

all: signal

signal: Signal.o Sine.o Square.o main.o
	$(CC) -o $@ $(CFLAGS) Signal.o Sine.o Square.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f signal
