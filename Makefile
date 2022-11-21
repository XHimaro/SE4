CC=g++
output=./bin
object=$(output)/obj
all:
	$(CC) Complex.cpp testcmp.cpp Complex.h -o $(output)/Complex
CFLAGS=-c -Wall

all: Complex

Complex: $(object)/Complex.o $(object)/test.o
	$(CC) Complex.cpp testcmp.cpp Complex.h -o $(output)/Complex

$(object)/Complex.o: Complex.cpp Complex.h
	$(CC) $(CFLAGS) Complex.cpp -o $(object)/Complex.o

$(object)/test.o: testcmp.cpp
	$(CC) $(CFLAGS) testcmp.cpp -o $(object)/test.o
