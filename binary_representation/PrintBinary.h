#ifndef PRINTBINARY_CPP
#define PRINTBINARY_CPP

#include <iostream>
using namespace std;

union floatValue
{
	int intVal;
	float floatVal;
};


void printChar(char ch)
{
	cout << "The binary representation for " << ch << " is ";
	for (int i = 7; i >= 0; --i)
	{
		cout << (((ch >> i) % 2) ? '1' : '0'); // if ch and i are nonzero, print 1 else print 0
		if (i % 4 == 0)
		{
			cout << " ";
		}
	}
	cout << endl << endl;
}
void printShort(short sh)
{
	cout << "The binary representation for " << sh << " is ";
	for (int i = 15; i >= 0; --i)
	{
		cout << (((sh >> i) % 2) ? '1' : '0');
		if (i % 4 == 0)
		{
			cout << " ";
		}
	}
	cout << endl << endl;
}
void printFloat(float fl)
{
	floatValue numbers;
	numbers.floatVal = fl;


	cout << "The binary representation for " << numbers.floatVal << " is ";
	for (int i = 31; i >= 0; --i)
	{
		cout << (((numbers.intVal >> i) % 2) ? '1' : '0');
		if (i % 4 == 0)
		{
			cout << " ";
		}
	}
	cout << endl << endl;
}

#endif