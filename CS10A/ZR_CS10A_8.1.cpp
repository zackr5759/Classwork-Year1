#include <iostream>
using namespace std;

const int SEVEN = 7;

int main()
{
	int amountOfNumbers, count, currentNumber, firstSeven, lastSeven;

	cout << "How many numbers will be entered ? "; //Prompt user for input of how many numbers to run through.
	cin >> amountOfNumbers;
	amountOfNumbers = amountOfNumbers + 1; //This is so the for statement wont loop one less time than they entered because I started count at 1.
	firstSeven = 0;						  
	lastSeven = 0;

	for (count = 1; count < amountOfNumbers; count++) { //Start count at 1 to keep track of numbers.
		cout << "Enter num: ";
		cin >> currentNumber;
		if (currentNumber == SEVEN) {	
			if (firstSeven == 0) {
				firstSeven = count; //If the entered number is a seven the position will be recorded if its the first, otherwise firstSeven would not be == 0.
			}
			else {					//Since the inputted number must be 7 to reach this point, the lastSeven is recorded if the firstSeven hasnt been recorded.
				lastSeven = count;
			}
		}
	}
	if (firstSeven != 0 && lastSeven == 0) { //If only one seven was inputted, this statement makes it also be the lastSeven.
		lastSeven = firstSeven;
	}
	if (firstSeven == 0) { //Error message for not entering any sevens.
	cout <<	"Sorry, no 7's were entered." << endl;
	}
	else { //Display the position of the sevens if there were any.
		cout << "The first 7 was in position " << firstSeven << endl;
		cout << "The last 7 was in position " << lastSeven << endl;
	}
	
	
}