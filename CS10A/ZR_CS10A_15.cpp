#include <iostream>
using namespace std;

const int ARRAY_SIZE = 1000;




void readNumbers(int numberList[], int &inputNumber, int &numberCount);	
void printNumberList(int numberList[], int numberCount);
bool isUnique(int numberList[], int inputNumber, int numberCount);






int main()
{
	int numberList[ARRAY_SIZE], inputNumber, numberCount;

	readNumbers(numberList, inputNumber, numberCount); //Reads in input numbers and cuts out duplicates.
	printNumberList(numberList, numberCount);	//Prints out the input numbers in the same order.
	system("pause");
}






void readNumbers(int numberList[], int &inputNumber, int &numberCount)
{
	numberCount = 0;	//Amount of numbers entered so far.

	cout << "Enter a number (negative number to quit): ";	//Get input once before the check for the loop;
	cin >> inputNumber;

	while (inputNumber >= 0)	//Check for a negative.
	{
		if (isUnique(numberList, inputNumber, numberCount) == true)	//Function call to check for duplicates.
		{
			numberList[numberCount] = inputNumber;	//If not a duplicate the number is added to current slot and the count goes up.
			numberCount++;
		}
		cout << "Enter a number (negative number to quit): ";	//Get input again in loop.
		cin >> inputNumber;
	}
}







bool isUnique(int numberList[], int inputNumber, int numberCount)
{
	int trueCheck;
	
		for (int i = 0; i < ARRAY_SIZE; i++) //Loops until every variable has been checked or it hits a duplicate.
		{
			if (numberList[i] != inputNumber) //If statement to check duplicates.
			{
				trueCheck = 0;
			}
			else 
			{
				trueCheck = 1; //If a duplicate is found the variable is changed to 1 and the loop is stopped.
				i = ARRAY_SIZE;
			}
		}
		return trueCheck == 0; //Returns true if no duplicates, false is it is one.
}






void printNumberList(int numberList[], int numberCount)
{
	cout << "You entered: ";

	for (int count = 0; count < numberCount; count++) //Loops as many times as numbers entered.
	{
		cout << numberList[count] << "  "; //Variable of array printed goes up with count each loop.
	}
	cout << endl;
}





/*
Enter a number (negative number to quit): 2
Enter a number (negative number to quit): 3
Enter a number (negative number to quit): 4
Enter a number (negative number to quit): 1
Enter a number (negative number to quit): 2
Enter a number (negative number to quit): 3
Enter a number (negative number to quit): 6
Enter a number (negative number to quit): 3
Enter a number (negative number to quit): 5
Enter a number (negative number to quit): 4
Enter a number (negative number to quit): 4
Enter a number (negative number to quit): 1
Enter a number (negative number to quit): -2
You entered: 2  3  4  1  6  5
*/