/*Purpose: The purpose of this file is to open a numbersFile.txt and save
 * those numbers into a programmer defined linked list.
 * */


#include <iostream>
#include <fstream>
using namespace std;


struct ListNode
{
	double value;
	ListNode *next;

	// Constructor.
	ListNode(double value1, ListNode *next1 = NULL)
	{
		value = value1;
		next = next1;
	}
};

int main()
{
	ListNode *numberList = NULL; 
	
	ifstream numberFile("numbersFile.txt");
	if (!numberFile)
	{
		cout << "Error in opening the file of numbers." << endl;;
		system("Pause");
		exit(1);
	}
	
	// Read the file into a linked list.
	double number; // Used to read the file
	cout << "The contents of the file are: " << endl;
	while (numberFile >> number)
	{
		cout << number << endl;
		
		numberList = new ListNode(number, numberList);// Create a node to hold this number.
	
	}
	
	// Traverse the list while printing.
	cout << endl << "The contents of the list are: " << endl;
	ListNode *ptr = numberList;
	while (ptr != NULL)
	{
		cout << ptr->value << " "; // Process node
		ptr = ptr->next; // Move to next node
	}

	return 0;
}
