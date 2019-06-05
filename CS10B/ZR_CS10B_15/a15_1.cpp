#pragma warning(disable:4996)

#include <iostream>
using namespace std;

int reverseWithinBounds(char* myString, int boundL, int boundR);
void reverseCstring(char cstring[], int boundL, int boundR);




int main()
{
	int stringLength, boundL, boundR;
	char cstring[100];

	cout << "Enter string length: ";
	cin >> stringLength;

	char* myString = new char[stringLength];

	cout << "Enter string: ";
	cin >> myString;

	while (cin.peek() == ' ')
	{
		char* temp = new char[stringLength];
		cin.get (temp, 1000);
		strcat(myString, temp);
	}

	
	
	cout << "Enter array bounds to reverse (lowerBound/upperBound): ";
	cin >> boundL;
	cin.ignore();
	cin >> boundR;
	

	reverseWithinBounds(myString, boundL, boundR);

	cout << "Reversed string: " << myString << endl;
	

	cout << "Enter cstring: ";
	cin >> cstring;
	while (cin.peek() == ' ')
	{
		char temp[1000];
		cin.get(temp, 1000);
		strcat(cstring, temp);
	}




	cout << "Enter array bounds to reverse (lowerBound/upperBound): ";
	cin >> boundL;
	cin.ignore();
	cin >> boundR;


	reverseCstring(cstring, boundL, boundR);

	cout << "Reversed cstring: " << cstring << endl;


}





int reverseWithinBounds(char* myString, int boundL, int boundR)
{
	char temp;

	if (boundL < boundR)
	{
		temp = myString[boundL];
		myString[boundL] = myString[boundR];
		myString[boundR] = temp;
		boundL++;
		boundR--;
	}
	else
	{
		return 1;
	}
	return reverseWithinBounds(myString, boundL, boundR);
}






void reverseCstring(char cstring[], int boundL, int boundR)
{
	reverseWithinBounds(cstring, boundL, boundR);
}