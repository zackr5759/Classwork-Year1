/*
Zachary Robinson, CS10B, 3/18/2019, Dave Harden, ZR_CS10B_7.1

This program takes a user specified number of highscores via a dynamic array.
The highscores are defined as a struct containing a name and a score. The 
function initializeData is calls for user input for the highscores, sorData
then sorts the array from highest to lowest, and displayData prints the list
of highscores.
*/
#include <iostream>
#include <string>
using namespace std;


void initializeData(struct highscore scores[], int size);	//Takes user inputs for scores[] based on size
void sortData(struct highscore scores[], int size);	/*Checks the top unsorted score against those below
													it and swaps them if the one below is larger*/

void displayData(const highscore scores[], int size);	//Prints list of scores.


struct highscore{
	int score;
	char name[24];
};


int main()
{
	int size;
	cout << "How many scores will you enter?: ";
	cin >> size;

	struct highscore* scores = new highscore[size];

	initializeData(scores, size);
	sortData(scores, size);
	displayData(scores, size);
}






void initializeData(struct highscore scores[], int size)
{
	for (int count = 0; count < size; count++)
	{
		cout << "Enter the name for score # " << count + 1 << ": ";	
		cin >> scores[count].name;
		cout << "Enter the score for score # " << count + 1 << ": ";
		cin >> scores[count].score;
	}	
}






void sortData(struct highscore scores[], int size)
{	
	for (int count = 0; count < size - 1; count++)	//This for loop represents
													//the top unsorted score.
	{
		for (int i = count + 1; i < size ; i++)	//This loop runs through the scores
												//to be checked against the top.
		{
			if (scores[count].score < scores[i].score)
			{
				swap(scores[count], scores[i]);
			}
		}
	}
}






void displayData(const highscore scores[], int size)
{
	cout << "Top scorers: " << endl;

	for (int count = 0; count < size; count++)
	{
		cout << scores[count].name << ": " << scores[count].score << endl;
	}
}