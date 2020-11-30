
osctest: main.o oscillator.o
	g++ -o osctest main.o oscillator.o

main.o: main.cpp oscillator.h
	g++ -c main.cpp

oscillator.o: oscillator.cpp oscillator.h
	g++ -c oscillator.cpp

clean:
	rm osctest main.o oscillator.o

