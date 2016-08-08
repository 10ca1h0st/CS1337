//******************************************************************
// Basic Math Operations program
// Programmer: Ian Olsen
// Completed : 6/18/2016
// Status    : Complete
// Description
// This program computes two numbers and outputs
// their sum, product, average, qoutient, and modulus
//******************************************************************
#include <iostream> // input and output declarations
using namespace std;

// Function Prototypes
void getNumbers();
void doMath(int &, int &);

int main()
{
// Call to our function to get input
	getNumbers();
	system("PAUSE");
	return 0;
}

//Function getNumbers
//Purpose: Get user input and pass to doMath
void getNumbers()
{

	int number1;	//first number selected by user
	int number2;	//second number selected by user

	//Get the input
	cout << "Enter two integers: " << endl;
	cin >> number1;
	cin >> number2;

	//Pass input to doMath
	doMath(number1, number2);
}

//Function doMath
//Purpose: Get input passed by reference from getNumbers and output basic math data
void doMath(int &num1, int &num2)
{
// Output of basic math operations
	cout << "Sum is " << num1 + num2 << endl;
	cout << "Product is " << num1 * num2 << endl;
	cout << "Average is " << (num1 + num2) / 2 << endl;
	cout << "Quotient is " << num1 / num2 << endl;
	cout << "Modulus is " << num1 % num2 << endl;
}
