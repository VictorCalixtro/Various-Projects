/*Purpose: To Implement a max heap and heapify algorithms*/


#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>
using namespace std;

void heapify(int intArray[], int s);
/* 
Preconditions:  int array and size, size is possitive and greater than 0.
Postconditions: Creates a Max heap with indexes 1 to size

*/
void heapsort(int intArray[], int s);
/*
Preconditions:  int array and size, size is possitive and greater than 0.
Postconditions: Creates a sorted array from indexes 1 to size

*/


void heapsort2(int intArray[], int x,int  s); // purpose is to keep heapsort 1 short. Basically does what parcolate down would do.
/*
Preconditions: Accepts 3 variables form heapshort
Postconditions: returns to heapshort.

*/

int main()
{
	int * intArray;
	char ch = 'Q';
	do
	{
		int number = -1;
		while (number <= 0) // number must be positive(input validation)
		{
			cout << "Enter the number of integers to be sorted: ";
			cin >> number;
		}
		
		number++;
		intArray = new int [number];
		int i = 1;
		while (i != number)
		{
			cout << "Enter element " << i << ": ";
			cin >> intArray[i];
			i++;
		}


		cout << "Array as entered\n";
		for (int i = 1; i < number; i++)
		{
			cout << intArray[i] << " ";
		}
		cout << endl;
		cout << "Calling heapify..." << endl;
		heapify(intArray, number);
		cout << "Max Heap\n";
		for (int i = 1; i < number; i++)
		{
			cout << intArray[i] << " ";
		}
		cout << endl << "Calling heapsort...";
		
		heapsort(intArray, number);
		cout << endl;

		cout << "Sorted Array\n";
		for (int i = 1; i < number; i++)
		{
			cout << intArray[i] << " ";
		}


		cout << "Do you wish to quit? (Y/N): ";
		cin >> ch;
		ch = toupper(ch);

	} while (ch != 'Y');

	

	delete[] intArray;
	intArray = NULL;



	return 0;

}
void heapify(int intArray[], int s)
{
	int i;
	for (i = s / 2; i >= 1; i--)
	{
		int j, temp;
		temp = intArray[i];
		j = 2 * i;
		while (j <= s)
		{
			if (j < s && intArray[j + 1] > intArray[j])
				j = j + 1;
			if (temp > intArray[j])
				break;
			else if (temp <= intArray[j])
			{
				intArray[j / 2] = intArray[j];
				j = 2 * j;
			}
		}
		intArray[j / 2] = temp;
	}
}

void heapsort(int intArray[], int s)
{

	int i, num;
	for (i = s -1; i >= 2; i--)
	{
		num = intArray[i];
		intArray[i] = intArray[1];
		intArray[1] = num;
		heapsort2(intArray, 1, i-1 );
	}
}

void heapsort2(int intArray[], int i, int  s)
{
	
	int j, temp;
	temp = intArray[i];
	j = 2 * i;
	while (j <= s)
	{
		if (j < s && intArray[j + 1] > intArray[j])
		{
			j = j + 1;

		}
		if (temp > intArray[j])
		{
			break;
		}
		else if (temp <= intArray[j])
		{
			intArray[j / 2] = intArray[j];
			j = 2 * j;
		}
	}
	intArray[j / 2] = temp;
	
}


/*Sample Output

Enter the number of integers to be sorted: 5
Enter element 1: 2
Enter element 2: 4
Enter element 3: 3
Enter element 4: 1
Enter element 5: 5
Array as entered
2 4 3 1 5
Calling heapify...
Max Heap
5 4 3 1 2
Calling heapsort...

Sorted Array
1 2 3 4 5 Do you wish to quit? (Y/N): y
Press any key to continue . . .

*/
