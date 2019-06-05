#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


using namespace std;


void doOneSet(char op, double probsPerSet, int &numRight);
void doOneProblem(char op, int maxNum, int &numRight);
void generateOperands(int &numOne, int &numTwo, int maxNum);
void calculateCorrectAnswer(int numOne, int numTwo, char op, int &answer); //Prototypes.
void checkAnswer(int answer, int userInput, int &numRight);
void getProbsPerSet(double &probsPerSet);
void printHeader(char op);
void getMaxNum(int &maxNum);
void printReport(double probsPerSet, int numRightPlus, int numRightMinus, int numRightTimes);






int main()
{
	int  numRightPlus = 0, numRightMinus = 0, numRightTimes = 0;
	double probsPerSet;

	srand(static_cast<unsigned>(time(0))); //Randomize number generator based on clock.
	getProbsPerSet(probsPerSet);
	doOneSet('+', probsPerSet, numRightPlus);
	doOneSet('-', probsPerSet, numRightMinus); //Doing one set, changing the operator, and the correct answer count being incremented each time.
	doOneSet('*', probsPerSet, numRightTimes);
	printReport(probsPerSet, numRightPlus, numRightMinus, numRightTimes);
	system("pause"); //The console wasnt staying open on visual studio 2017 so I added this.
}






void doOneSet(char op, double probsPerSet, int &numRight) //Call the printHeader and MaxNum functions them repeat doOneProblem for the specified number of problems.
{
	int maxNum;


	printHeader(op);
	getMaxNum(maxNum);

	for (int count = 0; count < probsPerSet; count++)
	{
		doOneProblem(op, maxNum, numRight);

	}

}






void doOneProblem(char op, int maxNum, int &numRight) //Contains the other functions.
{
	int numOne, numTwo, answer, userInput;



	generateOperands(numOne, numTwo, maxNum);

	cout << numOne << " " << op << " " << numTwo << " = "; //Output of problem and taking userInput.
	cin >> userInput;

	calculateCorrectAnswer(numOne, numTwo, op, answer);
	checkAnswer(answer, userInput, numRight);


}






void generateOperands(int &numOne, int &numTwo, int maxNum) //Assign random numbers between 0 and the MaxNum to numOne and numTwo.
{

    numOne = rand() % (maxNum + 1);

	numTwo = rand() % (maxNum + 1);
}






void calculateCorrectAnswer(int numOne, int numTwo, char op, int &answer) //Assigns the correct value to the variable, answer.
{


	if (op == '+') {
		answer = numOne + numTwo;
	}
	if (op == '-') {
		answer = numOne - numTwo;
	}
	if (op == '*') {
		answer = numOne * numTwo;
	}
}






void checkAnswer(int answer, int userInput, int &numRight) //Increments numRight and displays a message based on the user's input being correct.
{


	if (userInput == answer) {

		cout << "correct" << endl;

		numRight++;

	}
	else {
		cout << "incorrect" << endl;

	}

}






void getProbsPerSet(double &probsPerSet) //Ask user for the amount of problems per set.
{
	cout << "How many problems per set? ";
	cin >> probsPerSet;
}






void printHeader(char op) //Prints the header for each set.

{
	if (op == '+') {
		cout << "Set #1" << endl << "-----------" << endl;

	}
	if (op == '-') {
		cout << "Set #2" << endl << "-----------" << endl;

	}
	if (op == '*') {
		cout << "Set #3" << endl << "-----------" << endl;

	}


}






void getMaxNum(int &maxNum) //Ask user for the max value for calculations for each set.
{
	cout << "Enter max number for calculations: ";
	cin >> maxNum;
}






void printReport(double probsPerSet, int numRightPlus, int numRightMinus, int numRightTimes) //Final report for the calculations.
{
	double percentOne, percentTwo, percentThree;

	percentOne = (numRightPlus / probsPerSet) * 100; //Convert the number of correct answers into percentages.
	percentTwo = (numRightMinus / probsPerSet) * 100;
	percentThree = (numRightTimes / probsPerSet) * 100;


	cout << fixed << setprecision(0) << "Set#1: You got " << numRightPlus << " correct out of " << probsPerSet << " for " << fixed << setprecision(1) << percentOne << "%." << endl; //Output report.

	cout << fixed << setprecision(0) << "Set#2: You got " << numRightMinus << " correct out of " << probsPerSet << " for " << fixed << setprecision(1) << percentTwo << "%." << endl;

	cout << fixed << setprecision(0) << "Set#3: You got " << numRightTimes << " correct out of " << probsPerSet << " for " << fixed << setprecision(1) << percentThree << "%." << endl;

}

/*
How many problems per set? 3
Set #1
-----------
Enter max number for calculations: 15
7 + 8 = 15
correct
10 + 1 = 5
incorrect
6 + 6 = 9
incorrect
Set #2
-----------
Enter max number for calculations: 44
23 - 30 = -7
correct
13 - 13 = 0
correct
28 - 6 = 22
correct
Set #3
-----------
Enter max number for calculations: 5
3 * 1 = 3
correct
4 * 0 = 0
correct
0 * 3 = 8
incorrect
Set#1: You got 1 correct out of 3 for 33.3%.
Set#2: You got 3 correct out of 3 for 100.0%.
Set#3: You got 2 correct out of 3 for 66.7%.
*/









