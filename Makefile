CXX = g++
CXXFLAGS = -Wall -std=c++17

all: main

main: main.o Steganography.o
	$(CXX) $(CXXFLAGS) -o main main.o Steganography.o

main.o: main.cpp Steganography.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Steganography.o: Steganography.cpp Steganography.h
	$(CXX) $(CXXFLAGS) -c Steganography.cpp

clean:
	rm -f *.o main
