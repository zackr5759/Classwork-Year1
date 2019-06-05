#include <iostream>
using namespace std;

const int STANDARD_DECK_SIZE = 52; //Number of cards in a deck.

int main()
{
	int numberOfPlayers, leftOverCards, cardsPerPlayer; //Define variables
		cout << "Enter number of players:";
		cin >> numberOfPlayers;

	if (numberOfPlayers < 1 || numberOfPlayers > 52) //Return warning if user inputs invalid number
	{
		cout << "Number of players must be between 1 and 52.\n";
	} else {	//If user inputs valid number of players the program continues
		cardsPerPlayer = STANDARD_DECK_SIZE / numberOfPlayers;	//These calculations are in the else statement so that the program doesnt crash if the user enters 0
		leftOverCards = STANDARD_DECK_SIZE % numberOfPlayers;
		
		cout << cardsPerPlayer << " hand(s) will be played.\n";	//One card per hand
		if (leftOverCards > 0)	//Only outputs left over cards if there are any
		{
			cout << "There will be " << leftOverCards << " extra card(s).\n";
		}
	}
	
	/*
	Enter number of players:5
	10 hands will be played.
	There will be 2 extra cards.

	Enter number of players:0
	Number of players must be between 1 and 52.
	*/
}