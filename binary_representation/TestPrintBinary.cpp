/*Purpose: The purpose of this program is to one of the menu provided data types into 
 * its binary representation
 * */

#include <iostream>
#include "PrintBinary.h"
using namespace std;

int main()
{

	int choice;
	do
	{
		cout << "Menu" << endl;
		cout << "1 - Print the binary representation of a character" << endl;
		cout << "2 - Print the binary representation of a short integer" << endl;
		cout << "3 - Print the binary representation of a float" << endl;
		cout << "4 - Exit program" << endl;

		cout << "Enter your choice: ";
		cin >> choice;


		while (choice > 4 || choice < 0) // Input Validation
		{
			cout << "Enter your choice: ";
			cin >> choice;
		}

		if (choice == 1)
		{
			char character;
			cout << "Enter a character: ";
			cin >> character;
			printChar(character);
		}
		if (choice == 2)
		{
			short shortInt;
			cout << "Enter a short integer: ";
			cin >> shortInt;
			printShort(shortInt);
		}
		if (choice == 3)
		{
			float floatNum;
			cout << "Enter a float: ";
			cin >> floatNum;
			printFloat(floatNum);

		}

	} while (choice != 4);


	cout << "Exiting the Program..." << endl;

	
	return 0;

}

/*
Sample Program Output

Menu
1 - Print the binary representation of a character
2 - Print the binary representation of a short integer
3 - Print the binary representation of a float
4 - Exit program
Enter your choice: 1
Enter a character: G
The binary representation for G is 0100 0111

Menu
1 - Print the binary representation of a character
2 - Print the binary representation of a short integer
3 - Print the binary representation of a float
4 - Exit program
Enter your choice: 2
Enter a short integer: 6
The binary representation for 6 is 0000 0000 0000 0110

Menu
1 - Print the binary representation of a character
2 - Print the binary representation of a short integer
3 - Print the binary representation of a float
4 - Exit program
Enter your choice: 3
Enter a float: 3.14
The binary representation for 3.14 is 0100 0000 0100 1000 1111 0101 1100 0011

Menu
1 - Print the binary representation of a character
2 - Print the binary representation of a short integer
3 - Print the binary representation of a float
4 - Exit program
Enter your choice: 4
Exiting the Program...


*/

