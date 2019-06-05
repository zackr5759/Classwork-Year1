#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double startNumber, finalNumber, count;

	cout << "Enter a whole number greater than 0 (less than 1 to quit) : "; //Prompt user for number to square up to.
	cin >> startNumber;
	
	while (startNumber >= 1) {	//Unless a user inputs 0 or lower, program will loop.
		finalNumber = 0;
		count = 0;
					
		for (count = 1; count < (startNumber + 1); count++) { //This loop counts to the startNumber, I added +1 to startNumber since count started at 1 for the following equation.
			finalNumber = finalNumber + pow(count,2); //Squaring count and adding it to the previous number, starting at 0.
		}
		cout << "The sum of the squares from 1 to " << startNumber << " is " << finalNumber << endl; //Output the total value.

		cout << "Enter a number greater than 0 (less than 1 to quit) : "; //Set up for repeating the loop.
		cin >> startNumber;


	} 
	cout << endl;
/*
Enter a number greater than 0 (less than 1 to quit) : 4
The sum of the squares from 1 to 4 is 30
Enter a number greater than 0 (less than 1 to quit) : 1
The sum of the squares from 1 to 1 is 1
Enter a number greater than 0 (less than 1 to quit) : 0

*/
}