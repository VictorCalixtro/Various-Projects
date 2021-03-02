/*Purpose: The purpose of this program is to implement a programmer
 * defined stack and then pop 3 elements from that stack.
 * The programm will then calculate a postFixCalculation where the 
 * 3rd element will represent (multiplication for 0)
 * (Division for 1), (Addition for 2), (Subtraction for 3)
 *
 * For example 2 8 2 will evaluate to 2 + 8 = 10 
 * Since the 2 will represent addition.
 *
 * */

#include <iostream>
using namespace std;

typedef int StackElementType;
class Stack {
private:
	struct StackNode
	{
		StackElementType value;
		StackNode *next;

		// Constructor.
		StackNode(StackNode *next1 = nullptr)
		{
			next = next1;
		}
		StackNode(StackElementType val, StackNode *nex = nullptr)
		{
			next = nex;
			value = val;
		}
	};
	StackNode * top = nullptr;
public:
	Stack()
	{

	}
	~Stack()
	{
		StackNode * Del = top;
		StackNode *NextPointer;
		while (Del != 0)
		{
			NextPointer = Del->next;
			delete Del;
			Del = NextPointer;
		}

	}
    
	Stack(const Stack & rightHandSide) // copy constructor
	{
		
		StackNode *traversed = rightHandSide.top;
		while (traversed != nullptr)
		{
			top = new StackNode(traversed->value, top);
			traversed = traversed->next;
		}

		
		traversed = top;
		StackNode *top2 = nullptr;
		while (traversed != nullptr)
		{
			top2 = new StackNode(traversed->value, top2);
			traversed = traversed->next;
		}

		StackNode *Destroy = top;
		top = top2;
		while (Destroy != nullptr)
		{
			StackNode *garbage = Destroy;
			Destroy = Destroy->next;
			delete garbage;
		}
	}
	const Stack & operator=(const Stack & rightHandSide)
	{
		
		/*DELETE OLD Stack*/
		StackNode *nodePtr = top;
		while (nodePtr != nullptr)
		{
			StackNode *garbage = nodePtr;
			nodePtr = nodePtr->next;
			delete garbage;
		}

		/*CREATE NEW Stack IN REVERSE ORDER*/
		StackNode *traversed = rightHandSide.top;
		while (traversed != nullptr)
		{
			top = new StackNode(traversed->value, top);
			traversed = traversed->next;
		}

		/*CREATE NEW Stack TO Re-REVERSED Stack*/
		traversed = top;
		StackNode *top2 = nullptr;
		while (traversed != nullptr)
		{
			top2 = new StackNode(traversed->value, top2);
			traversed = traversed->next;
		}

		StackNode *Destroy = top;
		top = top2; // repoint the Stack to the corrected order
					  // Destroy reversed Stack
		while (Destroy != nullptr)
		{
			StackNode *garbage = Destroy;
			Destroy = Destroy->next;
			delete garbage;
		}

		return *this;

	}
	bool isEmpty() const
	{
		return top == nullptr;
	}                              
	void push(StackElementType item)
	{
		top = new StackNode(item, top);
	}	
	void display() const
	{
		StackNode *indexing;
		for (indexing = top; indexing->next != nullptr; indexing = indexing->next)
		{
			cout << indexing->value << " ";
		}
		cout << endl;
	}
	
	StackElementType pop()
	{
		StackElementType number = 0;

		if (!isEmpty())
		{
			StackNode * flecha = top;
			number = top->value;
			top = top->next;
			delete flecha;
		}
		else
		{
			cerr << "***The Stack is Empty --Can Not PoP***\n";
			exit(0);
		}

		return number;

	}

	void postFixCalculation()
	{
		// caution this function will only work if there are at least 3 elements in stack

		if (isEmpty())
		{
			return;
		}
		StackElementType number1 = pop();
		StackElementType number2 = pop();
		StackElementType sign = pop();

		if (sign == 0)
		{
			cout << number1 << " * " << number2 << "= " << number1 * number2 << endl;
		}

		if (sign == 1)
		{
			if (number2 == 0)
			{
				cout << "Cannot divide by zero" << endl;
				exit(0);
			}
			cout << number1 << " / " << number2 << "= " << number1 / number2 << endl;
		}

		if (sign == 2)
		{
			cout << number1 << " + " << number2 << "= " << number1 + number2 << endl;
		}

		if (sign == 3)
		{
			cout << number1 << " - " << number2 << "= " << number1 - number2 << endl;
		}

	}

	
};



enum operation_t { add = 0 , subtract = 1, multiply = 2, divide = 3 };




int main()
{
  cout<<"Testing class Stack\n";

  Stack stackA, stackB;
  stackA.push(1); stackA.push(9); stackA.push(9); stackA.push(4);
  stackA.push(1); stackA.push(0); stackA.push(2); stackA.push(8);
  
  cout << "stackA= ";
  stackA.display();
  
  stackB=stackA; // operator=
  cout << "stackB= ";
  stackB.display();

  stackA.push(7);
  cout << "stackA= ";
  stackA.display();
  cout << "stackB= ";
  stackB.display();

  Stack stackC=stackB; // construct a new stack, initialize with previous stack
  stackC.push(2);
  cout << "stackB= ";
  stackB.display();
  cout << "stackC= ";
  stackC.display();

  cout << "(0 = *)(1 = /)(2 = +)(3 = -)" << endl;
  cout << "Poping 3 elements from StackC" << endl;
  stackC.postFixCalculation();




	return 0;
}


