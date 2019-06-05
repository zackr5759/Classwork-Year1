#include <iostream>
using namespace std;

int main()
{
int celsius;		//Define input and output as integers and the conversion factor as a double since using an integer will results in a conversion factor of 1.
int fahrenheit;
double conversion;

conversion = 9.0 / 5.0; //Conversion factor of 1.8.

cout << "enter degrees celsius: "; //Prompt user for input for celsius.
cin >> celsius;

fahrenheit = conversion * celsius + 32; //Convert to fahrenheit.

cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit\n"; //Output degrees fahrenheit.

/*
enter degrees celsius: 30
30 degrees Celsius is 86 degrees Fahrenheit
*/
}