main: TestPrintBinary.o
	g++ TestPrintBinary.o -o main

TestPrintBinary.o: TestPrintBinary.cpp PrintBinary.h
	g++ -c TestPrintBinary.cpp

clean:
	rm -rf *o main
