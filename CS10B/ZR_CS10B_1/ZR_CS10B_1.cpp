#include <iostream>
using namespace std;

int main() {
	int day, month, year;

	cout << "Enter a date in the format month/day/2-digit-year: ";

	cin >> day;		//When this line ends the last character in the instream is a forward slash.
	cin.ignore();	//Deletes the forward slash out of the instream.
	cin >> month;
	cin.ignore();	//Same as above.
	cin >> year;

	if (day * month == year)	//Simple if else checking for "magic date"
	{

	cout << "That is a magic date!\n";

	}
	else cout << "That is not a magic date.\n";

	system("pause");	//Keeps the console open if using an empty project.
}