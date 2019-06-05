/*
 Zachary Robinson, CS10B, 2/4/2019, Dave Harden, ZR_CS10B_3  

 This program takes user input asking if they are ready to play, then attempting to guess a number the user is thinking of
 between 1 and 100. The program guesses binarily by calculating the exact midpoint of the available numbers rounded down.
 The program asks the user if the number is higher, lower or correct and adjusts the available numbers until the user indicates 
 a correct guess. It then asks if they want to play again, starting over.
*/

#include <iostream>
using namespace std;

void playOneGame();	//Initializes variables for the highest and lowest possible numbers, calls the other two functions, and loops the guessing.
void getUserResponseToGuess(char& result);	//Sets the result variable equal to the users input of h, l, or c.
int getMidPoint(int low, int high);	//Called to set the guess to exactly half way between available numbers represented by high and low.






int main() 
{
	char response;

	cout << "Ready to play (y/n)? ";
	cin >> response;
	while (response == 'y') {	//Basic loop of the entire game based on user input.
		playOneGame();
		cout << "Great! Do you want to play again (y/n)? ";
		cin >> response;
	}
	system("pause");	//Only needed if you want to see the console after responding 'n'.
}






void playOneGame() 
{
	int guess, high = 100, low = 1;
	char result;
	guess = getMidPoint(low, high);
	cout << "Think of a number between 1 and 100. " << endl;
	
	do 
	{
		cout << "My guess is " << guess << ". ";
		getUserResponseToGuess(result);
		if (result == 'l')
		{
			high = guess;
		}
		else low = guess;

		guess = getMidPoint(low, high);


	} while (result != 'c');
}






void getUserResponseToGuess(char& result)
{
	cout << "Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it's correct: ";
	cin >> result;

}






int getMidPoint(int low, int high)
{
	return ((high + low) / 2);
}




/*
Ready to play (y/n)? y
Think of a number between 1 and 100.
My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it's correct: h
My guess is 75. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it's correct: h
My guess is 87. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it's correct: l
My guess is 81. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it's correct: h
My guess is 84. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it's correct: h
My guess is 85. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it's correct: c
Great! Do you want to play again (y/n)? y
Think of a number between 1 and 100.
My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it's correct: l
My guess is 25. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it's correct: l
My guess is 13. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it's correct: l
My guess is 7. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it's correct: h
My guess is 10. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it's correct: c
Great! Do you want to play again (y/n)? n
*/
