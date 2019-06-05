/*
 Zachary Robinson, CS10B, 2/14/2019, Dave Harden, ZR_CS10B_4

 This program takes user input for a hand of cards and calls 6 bool functions with 3 helper functions to decide and output what kind of hand the user holds.
 The program primarily relies on getIntegers to see how many times a specific number appears in the array.
 */

#include <iostream>
using namespace std;

const int HAND_SIZE = 5;

void drawCards (int cards[]); //Takes user input for the hand.


int getIntegers(int cards[], int target);	//Counts how many times the target number appears in the hand.

bool containsPair(int cards[]);	//Returns true if any number 2-9 appeared exactly twice.
bool containsTwoPair(int cards[]);	//Returns true if  if any two sets of numbers 2-9 appeared exactly twice.
bool containsThreeOfKind(int cards[]);	//Returns true if any number 2-9 appeared exactly three times.
bool containsFourOfKind(int cards[]);	//Returns true if any number 2-9 appeared exactly four times
bool containsFullHouse(int cards[]);	//Returns true if containsPair and containsThreeOfKind return true.
bool containsStraight(int cards[]);	//Returns true if a number in the array has 4 numbers in a row after it.

bool inArray(int cards[], int target);	//Called by containsStraight to check if target number is in the array.





int main()
{

	int cards[HAND_SIZE];
	cout << "Enter five numeric cards, no face cards. Use 2 - 9." << endl;
	drawCards(cards);

	if (containsFourOfKind(cards) == true)	//Nested if else statements from highest to lowest value hands.
	{
		cout << "Four of a kind!";
	}
	else {
		if (containsFullHouse(cards) == true)
		{
			cout << "Full House!";
		}
		else {
			if (containsStraight(cards) == true)
			{
				cout << "Straight!";
			}
			else {
				if (containsThreeOfKind(cards) == true)
				{
					cout << "Three of a kind!";
				}
				else {
					if (containsTwoPair(cards) == true)
					{
						cout << "Two pair!";
					}
					else {
						if (containsPair(cards) == true)
						{
							cout << "Contains pair!";
						}
						else {
							cout << "High card!";
						}
					}
				}
			}
		}
	}
	cout << endl;
	system("pause"); 
}



int getIntegers(int cards[], int target) //Target will be assigned a value by the functions calling it.
{
	int freq = 0;
	for (int i = 0; i < HAND_SIZE; i++)
	{
		if (cards[i] == target)
		{
			freq++;
		}
	}
	return freq;
}






void drawCards(int cards[])
{
	for (int count = 0; count < HAND_SIZE; count++)
	{
		cout << "Card " << count + 1 << ": ";
		cin >> cards[count];
	}
}






bool containsPair(int cards[])
{
	for (int i = 2; i <= 9; i++)	//Runs through each possible number for the cards.
	{
		if (getIntegers(cards, i) == 2)	//Returns true after one pair is found.
		{
			return true;
		}
	}
	return false;
}






bool containsTwoPair(int cards[])
{
	int count = 0;
	for (int i = 2; i <= 9; i++)
	{
		if (getIntegers(cards, i) == 2)
		{
			count++;
		}
	}
	if (count >= 2)	//Basically the same as containsPair but it checks for two instead of stopping after one.
	{
		return true;
	}
	return false;
}






bool containsThreeOfKind(int cards[])
{
	for (int i = 2; i <= 9; i++)
	{
		if (getIntegers(cards, i) == 3) //containsPair but checking for 3 appearances of target number.
		{
			return true;
		}
	}
	return false;
}






bool containsFourOfKind(int cards[])
{
	for (int i = 2; i <= 9; i++)
	{
		if (getIntegers(cards, i) == 4)	//As above, so below(but 4).
		{
			return true;
		}
	}
	return false;
}






bool containsFullHouse(int cards[]) 
{
	if ((containsPair(cards) && (containsThreeOfKind(cards)) == true))
	{
		return true;
	}
	return false;
}





bool containsStraight(int cards[])
{
	{
		int count = 0;
		for (int i = 2; i <= 9; i++)
		{
			if (inArray(cards, i) == true) //So if the number the for loop is checking is in the array the second loops starts.
			{
				for (int j = i + 1; j < (i + 5); j++) //Starts at the number after the first and keeps going to the required cards for a straight.
				{
					if (inArray(cards, j) == true)
					{
						count++;	//Call inArray again to see if each number is in the array and increment the counter.

						if (count == 4)	//If all 4 loops find a number, return true.
						{
							return true;
						}
					}
				}
				count = 0;	//Reset for the next tested starting number.
			}
		}
		return false;
	}
}






bool inArray(int cards[], int target)	//Target assigned a value by the functions calling it.
{
	if (getIntegers(cards, target) >= 1)
	{
		return true;
	}
	return false;
}






/*
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 2
Card 2: 3
Card 3: 8
Card 4: 8
Card 5: 9
Contains pair!

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 7
Card 2: 4
Card 3: 7
Card 4: 4
Card 5: 7
Full House!

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 7
Card 2: 8
Card 3: 9
Card 4: 6
Card 5: 5
Straight!
*/