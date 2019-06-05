/*
Zachary Robinson, CS10B, 2/28/2019, Dave Harden, ZR_CS10B_5.2

This program takes a user specified number of highscores with names attached. It allocates two
arrays for the scores then calls initializeArrays to take in the actual scores and names from
the user and assigns them to elements of the arrays. The program then calls sortData to rearrange
the array elements from highest to lowest scoring player. Finally, the program calls displayData
to print the list of scores.
*/
#include <iostream>
#include <string>
using namespace std;



void initializeArrays(string names[], int scores[], int size);	//Take user input and put scores and names
																//into their arrays.
void sortData(string names[], int scores[], int size);	//Loops through each number below the one being checked
														//and if bigger, swaps them.
void displayData(const string names[], const int scores[], int size);	//Displays contents of the two arrays.



int main()
{
	int size;
	cout << "How many scores will you enter?: ";
	cin >> size;
	string* names = new string[size];	//Allocate arrays from the heap based on the amount of scores to enter.
	int* scores = new int[size];

	initializeArrays(names, scores, size);
	sortData(names, scores, size);
	displayData(names, scores, size);

	system("pause");
}







void initializeArrays(string names[], int scores[], int size)
{
	for (int count = 0; count < size; count++)
	{
		cout << "Enter the name for score # " << count + 1 << ": ";
		cin >> names[count];
		cout << "Enter the score for score # " << count + 1 << ": ";
		cin >> scores[count];
	}	
}







void sortData(string names[], int scores[], int size)
{
	int temp;
	string tempS;

	for (int count = 0; count < size - 1; count++)	//This loop selects the top unsorted score.
	{
		for (int i = count + 1; i < size ; i++)	//This loop runs through each score below the one being checked.
		{
			if (scores[count] < scores[i])	//If the lower score is bigger, they swap.
			{
				temp = scores[count];
				scores[count] = scores[i];
				scores[i] = temp;

				tempS = names[count];
				names[count] = names[i];
				names[i] = tempS;
			}
		}
	}
}





void displayData(const string names[], const int scores[], int size)
{
	cout << "Top scorers: " << endl;

	for (int count = 0; count < size; count++)
	{
		cout << names[count] << ": " << scores[count] << endl;
	}
}


/*
How many scores will you enter?: 4
Enter the name for score # 1: Suzy
Enter the score for score # 1: 600
Enter the name for score # 2: Kim
Enter the score for score # 2: 9900
Enter the name for score # 3: Armando
Enter the score for score # 3: 8000
Enter the name for score # 4: Tim
Enter the score for score # 4: 514
Top scorers:
Kim: 9900
Armando: 8000
Suzy: 600
Tim: 514

How many scores will you enter?: 5
Enter the name for score # 1: a
Enter the score for score # 1: 1
Enter the name for score # 2: b
Enter the score for score # 2: 2
Enter the name for score # 3: c
Enter the score for score # 3: 3
Enter the name for score # 4: d
Enter the score for score # 4: 4
Enter the name for score # 5: e
Enter the score for score # 5: 5
Top scorers:
e: 5
d: 4
c: 3
b: 2
a: 1
*/