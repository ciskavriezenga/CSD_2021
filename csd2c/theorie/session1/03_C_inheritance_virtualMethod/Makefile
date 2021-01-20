CC = g++ -g

all: stringInstrument

stringInstrument: Instrument.o StringInstrument.o main.o
	$(CC) -o $@ Instrument.o StringInstrument.o main.o

.cpp.o:
	$(CC) -c $<

clean:
	rm -f *.o
	rm -f stringInstrument
