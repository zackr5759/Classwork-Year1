#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;






void printYear(int year, string month, int &monthCount, int firstOfMonth, int days, int dayCount, int leadingSpaces);
void printMonth(string month, int monthCount, int year, int &firstOfMonth, int days, int dayCount, int leadingSpaces);
void getDate(int &year, int &firstOfMonth);
bool isLeapYear(int year);
void getMonthName(string &month, int monthCount);
void getDays(int year, int &days, int monthCount);
int getLeadingSpaces(int firstOfMonth, int &leadingSpaces);






int main()
{
	int year, firstOfMonth, monthCount, days = 0, dayCount = 0, leadingSpaces = 0;
	string month;
	
	getDate(year, firstOfMonth);
	printYear(year, month, monthCount, firstOfMonth, days, dayCount, leadingSpaces);
	system("pause");
		

}






void getDate(int &year, int &firstOfMonth)
{
	

	cout << "What year do you want a calendar for? ";
	cin >> year;
	cout << "What day of the week does January 1 fall on (0 for Sunday, 1 for Monday, etc.)?";
	cin >> firstOfMonth;
	cout << endl;
}







bool isLeapYear(int year)
{
	if (year % 400 == 0) {
		return true;
	}

	if (year % 100 == 0) {
		return false;
	}

	return year % 4 == 0;
}






void printYear(int year, string month, int &monthCount, int firstOfMonth, int days, int dayCount, int leadingSpaces)
{
	cout << "          " << year << endl;

	for (monthCount = 0;monthCount< 12; monthCount++)
	{
		printMonth(month, monthCount, year, firstOfMonth, days, dayCount, leadingSpaces);
  }
}






int getLeadingSpaces(int firstOfMonth, int &leadingSpaces)
{
	return leadingSpaces = firstOfMonth;
}







void printMonth(string month, int monthCount, int year, int &firstOfMonth, int days, int dayCount, int leadingSpaces)
{

	days = 0, dayCount = 0;
	
	getMonthName(month, monthCount);
	getDays(year, days, monthCount);

	cout <<"	" << month << endl;
	cout << "  S  M  T  W  T  F  S" << endl;
	cout << "---------------------" << endl;

	getLeadingSpaces(firstOfMonth, leadingSpaces);

	for (int count = 0; count < leadingSpaces; count++)
	{
		cout << "   ";
	}

	for (dayCount = 1; dayCount < (days + 1); dayCount++)
	{

		if (dayCount < 10)
		{
			cout << "  " << dayCount;
			firstOfMonth++;
		}
		else {

			cout << " " << dayCount;
			firstOfMonth++;
		}

		if ((leadingSpaces + dayCount) == 7 || (leadingSpaces + dayCount) == 14 || (leadingSpaces + dayCount) == 21 || (leadingSpaces + dayCount) == 28 || (leadingSpaces + dayCount) == 35)
		{
			cout << endl;

			firstOfMonth = 0;
		}

	}
	cout << endl;

}






void getMonthName(string &month, int count)
{
	switch (count)
	{
	case 0: month = "January";
		break;
	case 1: month = "February";
		break;
	case 2: month = "March";
		break;
	case 3: month = "April";
		break;
	case 4: month = "May";
		break;
	case 5: month = "June";
		break;
	case 6: month = "July";
		break;
	case 7: month = "August";
		break;
	case 8: month = "September";
		break;
	case 9: month = "October";
		break;
	case 10: month = "November";
		break;
	case 11: month = "December";
		break;

	}

}






void getDays(int year, int &days, int count)
{
	switch (count)
	{
	case 0: days = 31;
		break;
	case 1: if (isLeapYear(year) == true) 
	{
		days = 29;
	}
			else days = 28;
		break;
	case 2: days = 31;
		break;
	case 3: days = 30;
		break;
	case 4: days = 31;
		break;
	case 5: days = 30;
		break;
	case 6: days = 31;
		break;
	case 7: days = 31;
		break;
	case 8: days = 30;
		break;
	case 9: days = 31;
		break;
	case 10: days = 30;
		break;
	case 11: days = 31;
		break;

	}
}