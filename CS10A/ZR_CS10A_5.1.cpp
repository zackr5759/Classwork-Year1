#include <iostream>
#include <iomanip>

using namespace std;

const float federalTax = 0.04, perMinuteRate = 0.4, nightTimeDiscount = 0.5, longCallDiscount = 0.15, eightAM = 800, sixPM = 1800, sixtyMinutes = 60;

int main()
{
	float callTime, startTime, grossCost, netCost; //Define variables as floats.

	cout << "Enter start time: ";				   //Prompt employee for call and start time.
	cin >> startTime;
	cout << "Enter length of call in minutes: ";
	cin >> callTime;

	grossCost = callTime * perMinuteRate;		   //Calculate gross cost.

	cout << "gross cost: $";
	cout << setprecision(2) << fixed << grossCost << "\n"; //Output gross cost to the hundreds place.

	if (startTime <= eightAM || startTime >= sixPM) {		   //If statement for the night time discount.
		grossCost = (grossCost * nightTimeDiscount);		   //This function is only doable this way since its 50%.
	}
	if (callTime > sixtyMinutes) {								//If statement for the long call discount.
		grossCost = grossCost - (grossCost * longCallDiscount); //If I did this the same way as the night discount it would be an 85% discount.
	}
	netCost = grossCost + (grossCost * federalTax);				//Add federal tax onto the gross cost after any discounts.
	cout << setprecision(2) << fixed << "Net cost: $" << netCost << endl;	//Net cost output to the hundreds place.

	/*
	Output 1

	Enter start time: 2322
	Enter length of call in minutes: 67
	gross cost: $26.80
	Net cost: $11.85

	Output 2

	Enter start time: 759
	Enter length of call in minutes: 10
	gross cost: $4.00
	Net cost: $2.08

	Output 3

	Enter start time: 1300
	Enter length of call in minutes: 100
	gross cost: $40.00
	Net cost: $35.36

	Output 4
	
	Enter start time: 1300
	Enter length of call in minutes: 10
	gross cost: $4.00
	Net cost: $4.16

	*/
}
