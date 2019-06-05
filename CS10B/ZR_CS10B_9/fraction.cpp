/*
Zachary Robinson, CS10B, 4/3/2019, Dave Harden, ZR_CS10B_9.1

A Fraction object has 2 data members: numerator, which stores any non-zero integer as the top number in the Fraction
and denominator, which does the same for the bottom number. Fraction objects will always be stored in their simplified
forms and will terminate the program if attempting toequate the denominator to 0. Nothing is implemented to deal with
negative numbers.
*/

#include <iostream>
#include <cassert>
#include "fraction.h"
using namespace std;


Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}






Fraction::Fraction(int inNumerator, int inDenominator)
{
		numerator = simplify(inNumerator, inDenominator).numerator;
		denominator = simplify(inNumerator, inDenominator).denominator;
		assert(denominator != 0);
}






void Fraction::print() const
{
	cout << numerator << "/" << denominator;
}






Fraction Fraction::multipliedBy(const Fraction inFraction)const	//Uses (a/b * b/d) = ((a*c) / (b*d)) algorithm, and 
																//uses simplify(); to return a reduced result.
{
	Fraction result;

	result.numerator = numerator * inFraction.numerator;
	result.denominator = denominator * inFraction.denominator;

	return simplify(result.numerator, result.denominator);
}






Fraction Fraction::dividedBy(const Fraction inFraction)const	//Uses (a/b / b/d) = ((a*d) / (b*c)) algorithm, and 
																//uses simplify(); to return a reduced result.
{
	Fraction result;

	result.numerator = numerator * inFraction.denominator;
	result.denominator = denominator * inFraction.numerator;

	return simplify(result.numerator, result.denominator);
}






Fraction Fraction::addedTo(const Fraction inFraction)const	//Uses (a/b + b/d) = (((a*d) + (b*c)) / (b * d)) algorithm,
															//and uses simplify(); to return a reduced result.
{
	Fraction result;

	result.numerator = ((numerator * inFraction.denominator) + (denominator * inFraction.numerator));
	result.denominator = (denominator * inFraction.denominator);

	return simplify(result.numerator, result.denominator);;
}






Fraction Fraction::subtract(const Fraction inFraction) const	//Uses (a/b + b/d) = (((a*d) - (b*c)) / (b * d))
																//algorithm,and uses simplify(); to return a reduced
																//result.
{
	Fraction result;

	result.numerator = ((numerator * inFraction.denominator) - (denominator * inFraction.numerator));
	result.denominator = (denominator * inFraction.denominator);

	return simplify(result.numerator, result.denominator);
}






bool Fraction::isEqualTo(const Fraction inFraction) const	//With the current client program, the inFraction is 
{															//already simplified so nothing needs to be checked
															//for simplifying here.
	if ((numerator == inFraction.numerator) && (denominator == inFraction.denominator))
	{
		return true;
	}
	else return false;
}






Fraction Fraction::simplify(int inNumerator, int inDenominator)const	//Copies passed values into a temporary
																		//Fraction then checks every number down from
{																		//the numerator and denominators product down
																		//for a possible divisor, dividing the Fraction
																		//if it finds one.
	Fraction simplifiedResult;

		simplifiedResult.numerator = inNumerator;
		simplifiedResult.denominator = inDenominator;

	for (int i = simplifiedResult.numerator * simplifiedResult.denominator; i > 1; i--) {
		if ((simplifiedResult.numerator % i == 0) && (simplifiedResult.denominator % i == 0))
		{
			simplifiedResult.numerator /= i;
			simplifiedResult.denominator /= i;
		}
	}
	return simplifiedResult;
}