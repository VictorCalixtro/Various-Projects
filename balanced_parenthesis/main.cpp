#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*Purpose: The purpose of this program is to use the stack container in a program that reads a string, 
one character at a time, and determines whether the string contains balanced parentheses
that is, for each left parenthesis (if there are any) there
is exactly one matching right parenthesis later in the string.
*/


int main()
{
	string readInput;
	stack <char> myStack;

	cout << "Enter a string using only ( or ) and i will determine if it contains balanced parentheses" << endl;
	cout << "If it is not balanced then it is invalid: "; // only use ( or )
	getline(cin, readInput);


	for (int i = 0; i < readInput.length(); i++)
	{
			myStack.push(readInput[i]);
	}
	
	if (myStack.empty())
	{
		cout << "The Stack is empty. Therefore there is an even number" << endl;
		cout << "of parentheses(Zero)." << endl;
		cout << "Terminating the program..." << endl;
		
		return 0;
	}
	
	int leftP = 0, rightP = 0;
	for (int i = 0; i < 1; i++)
	{
		if (myStack.top() == '(')
		{
			cout << "Invalid expression" << endl; // if the last one is ( then we know its invalid.
			cout << "Terminating the program..." << endl;
		
			return 0;
		}
	}


	for (int i = 0; i < readInput.length(); i++)
	{
		if (myStack.top() == '(')
		{
			leftP += 1;
		}
		if (myStack.top() == ')')
		{
			rightP += 1;
		}
		if (rightP < leftP)
		{
			cout << "Invalid expression..." << endl;
			cout << "Terminating the progaram..." << endl;
		
			exit(0);
		}
		myStack.pop();
	}
	
	if (leftP == rightP)
	{
		cout << "The string is " << readInput << endl;
		cout << "Number of left parentheses " << leftP << endl;
		cout << "Number of right parentheses " << rightP << endl;
		cout << "The string contains balanced parentheses." << endl;
	}
	else
	{
		cout << "Invalid expression..." << endl;
		cout << "Terminating the progaram..." << endl;
		
		exit(0);
	}
	
	
	return 0;
}

/*Sample Output

Enter a string using only ( or ) and i will determine if it contains balanced parentheses
If it is not balanced then it is invalid: )(
Invalid expression
Terminating the program...
Press any key to continue . . .

Enter a string using only ( or ) and i will determine if it contains balanced parentheses
If it is not balanced then it is invalid: )()()
Invalid expression...
Terminating the progaram...
Press any key to continue . . .

Enter a string using only ( or ) and i will determine if it contains balanced parentheses
If it is not balanced then it is invalid: ()(
Invalid expression
Terminating the program...
Press any key to continue . . .

Enter a string using only ( or ) and i will determine if it contains balanced parentheses
If it is not balanced then it is invalid: ()()(())
The string is ()()(())
Number of left parentheses 4
Number of right parentheses 4
The string contains balanced parentheses.
Press any key to continue . . .

*/
