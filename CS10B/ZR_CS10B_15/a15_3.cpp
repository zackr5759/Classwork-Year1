#include <iostream>
using namespace std;

int indexOfSmallest(int scores[]);
int sortArray(int inArray[], int lowerBound, int upperBound);

int main()
{
	int scores[30] = { 0 };
	int in, index = 0;


	for (int count = 0; count < 30; count++)
	{
		cout << "Enter scores(0 to quit, up to 30 scores, currently: " << count + 1 << "): ";
		cin >> in;
		if (in == 0)
		{
			count = 30;
		}
		else scores[count] = in;
	}

	sortArray(scores, 0, size(scores));

	for (int count = 0; count < 30; count++)
	{
		if (scores[count] > -1)
		{
			if (scores[count] > 0)
			{
			cout << scores[count] << endl;
			}
		}
	}
}






int indexOfSmallest(int inArray[])
{
	int index = 0, temp = inArray[0];
	for (int count = 0; count < 30; count++)
	{
		if (inArray[count] < temp)
		{
			index = count;
		}
	}
	return index;
}





int sortArray(int inArray[], int lowerBound, int upperBound)
{

	swap(inArray[0], inArray[indexOfSmallest(inArray)]);

	for (int count = lowerBound + 1; count < upperBound; count++)
	{
		if (inArray[lowerBound] > inArray[count])
		{
			swap(inArray[lowerBound], inArray[count]);
		}
	}

	lowerBound++;

	if (lowerBound < 29)
	{
		return sortArray(inArray, lowerBound, upperBound);
	}
	else return 1;

}