#include <iostream>
using namespace std;






class Fraction {
public:
	void set(int inNumerator, int inDenominator);
	Fraction multipliedBy(Fraction inFraction);
	Fraction dividedBy(Fraction inFraction);
	Fraction addedTo(Fraction inFraction);
	Fraction subtract(Fraction inFraction);
	bool isEqualTo(Fraction inFraction);
	void print();

	int numerator;
	int denominator;
	
};





void Fraction::set(int inNumerator, int inDenominator)
{
	numerator = inNumerator;
	denominator = inDenominator;
}





void Fraction::print()
{
	cout << numerator << "/" << denominator;
}





Fraction Fraction::multipliedBy(Fraction inFraction)
{
	Fraction result;

	result.numerator = (numerator * inFraction.numerator);
	result.denominator = (denominator * inFraction.denominator);

	return result;
}





Fraction Fraction::dividedBy(Fraction inFraction)
{
	Fraction result;

	result.numerator = (numerator * inFraction.denominator);
	result.denominator = (denominator * inFraction.numerator);

	return result;
}





Fraction Fraction::addedTo(Fraction inFraction)
{
	Fraction result;

	result.numerator = ((numerator * inFraction.denominator ) + (denominator * inFraction.numerator));
	result.denominator = (denominator * inFraction.denominator);

	return result;
}





Fraction Fraction::subtract(Fraction inFraction)
{
	Fraction result;

	result.numerator = ((numerator * inFraction.denominator) - (denominator * inFraction.numerator));
	result.denominator = (denominator * inFraction.denominator);

	return result;
}





bool Fraction::isEqualTo(Fraction inFraction)
{
	if (numerator == inFraction.numerator || denominator == inFraction.denominator)
		return true;
	else return false;
}





int main()
{
	Fraction f1;
	Fraction f2;
	Fraction result;

	f1.set(9, 8);
	f2.set(2, 3);

	cout << "The product of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.multipliedBy(f2);
	result.print();
	cout << endl;

	cout << "The quotient of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.dividedBy(f2);
	result.print();
	cout << endl;

	cout << "The sum of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.addedTo(f2);
	result.print();
	cout << endl;

	cout << "The difference of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.subtract(f2);
	result.print();
	cout << endl;

	if (f1.isEqualTo(f2)) {
		cout << "The two Fractions are equal." << endl;
	}
	else {
		cout << "The two Fractions are not equal." << endl;
	}
}


/*
The product of 9/8 and 2/3 is 18/24
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two Fractions are not equal.

C:\Users\Zack\source\repos\Project27\Debug\Project27.exe (process 868) exited wi
th code 0.
Press any key to close this window . . .
*/