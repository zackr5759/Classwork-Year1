#include <iostream>
using namespace std;

const int QUARTERS_V = 25;	//Give coins their value.
const int DIMES_V = 10;
const int NICKELS_V = 5;
const int PENNIES_V = 1;

int main()
{

int quarters, dimes, nickels, pennies, cents;	// Define coins and their values as integers.
	

	cout << "enter number of cents: "; //Prompt user for input on change required.
	cin >> cents;
	
	quarters = cents / QUARTERS_V;					// Here I defined the amount of quarters needed to be the input divided by the value of quarters without a remainder.
	dimes = (cents % QUARTERS_V) / DIMES_V;					// Here I defined dimes to be the the remainder of the input that was divided by the value of quarters, divided by the value of dimes.
	nickels = ((cents % QUARTERS_V) % DIMES_V) / NICKELS_V;	// Each line repeats what I did above with another added layer for the remainder.			
	pennies = (((cents % QUARTERS_V) % DIMES_V) % NICKELS_V) / PENNIES_V;

	cout << "pennies: " << pennies << "\n";		// The following lines output how many coins are required.
	cout << "nickels: " << nickels << "\n";
	cout << "dimes: " << dimes << "\n";
	cout << "quarters: " << quarters << "\n";

/*
enter number of cents: 119
pennies: 4
nickels: 1
dimes: 1
quarters: 4
*/
}