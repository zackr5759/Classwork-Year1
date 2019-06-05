/*
Zachary Robinson, CS10B, 3/18/2019, Dave Harden, ZR_CS10B_7.2

This program takes multiple lines of input from the user and tallies the alpha
characters used by creating a 26 element struct array for each letter of the
alphabet. Then, the program sorts the array from most to least used characters,
then prints the array.
*/

#include <iostream>
using namespace std;

void takeInput(struct list letters[], char ch);	/*Recieves input from user and increments
												letters.charCount for each char used even
												with many chars, since they are just left
												in the input stream.*/

void sortList(struct list letters[]);	/*Checks the most entered element in letters[]
										against those below it and swaps them if the 
										one below has a high charCount.*/

void printList(const list letters[]);	//Prints the sorted letters[] except the unused letters.



struct list {
	int charCount;
	char alphaChar;
};



int main()
{
	char ch;

	list letters[26];	
	for (int count = 0; count < 26; count++)	//Loop assigns a letter to each
												//of the 26 elements and sets
												//each charCount to 0.
	{
		ch = 97 + count;	//Assigns 'a' first run, 'b' second, and so on.
		letters[count].alphaChar = ch;
		letters[count].charCount = 0;
	}

	takeInput(letters, ch);
	sortList(letters);
	printList(letters);

}






void takeInput(struct list letters[], char ch)
{
	cout << "Please enter a sequence of characters terminated with a period ('.'): ";
	cin >> ch;
	while (ch != '.') {
		if (ch > 64 && ch < 91)	//Changes uppercase inputs to lowercase.
		{
			ch += 32;
		}
		if(ch > 96 && ch < 123)	//Ignores any non alpha character.
		{
		letters[ch - 97].charCount++;	//Since a = 97 in decimal, a = letters[0].
		}
		cin >> ch;
	}
}






void sortList(list letters[])
{
	for (int count = 0; count < 25; count++)	//Exactly the same as 7.1.
	{
		for (int i = count + 1; i < 26; i++)
		{
			if (letters[count].charCount < letters[i].charCount)
			{
				swap(letters[count], letters[i]);
			}
		}
	}
}






void printList(const list letters[])
{
	cout << "Letter:    Number of Occurrences";

	for (int count = 0; count < 26; count++)
	{
		if (letters[count].charCount > 0)
		{
			cout << endl;
			cout << letters[count].alphaChar << "    " << letters[count].charCount;
		}
	}
}