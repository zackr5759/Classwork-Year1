#include <iostream>
using namespace std;

void drawHorizontalLine(int numXs); //Defining all of our functions and setting up their variables.
void draw2VerticalLines(int numSpaces, int numRows);
void drawOneRow(int numSpaces);
void getDimensions(int &width, int &height, int &stages);
void drawBox(int width, int height);
void drawStages(int width, int height, int stages);
void drawCone();
void drawRocket(int width, int height, int stages);

int main()
{
	int width, height, stages;	//Main program runs the two end game functions and defines global variables.

	getDimensions(width, height, stages);
	drawRocket(width, height, stages);
}






void getDimensions(int &width, int &height, int &stages) //Use & for recieving and sending variable data from main
{
	cout << "Enter the width: ";
	cin >> width;
	cout << "Enter the height: ";
	cin >> height;
	cout << "Enter number of stages: ";
	cin >> stages;
}






void drawBox(int width, int height)
{

		drawHorizontalLine(width);
		draw2VerticalLines(width - 2, height - 2); //Since these lines will have to compensate for the horizontals, we use -2.
		drawHorizontalLine(width);
}






void drawHorizontalLine(int width)
{
	int count;
	for (count = 0; count < width; count++) { //Simply print an X then end the line.
		cout << "X";
	}
	cout << endl;
}






void draw2VerticalLines(int width, int height)
{
	int rowCount;

	for (rowCount = 0; rowCount < height; rowCount++) { //Print rows equal to the inputted height.
		drawOneRow(width);
	}
}






void drawOneRow(int width)
{
	int spaceCount;

	cout << "X";
	for (spaceCount = 0; spaceCount < width; spaceCount++) {	//The space between the rows is going to be width -2. Width already = original width -2 when pulled from drawBox.
		cout << " ";
	}
	cout << "X" << endl;
}






void drawStages(int width, int height, int stages)
{
	int count;

	for (count = 0; count < stages; count++) { //Draws boxes equal to the number of stages.
		drawBox(width, height);
	}
}






void drawCone()
{

	cout << "  X  " << endl;
	cout << " X X " << endl; //Simple cone.
	cout << "X   X" << endl;
}






void drawRocket(int width, int height, int stages)
{
	drawCone();
	drawStages(width, height, stages);	//Cones on top and bottom of the rocket.
	drawCone();

}
/*Enter the width of each stage: 5
		Enter the height of each stage: 4
		Enter the total number of stages in the rocket: 6
		  X
		 X X
		X   X
		XXXXX
		X   X
		X   X
		XXXXX
		XXXXX
		X   X
		X   X
		XXXXX
		XXXXX
		X   X
		X   X
		XXXXX
		XXXXX
		X   X
		X   X
		XXXXX
		XXXXX
		X   X
		X   X
		XXXXX
		XXXXX
		X   X
		X   X
		XXXXX
		  X
		 X X
		X   X */