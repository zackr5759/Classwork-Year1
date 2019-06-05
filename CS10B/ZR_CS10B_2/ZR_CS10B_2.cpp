#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void oneGame(int totalValue, char response);
void dealInitialHand(int& totaValue);
void drawCards(int &totalValue, char &response);

int main()
{
	char response = 'y';
	int totalValue = 0;

	srand(static_cast<unsigned>(time(nullptr)));

	oneGame(totalValue, response);

	system("pause");
}





void oneGame(int totalValue, char response)
{

	while (response == 'y' || response == 'Y')
	{
		totalValue = 0;

		dealInitialHand(totalValue);
		drawCards(totalValue, response);
	} 
}





void dealInitialHand(int& totalValue)
{
	int cardOne, cardTwo;

	cardOne = rand() % 10 + 1;
	cardTwo = rand() % 10 + 1;

	totalValue = cardOne + cardTwo;

	cout << "First cards: " << cardOne << ", " << cardTwo << endl;
	cout << "Total: " << totalValue << endl;

}






void drawCards(int& totalValue, char &response)
{
	int drawnCard;

	cout << "Do you want another card? (y/n): ";
	cin >> response;

	while (response == 'y' || response == 'Y')
	{

		drawnCard = rand() % 10 + 1;
		totalValue = totalValue + drawnCard;

		cout << "Card: " << drawnCard << endl;
		cout << "Total: " << totalValue << endl;

		if (totalValue < 21)
		{
			cout << "Do you want another card? (y/n): ";
			cin >> response;
		}

		if (totalValue == 21)
		{
			cout << "Congratulations!" << endl;
			totalValue = 0;
			response = 'n';

		}

		if (totalValue > 21)
		{
			cout << "Bust." << endl;
			totalValue = 0;
			response = 'n';

		}



	}
	cout << "Play again? (y/n): ";
	cin >> response;
}

