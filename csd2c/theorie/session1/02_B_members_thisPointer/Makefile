CC = g++ -g

all: instrument

instrument: Instrument.o main.o
	$(CC) -o $@ Instrument.o main.o

.cpp.o:
	$(CC) -c $<

clean:
	rm -f *.o
	rm -f example
