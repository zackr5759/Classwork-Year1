/*
Zachary Robinson, CS10B, 5/1/2019, Dave Harden, ZR_CS10B_11

A Fraction object has 3 data members: integers, numerator, and denominator; all three of these store ints to represent
values of mixed numbers. Fraction objects will always be stored in their simplified forms and will terminate the
program if attempting to equate the denominator to 0. Negative mixed numbers show up with a minus sign in front and 
no minus sign by the numerator. To do so, numerators are stored as positive in negative mixed numbers; the
arithmetic programs change them to negative before calculations. Negative denominators will be changed either through
the numerator becoming negative or canceling the two out. 
*/

#include <iostream>
#include <cassert>
#include "fraction.h"
using namespace std;

namespace cs_fraction {

	Fraction::Fraction(int inNumerator, int inDenominator)
	{
		assert(inDenominator != 0);

		integers = 0;
		numerator = inNumerator;
		denominator = inDenominator;
		simplify();
	}






	std::ostream& operator<<(ostream& out, const Fraction& right)
	{
		if (right.numerator == 0)	
		{
			out << right.integers;	//prints whole numbers
			return out;
		}
		else if (right.integers == 0)
		{
			out << right.numerator << "/" << right.denominator;	//prints fractions
			return out;
		}
		else
		{
			out << right.integers << "+" << right.numerator << "/" << right.denominator;	//prints mixed numbers
			return out;
		}

	}






	istream& operator>>(istream& in, Fraction& right)
	{
		int negativeMultiplier = 1;
		for (int count = 0; count < 3; count++)	//Loop for a max three possible ints to store.
		{
			int numbers = 0;
			if (in.peek() == '-')	
			{
				in.ignore();
				negativeMultiplier = -1;	//Deletes negative prefix and stores -1 to use it.
			}
			while (in && in.peek() != '/' && in.peek() != '+' && in.peek() != '\n')
			{
				in >> numbers;	//Read in the value.
			}
				if (in.peek() == '/' && numbers != 0)	//If followed by a / it must be a numerator.
				{
				right.numerator = numbers * negativeMultiplier;
				in.ignore();
				}
				else if (in.peek() == '+' && numbers != 0)	//If followed by a + it must be an integer.
				{
				right.integers = numbers * negativeMultiplier;
				in.ignore();
				}
				else if(count == 0 && numbers != 0)	//If its not followed by anything and
													//it's the first value, it's a whole number.
				{	
					right.integers = numbers * negativeMultiplier;
					in.ignore();
				}
				else if (count != 0 && numbers != 0)//If its not followed by anything and
													//it isn't the first value, it's the denominator.
				{
					right.denominator = numbers;
				}
		}
		right.simplify();
		return in;
	}






	bool operator<(const Fraction& left, const Fraction& right)
	{
		int temp = (left.numerator*right.denominator - left.denominator*right.numerator); 

		if (temp < right.integers) {	//Checks the difference of the cross multiplication.
			return true;
		} 

		if (left.integers > right.integers) {
			return false;
		}
		
		return temp < 0;
	}






	bool operator>(const Fraction& left, const Fraction& right)
	{
		int temp = (left.numerator*right.denominator - left.denominator*right.numerator);

		if (left.integers > right.integers) {	//Checks the difference of the cross multiplication.
			return true;
		}

		if (left.integers < right.integers) {
			return false;
		}
		return temp > 0;
	}



	bool operator<=(const Fraction& left, const Fraction& right)
	{
		int temp = (left.numerator*right.denominator - left.denominator*right.numerator);

		if (left.integers <= right.integers && temp == 0) {	//Checks the difference of the cross multiplication.	
			return true;
		}

		if (left.integers > right.integers) {
			return false;
		}
		return temp <= 0;
	}






	bool operator>=(const Fraction& left, const Fraction& right)
	{
		int temp = (left.numerator*right.denominator - left.denominator*right.numerator);

		if (left.integers >= right.integers && temp == 0) {	//Checks the difference of the cross multiplication.
			return true;
		}

		if (left.integers < right.integers) {
			return false;
		}
		return temp >= 0;
	}






	bool operator==(const Fraction& left, const Fraction& right)
	{
		int temp = (left.numerator*right.denominator - left.denominator*right.numerator);

		if (left.integers == right.integers && temp == 0) {	//Checks the difference of the cross multiplication.
			return true;
		}

		if (left.integers != right.integers) {
			return false;
		}
		return temp == 0;
	}






	bool operator!=(const Fraction& left, const Fraction& right)
	{
		int temp = (left.numerator*right.denominator - left.denominator*right.numerator);

		if (left.integers != right.integers) {	//Checks the difference of the cross multiplication.
			return true;
		}

		if (left.integers == right.integers && temp == 0) {
			return false;
		}
		return temp != 0;
	}






	Fraction operator+(const Fraction& left, const Fraction& right)
	{
		Fraction answer;
		Fraction tempL = left;
		Fraction tempR = right;

		if (tempL.integers < 0)	//Returns stored numerators in mixed numbers to negative state if necessary.
		tempL.numerator *= -1;
		if (tempR.integers < 0)
		tempR.numerator *= -1;

		tempL.numerator += (tempL.integers * tempL.denominator);	//Turns mixed numbers back to Fractions for easier calculation
		tempR.numerator += (tempR.integers * tempR.denominator);

		answer.numerator = ((tempL.numerator * tempR.denominator) + (tempL.denominator * tempR.numerator));
		answer.denominator = (tempL.denominator * tempR.denominator);

		answer.simplify();
		return answer;
	}






	Fraction operator-(const Fraction& left, const Fraction& right)
	{
		Fraction answer;
		Fraction tempL = left;
		Fraction tempR = right;

		if (tempL.integers < 0)	//Returns stored numerators in mixed numbers to negative state if necessary.
			tempL.numerator *= -1;
		if (tempR.integers < 0)
			tempR.numerator *= -1;

		tempL.numerator += (tempL.integers * tempL.denominator);	//Turns mixed numbers back to Fractions for easier calculation
		tempR.numerator += (tempR.integers * tempR.denominator);

		answer.numerator = ((tempL.numerator * tempR.denominator) - (tempL.denominator * tempR.numerator));
		answer.denominator = (tempL.denominator * tempR.denominator);

		answer.simplify();
		return answer;
	}






	Fraction operator*(const Fraction& left, const Fraction& right)
	{
		Fraction answer;
		Fraction tempL = left;
		Fraction tempR = right;

		if (tempL.integers < 0)	//Returns stored numerators in mixed numbers to negative state if necessary.
			tempL.numerator *= -1;
		if (tempR.integers < 0)
			tempR.numerator *= -1;
		
		tempL.numerator += (tempL.integers * tempL.denominator);	//Turns mixed numbers back to Fractions for easier calculation
		tempR.numerator += (tempR.integers * tempR.denominator);

		answer.numerator = tempL.numerator * tempR.numerator;
		answer.denominator = tempL.denominator * tempR.denominator;

		answer.simplify();
		return answer;
	}






	Fraction operator/(const Fraction& left, const Fraction& right)
	{
		Fraction answer;
		Fraction tempL = left;
		Fraction tempR = right;

		if (tempL.integers < 0)	//Returns stored numerators in mixed numbers to negative state if necessary.
			tempL.numerator *= -1;
		if (tempR.integers < 0)
			tempR.numerator *= -1;

		tempL.numerator += (tempL.integers * tempL.denominator);	//Turns mixed numbers back to Fractions for easier calculation
		tempR.numerator += (tempR.integers * tempR.denominator);
		

		answer.numerator = tempL.numerator * tempR.denominator;
		answer.denominator = tempL.denominator * tempR.numerator;

		answer.simplify();
		
		return answer;
	}







	Fraction Fraction::operator+=(const Fraction& right)
	{
		*this = *this + right;

		Fraction temp = *this;
		temp.simplify();
		return temp;
	}






	Fraction Fraction::operator-=(const Fraction& right)
	{
		*this = *this - right;

		Fraction temp = *this;
		temp.simplify();
		return temp;
	}






	Fraction Fraction::operator*=(const Fraction& right)
	{
		

		*this = *this * right;


		Fraction temp = *this;
		temp.simplify();
		return temp;
	}






	Fraction Fraction::operator/=(const Fraction& right)
	{

		*this = *this / right;


		Fraction temp = *this;
		temp.simplify();
		return temp;
	}





	Fraction Fraction::operator++()
	{
		numerator += denominator;
		simplify();
		return *this;
	}





	Fraction Fraction::operator++(int)
	{
		Fraction temp = *this;
		numerator += denominator;
		simplify();
		return temp;
	}






	Fraction Fraction::operator--()
	{
		numerator -= denominator;	//Slightly different than ++ to deal with the way mixed negative numbers are stored.
		simplify();
		return *this;
	}






	Fraction Fraction::operator--(int)
	{
		Fraction temp = *this;  
		numerator -= denominator;
		simplify();
		return temp;
	}







	void Fraction::simplify()
	{
		if (denominator < 0)	//Turns negative denominators positive while retaining the overall fraction's sign.
		{
			numerator = numerator * -1;
			denominator = abs(denominator);
		}

		for (int i = abs(numerator * denominator); i > 1; i--)	//Checks if the fraction can be reduced by any number 
																//from the highest common factor, to 2.
		{
			if ((numerator % i == 0) && (denominator % i == 0))
			{
				numerator /= i;
				denominator /= i;
			}
		}

		while (abs(numerator) >= denominator)	//Turns improper fractions into mixed numbers.
		{
			if (numerator > 0)
			{
				integers++;
				numerator -= denominator;
			}
			else
			{
				integers--;
				numerator += denominator;

			}
		}

		if (numerator < 0 && integers > 0)	//Handles simplifying negative numerators with postive integers.
		{
			numerator += denominator;
			integers--;
		}
		if (integers != 0 && numerator < 0)	//Makes sure that the numerator is positive in mixed numbers.
		{
			numerator = abs(numerator);
		}
		
	}
}




