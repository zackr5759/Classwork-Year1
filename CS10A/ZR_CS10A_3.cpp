#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	char shape;	//Defining variables.
	double base, height, side, area;
	
	cout << "Enter type of figure (s or t):";	//Prompt user for which shape to use.
	cin >> shape;
	
	if (shape == 't')	//If statement for triangles.
		{
		cout << "Enter the base:";	//Prompt user for base and height.
		cin >> base;
		cout << "Enter the height:"; 
		cin >> height;
		area = 0.5 * base * height;	//Area is calculated.
		cout << fixed << setprecision(1) << "The area is " << area << "\n";	//Area is outputted.


		}
	if (shape == 's')	//If statment for squares.
		{
		cout << "Enter the length of a side:";	//Prompt user for side length.
		cin >> side;
		area = side * side;	//Area is calculated.
		cout << fixed << setprecision(1) << "The area is " << area << "\n";	//Area is outputted.
		}
	/*
	Enter type of figure (s or t):t
	Enter the base:7
	Enter the height:3
	The area is 10.5

	Enter type of figure (s or t):s
	Enter the length of a side:9
	The area is 81.0
	*/
}
