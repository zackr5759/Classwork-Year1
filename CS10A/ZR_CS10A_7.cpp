#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int numberOfKids, numberOfYoungAdults, numberOfAdults, numberOfOlderAdults, numberOfSeniors, ageOfAttendee, smallestAge, highestAge, popcornPreference, sodaPreference, bothPreference, count;
	float averageAge, sumOfAges;	//Defining our many variables.
	char foodPreference;

	numberOfKids = 0;			//Setting all counting variables to 0.
	numberOfYoungAdults = 0;
	numberOfAdults = 0;
	numberOfOlderAdults = 0;
	numberOfSeniors = 0;
	sumOfAges = 0;
	count = 0;
	popcornPreference = 0;
	sodaPreference = 0;
	bothPreference = 0;

	cout << "Enter age of attendee (negative number to quit):";	 //Prompt user for attendee age.
	cin >> ageOfAttendee;

	smallestAge = ageOfAttendee;	//On the first input, smallest and highest age are equal to the only age.
	highestAge = ageOfAttendee;

	while (ageOfAttendee >= 0) {	//When a non-negative number is input, the loop begins.

		if (ageOfAttendee < smallestAge) {	//On the first pass this does nothing. If on the second loop the age is smaller it will now be the smallest age.

			smallestAge = ageOfAttendee;
		}

		if (ageOfAttendee > highestAge) {	//On the first pass this does nothing. If on the second loop the age is larger it will now be the highest age.

			highestAge = ageOfAttendee;
		}

		if (ageOfAttendee >= 0 && ageOfAttendee <= 18) {	//Each of these if statements add one to the counter for number of the targeted age group.
			numberOfKids = numberOfKids + 1;
		}

		if (ageOfAttendee >= 19 && ageOfAttendee <= 30) {
			numberOfYoungAdults = numberOfYoungAdults + 1;
		}

		if (ageOfAttendee >= 31 && ageOfAttendee <= 40) {
			numberOfAdults = numberOfAdults + 1;
		}

		if (ageOfAttendee >= 41 && ageOfAttendee <= 60) {
			numberOfOlderAdults = numberOfOlderAdults + 1;
		}

		if (ageOfAttendee > 60) {
			numberOfSeniors = numberOfSeniors + 1;
		}
		count++;	//count = count + 1 to keep track of amount of attendees.
		sumOfAges = sumOfAges + ageOfAttendee;	//Each age is added to the sum.

		cout << "Enter food preference('p' for popcorn, 's' for soda, 'b' for both) :"; //Prompt user for attendee food preference.
		cin >> foodPreference;
		
		if (foodPreference == 's') {			//Add plus one to each preference counter based on the letter that was input.
			sodaPreference = sodaPreference + 1;
		}

		if (foodPreference == 'p') {
			popcornPreference = popcornPreference + 1;
		}

		if (foodPreference == 'b') {
			bothPreference = bothPreference + 1;
		}

		while (foodPreference != 's' && foodPreference != 'b' && foodPreference != 'p') {
			cout << "Invalid input please input p, s, or b: ";
			cin >> foodPreference;
		}



		cout << "Enter age of attendee (negative number to quit):"; //Prompt user again for age again, inside the loop this time.
		cin >> ageOfAttendee;

	}
	if (count > 0) {	//If there are more than 0 attendees this information is outputted.
		averageAge = sumOfAges / count; //Divide the sum of ages by the amount of attendees.

		cout << endl << "age 0 to 18: " << numberOfKids << endl;
		cout << "age 19 to 30: " << numberOfYoungAdults << endl;
		cout << "age 31 to 40: " << numberOfAdults << endl;
		cout << "age 41 to 60: " << numberOfOlderAdults << endl;
		cout << "over 60: " << numberOfSeniors << endl << endl;

		cout << "food preference popcorn: " << popcornPreference << endl;
		cout << "food preference soda: " << sodaPreference << endl;
		cout << "food preference both: " << bothPreference << endl << endl;
		

		cout << "The average age was " << setprecision(1) << fixed << averageAge << endl;
		cout << "The youngest person in attendance was " << smallestAge << endl;
		cout << "The oldest person in attendace was " << highestAge << endl << endl;
	}
	if (count == 0) {	//If no attendees were entered, no information is displayed and this message is outputted.
		cout << "No ages entered, now exiting.\n";
	}
/*
Enter age of attendee (negative number to quit):34
Enter food preference('p' for popcorn, 's' for soda, 'b' for both) :s
Enter age of attendee (negative number to quit):16
Enter food preference('p' for popcorn, 's' for soda, 'b' for both) :b
Enter age of attendee (negative number to quit):68
Enter food preference('p' for popcorn, 's' for soda, 'b' for both) :b
Enter age of attendee (negative number to quit):53
Enter food preference('p' for popcorn, 's' for soda, 'b' for both) :s
Enter age of attendee (negative number to quit):39
Enter food preference('p' for popcorn, 's' for soda, 'b' for both) :p
Enter age of attendee (negative number to quit):23
Enter food preference('p' for popcorn, 's' for soda, 'b' for both) :s
Enter age of attendee (negative number to quit):21
Enter food preference('p' for popcorn, 's' for soda, 'b' for both) :s
Enter age of attendee (negative number to quit):-1

age 0 to 18: 1
age 19 to 30: 2
age 31 to 40: 2
age 41 to 60: 1
over 60: 1

food preference popcorn: 1
food preference soda: 4
food preference both: 2

The average age was 36.3
The youngest person in attendance was 16
The oldest person in attendace was 68
*/
}