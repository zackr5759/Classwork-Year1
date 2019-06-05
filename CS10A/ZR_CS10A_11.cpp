#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void doOneSet(char op);
void doOneProblem(char op);
void generateOperands(int &numOne, int &numTwo);
void calculateCorrectAnswer(int numOne, int numTwo, char op, int &answer); //Prototypes.
void checkAnswer(int answer, int userInput);

int main()
{


	srand(static_cast<unsigned>(time(0))); //Randomize number generator based on clock.
	doOneSet('+');
	doOneSet('-'); //Doing one set, changing the operator each time.
	doOneSet('*');


}

void doOneSet(char op) //Repeat the doOneProblem function 5 times.
{
	for (int count = 0; count < 5; count++)
	{
		doOneProblem(op);
	}
}



void doOneProblem(char op) //Contains the other functions.
{
	int numOne, numTwo, answer, userInput;



	generateOperands(numOne, numTwo);

	cout << numOne << " " << op << " " << numTwo << " = "; //Output of problem and taking userInput.
	cin >> userInput;

	calculateCorrectAnswer(numOne, numTwo, op, answer);
	checkAnswer(answer, userInput);

}

void generateOperands(int &numOne, int &numTwo) //Assign random numbers to variables.
{

    numOne = rand() % 101;

	numTwo = rand() % 101;
}

void calculateCorrectAnswer(int numOne, int numTwo, char op, int &answer) //Assigns the correct value to the answer variable.
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
void checkAnswer(int answer, int userInput) //Checks if the user input is correct.
{

	if (userInput == answer) {
		cout << "correct" << endl;
	}
	else {
		cout << "incorrect" << endl;
	}

}

/*
20 + 16 = 36
correct
35 + 68 = 103
correct
32 + 96 = 18
incorrect
25 + 80 = 5
incorrect
11 + 88 = 99
correct
90 - 60 = 30
correct
85 - 21 = 4
incorrect
20 - 69 = -49
correct
78 - 55 = 13
incorrect
34 - 51 = -17
correct
65 * 34 = 2210
correct
50 * 91 = 4550
correct
31 * 98 = 84
incorrect
25 * 4 = 600
incorrect
36 * 89 = 3
incorrect
*/



