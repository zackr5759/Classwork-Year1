#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float pounds;					//Define variable
	cout << "Enter pounds(negative number to quit): ";	//Prompt user for input in pounds
	cin >> pounds;		

	while (pounds >= 0) {	//If input is greater than or equal to zero it will calculate and output the number of ounces
		cout << pounds;
		cout << " pounds is ";

		cout << pounds * 16;
		cout << " ounces.\n";

		cout << "Enter pounds(negative number to quit): "; //Check for pounds again inside the loop
		cin >> pounds;
	}
	cout << "Goodbye!\n"; //Exiting message

	/*
	Enter pounds(negative number to quit): 4
	4 pounds is 64 ounces.
	Enter pounds(negative number to quit): 0
	0 pounds is 0 ounces.	
	Enter pounds(negative number to quit): -8
	Goodbye!
	*/
}