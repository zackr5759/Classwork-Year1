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
int getLeadingSpaces(int firstOfMonth, int &leadingSpaces); //Declaring prototypes.






int main()
{
	int year, firstOfMonth, monthCount, days = 0, dayCount = 0;
	string month;
	
	getDate(year, firstOfMonth);	
	printYear(year, month, monthCount, firstOfMonth, days, dayCount, leadingSpaces);
	system("pause"); //Studio 2017 closes after printing without this.



}






void getDate(int &year, int &firstOfMonth)
{
	

	cout << "What year do you want a calendar for? ";  //Recieve input for year and first day of the month.
	cin >> year;
	cout << "What day of the week does January 1 fall on (0 for Sunday, 1 for Monday, etc.)?";
	cin >> firstOfMonth;
	cout << endl;
}







bool isLeapYear(int year)
{
	if (year % 400 == 0) {	//Logic funtion from the lesson that checks for a leap year and returns true or false.
		return true;
	}

	if (year % 100 == 0) {
		return false;
	}

	return year % 4 == 0;	//If the remainder isnt O, return false.
}






void printYear(int year, string month, int &monthCount, int firstOfMonth, int days, int dayCount, int leadingSpaces)
{
	cout << "         " << year << endl;	//Print header.

	for (monthCount = 0;monthCount< 12; monthCount++)
	{
		printMonth(month, monthCount, year, firstOfMonth, days, dayCount, leadingSpaces);
    }
}






int getLeadingSpaces(int firstOfMonth, int &leadingSpaces)
{
	int leadingSpaces = 0;

	return leadingSpaces = firstOfMonth * 3; //Not really necessary if I hardcode the spaces in printMonth but this way the spacing can be changed easily.
}







void printMonth(string month, int monthCount, int year, int &firstOfMonth, int days, int dayCount, int leadingSpaces)
{

	days, dayCount;
	
	getMonthName(month, monthCount);	//Update month name and amount of days.
	getDays(year, days, monthCount);

	cout <<"	" << month << endl;
	cout << "  S  M  T  W  T  F  S" << endl;	//Print header.
	cout << "---------------------" << endl;

	getLeadingSpaces(firstOfMonth, leadingSpaces);

	for (int count = 0; count < leadingSpaces; count++)
	{
		cout << " ";	//Print 3 spaces for each day before the first of the month.
	}

	for (dayCount = 1; dayCount < (days + 1); dayCount++)	//days + 1 since the first day should be 1 not 0.
	{
	

		cout.width(3); cout << dayCount;	//If dayCount < 10 this will print 2 spaces and if its > 10 it will print one.

		firstOfMonth++;		//firstOfMonth progresses a day each dayCount thats printed.

		if ((firstOfMonth) == 7)	
		{											
			cout << endl;							

			firstOfMonth = 0;	//firstOfMonth gets reset when saturday passes and the line breaks.
		}
	}
	cout << endl;	//Space between months.

}






void getMonthName(string &month, int count)
{
	switch (count)	//Switch case based on the for loop count for months to decide month name.
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
	switch (count)	//Switch case to determine number of days per month.
	{
	case 0: days = 31;
		break;
	case 1: if (isLeapYear(year) == true)	//Calls the bool function to determine if february needs to lose a day.
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

/*
What year do you want a calendar for? 2000
What day of the week does January 1 fall on (0 for Sunday, 1 for Monday, etc.)?4

		 2000
		January
  S  M  T  W  T  F  S
---------------------
			  1  2  3
  4  5  6  7  8  9 10
 11 12 13 14 15 16 17
 18 19 20 21 22 23 24
 25 26 27 28 29 30 31

		February
  S  M  T  W  T  F  S
---------------------
  1  2  3  4  5  6  7
  8  9 10 11 12 13 14
 15 16 17 18 19 20 21
 22 23 24 25 26 27 28
 29
		March
  S  M  T  W  T  F  S
---------------------
	 1  2  3  4  5  6
  7  8  9 10 11 12 13
 14 15 16 17 18 19 20
 21 22 23 24 25 26 27
 28 29 30 31
		April
  S  M  T  W  T  F  S
---------------------
			  1  2  3
  4  5  6  7  8  9 10
 11 12 13 14 15 16 17
 18 19 20 21 22 23 24
 25 26 27 28 29 30
		May
  S  M  T  W  T  F  S
---------------------
					1
  2  3  4  5  6  7  8
  9 10 11 12 13 14 15
 16 17 18 19 20 21 22
 23 24 25 26 27 28 29
 30 31
		June
  S  M  T  W  T  F  S
---------------------
		1  2  3  4  5
  6  7  8  9 10 11 12
 13 14 15 16 17 18 19
 20 21 22 23 24 25 26
 27 28 29 30
		July
  S  M  T  W  T  F  S
---------------------
			  1  2  3
  4  5  6  7  8  9 10
 11 12 13 14 15 16 17
 18 19 20 21 22 23 24
 25 26 27 28 29 30 31

		August
  S  M  T  W  T  F  S
---------------------
  1  2  3  4  5  6  7
  8  9 10 11 12 13 14
 15 16 17 18 19 20 21
 22 23 24 25 26 27 28
 29 30 31
		September
  S  M  T  W  T  F  S
---------------------
		   1  2  3  4
  5  6  7  8  9 10 11
 12 13 14 15 16 17 18
 19 20 21 22 23 24 25
 26 27 28 29 30
		October
  S  M  T  W  T  F  S
---------------------
				 1  2
  3  4  5  6  7  8  9
 10 11 12 13 14 15 16
 17 18 19 20 21 22 23
 24 25 26 27 28 29 30
 31
		November
  S  M  T  W  T  F  S
---------------------
	 1  2  3  4  5  6
  7  8  9 10 11 12 13
 14 15 16 17 18 19 20
 21 22 23 24 25 26 27
 28 29 30
		December
  S  M  T  W  T  F  S
---------------------
		   1  2  3  4
  5  6  7  8  9 10 11
 12 13 14 15 16 17 18
 19 20 21 22 23 24 25
 26 27 28 29 30 31
*/