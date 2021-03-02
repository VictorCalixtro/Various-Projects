/*Purpose: I made this program to test out the chrono library in c++
 *I implemented two programmer defined power functions, power and improvedPow.
 *I then made a simple benchmark that tests out the time needed to perform the 
 *Needed calculations for each function. 
 * */


#include <iostream>
#include <chrono>

using namespace std;

double power2(double x, int y)
{

	if (y == 0)
		return 1;
	if (y > 0)
	{
		return (x*power2(x, y - 1));
	}
	double number;
	if (y < 0)
	{
		y = y * -1;
		number = (x*power2(x, y - 1));
	}
	double number2 = 1 / number;
	return number2;


}

double improvedPow(double x, int y)
{
	if (y == 0)
		return 1;

	double tempVariable;
	if (y % 2 == 0) // If even
	{
		if (y > 0) // If positive
		{
			tempVariable = (x * improvedPow(x, ((y - 1) / 2)));
			return tempVariable * tempVariable;
		}
		double number;
		if (y < 0)// if negative
		{
			y = y * -1;
			tempVariable = (x * improvedPow(x, ((y - 1) / 2)));
		}
		number = 1 / (tempVariable * tempVariable);
		return number;
	}
	if (y % 2 == 1 || y % 2 == -1) // If odd
	{
		if (y > 0) // if positive
		{
			tempVariable = (improvedPow(x, (y - 1) / 2));
			return (x * tempVariable * tempVariable);
		}
		double number;
		if (y < 0)//if negative
		{
			y = y * -1;
			tempVariable = improvedPow(x, (y));

		}
		number = 1 / (tempVariable);
		return number;

	}
	return 1;
}

int main()
{
	cout << "To calculate x^y ..." << endl;

	double x;
	int y;
	cout << "Please enter x: ";
	cin >> x;
	cout << "Please enter y: ";
	cin >> y;

	if (x == 0) {
		if (y > 0)
			cout << 0 << endl;
		else
			cout << "x^y is not defined" << endl;
	}
	else {
		cout << improvedPow(x, y) << endl;	
		cout << "To get this result..." << endl;

		chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
		power2(x, y);
		chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
		cout << "power2(x,y) would take time: " << duration << " ns" << endl;

		t1 = chrono::high_resolution_clock::now();
		improvedPow(x, y);
		t2 = chrono::high_resolution_clock::now();
		duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
		cout << "improvedPow(x,y) would take time: " << duration << " ns" << endl;
	}

	
	return 0;}
