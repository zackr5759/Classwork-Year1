#include <iostream>
using namespace std;

int main()
{
	int years;	//Define variables.
	cout << "Enter years of school:";	//Prompt user for input for years.
		cin >> years;
	if (years < 0)	//For numbers less than 0 return this warning.
	{
		cout << "years of school must be a non-negative integer\n";
	}
	if (years > 0 && years <= 6)
	{
		cout << "elementary school\n";
	}
	if (years >= 7 && years <= 8)	//For numbers between 0 and 12 types of schooling.
	{
		cout << "middle school\n";
	}
	if (years >= 9 && years <= 12)
	{
		cout << "high school\n";
	}
	if (years > 12)
	{
		cout << "college\n";	//For numbers over 12 return college.
	}
}