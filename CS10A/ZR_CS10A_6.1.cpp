#include <iostream>

using namespace std;

int main()
{
	int pounds;		//Define Variables.
	char response;
	

	cout << "Convert an amount of pounds to ounces?(Y/N):";	//Ask user if they have an amount to convert.
	cin >> response;

	
	do {		//Do loop proceeds as long as the response isnt n or N (see below).

		while (response == 'y' || response == 'Y') {	//After an affirmative, correct, response, proceed with pounds input

			cout << "Enter pounds: ";
			cin >> pounds;
			while (pounds <= 0) {	//If an input is less than or equal to 0, loop output error message.
				cout << "Please input a number greater than 0:";
				cin >> pounds;
			}

			cout << pounds << " pounds is " << pounds * 16 << " ounces.\n"; //After a non 0 answer, the conversion and output proceed.

			cout << "Convert an amount of pounds to ounces?(Y/N):";
			cin >> response;
		}

		while (response != 'y' && response != 'Y' && response != 'n' && response != 'N') {	//If the response is not recognized, loop asking for Y or N.
			cout << "Unrecognized response, try Y/N:";
			cin >> response;
		}
	} while (response != 'n' && response != 'N'); //Checks if the response was no to end the program. Any other response will get an error message or restart the loop.
	
		cout << "Ok, Goodbye!\n";
	
	/*Convert an amount of pounds to ounces?(Y/N):y
	Enter pounds: 04
	4 pounds is 64 ounces.
	Convert an amount of pounds to ounces?(Y/N):5
	Unrecognized response, try Y/N:Y
	Enter pounds: -4
	Please input a number greater than 0:0
	Please input a number greater than 0:4
	4 pounds is 64 ounces.
	Convert an amount of pounds to ounces?(Y/N):n
	Ok, Goodbye!*/
}
