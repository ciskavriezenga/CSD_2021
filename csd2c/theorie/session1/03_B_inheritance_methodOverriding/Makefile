CC = g++ -g

all: polyInstrument

polyInstrument: Instrument.o PolyphonicInstrument.o main.o
	$(CC) -o $@ Instrument.o PolyphonicInstrument.o main.o

.cpp.o:
	$(CC) -c $<

clean:
	rm -f *.o
	rm -f example
