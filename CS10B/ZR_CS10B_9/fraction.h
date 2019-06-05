/*
Zachary Robinson, CS10B, 4/3/2019, Dave Harden, ZR_CS10B_9.1

Class representing a fraction with two data members for the numerator and denominator. Contains functions for
several different arithmetic operations and reduces fractions when taking input and calculating. Arithmetic
functions do not modify passed variables


	Fraction();

	pre: There are no pre-conditions.
	post: [The numerator and denominator are initialized to 0 and 1.]


	Fraction(int inNumerator, int inDenominator);

	pre: There are no pre-conditions.
	post: The numerator and denominator are equal to the reduced version of the passed values.

	Fraction multipliedBy(const Fraction inFraction)const;

	pre: There are no pre-conditions.
	post: The simplified product of the called Fraction and the passed Fraction is returned.


	Fraction dividedBy(const Fraction inFraction)const;

	pre: There are no pre-conditions.
	post: The simplified quotient of the called Fraction and the passed Fraction is returned.


	Fraction addedTo(const Fraction inFraction)const;

	pre: There are no pre-conditions.
	post: The simplified sum of the called Fraction and the passed Fraction is returned.


	Fraction subtract(const Fraction inFraction)const;

	pre: There are no pre-conditions.
	post: The simplified difference of the called Fraction and the passed Fraction is returned.

	
	bool isEqualTo(const Fraction inFraction)const;

	pre: There are no pre-conditions.
	post: True or false is returned based on if the called and passed Fractions are equal to eachother.


	void print()const;

	pre: There are no pre-conditions.
	post: [The numerator and denominator are printed in the console as a fraction]
*/



#ifndef FRACTION_H
#define FRACTION_H


class Fraction {
public:
	Fraction();
	Fraction(int inNumerator, int inDenominator);
	Fraction multipliedBy(const Fraction inFraction)const;
	Fraction dividedBy(const Fraction inFraction)const;
	Fraction addedTo(const Fraction inFraction)const;
	Fraction subtract(const Fraction inFraction)const;
	bool isEqualTo(const Fraction inFraction)const;
	void print()const;
private:
	int numerator;
	int denominator;
	Fraction simplify(int inNumerator, int inDenominator)const;
};


#endif

/*
The result starts off at 0/1
The product of 9/8 and 2/3 is 3/4
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two Fractions are not equal.
The product of 3/2 and 2/3 is 1/1

C:\Users\Zack\source\repos\Project28\Debug\Project28.exe (process 7348) exited w
ith code 0.
Press any key to close this window . . .
*/