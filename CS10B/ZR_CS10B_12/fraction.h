/*
Zachary Robinson, CS10B, 5/1/2019, Dave Harden, ZR_CS10B_11

Fraction class representing fractions, whole numbers, and mixed numbers with three data members for the numerator,
denominator and integers. Contains functions for tesing arithmetic, binary arithmetic, shorthand arithmetic, and
decrement/increment operations. Reduces and simplifies mixed numbers and all fractions when taking input and 
calculating. Arithmetic functions do notmodify passed variables besides the increment/decrement operators


	Fraction(int inNumerator = 0, int inDenominator = 1);

	pre: There are no pre-conditions.
	post: [The integers, numerator and denominator are equal to the reduced version of the passed values, or defaulted to
	0, 0, 1.]


	friend Fraction operator+(const Fraction& left, const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns the simplified sum of two Fractions.]


	friend Fraction operator-(const Fraction& left, const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns the simplified difference of two Fractions.]


	friend Fraction operator*(const Fraction& left, const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns the simplified product two Fractions.]


	friend Fraction operator/(const Fraction& left, const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns the simplified quotient of two Fractions.]


	friend std::ostream& operator<<(std::ostream& out, const Fraction& right);

	pre: There are no pre-conditions.
	post: [Prints Fractions in reduced form, improper fractions are printed as a mixed number.]


	friend std::istream& operator>>(std::istream& in, Fraction& right);

	pre: No spaces, only the integer may be negative in mixed numbers, denominator cannot be negative in fractions.
	post: [Returns the passed input stream while inserting the read numbers into a Fraction.]


	friend bool operator<(const Fraction& left, const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns true or false based on if the left operand is less than the right.]


	friend bool operator>(const Fraction& left, const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns true or false based on if the left operand is greater than the right.]


	friend bool operator<=(const Fraction& left, const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns true or false based on if the left operand is less than or equal to the right.]


	friend bool operator>=(const Fraction& left, const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns true or false based on if the left operand is greater than or equal to the right.]


	friend bool operator==(const Fraction& left, const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns true or false based on if the left operand is equal to the right.]


	friend bool operator!=(const Fraction& left, const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns true or false based on if the left operand is not equal to the right.]


	Fraction operator+=(const Fraction& right);

	pre: Only Fractions can be the calling object, no integers.
	post: [Returns the  sum of the integer or Fraction on the right and the calling object.]


	Fraction operator-=(const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns the  difference of the integer or Fraction on the right and the calling object.]


	Fraction operator*=(const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns the  product of the integer or Fraction on the right and the calling object.]


	Fraction operator/=(const Fraction& right);

	pre: There are no pre-conditions.
	post: [Returns the quotient of the integer or Fraction on the right and the calling object.]


	Fraction operator++();

	pre: There are no pre-conditions.
	post: [Adds one to the calling object then returns it.]


	Fraction operator++(int);

	pre: There are no pre-conditions.
	post: [Returns the calling object then adds 1 to it.]


	Fraction operator--();

	pre: There are no pre-conditions.
	post: [Subtracts one from the calling object then returns it.]


	Fraction operator--(int);

	pre: There are no pre-conditions.
	post: [Returns the calling object then subtracts 1 from it.]


*/

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

namespace cs_fraction {
	class Fraction {
	public:
		Fraction(int inNumerator = 0, int inDenominator = 1);
		friend Fraction operator+(const Fraction& left, const Fraction& right);
		friend Fraction operator-(const Fraction& left, const Fraction& right);
		friend Fraction operator*(const Fraction& left, const Fraction& right);
		friend Fraction operator/(const Fraction& left, const Fraction& right);
		friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
		friend std::istream& operator>>(std::istream& in, Fraction& right);
		friend bool operator<(const Fraction& left, const Fraction& right);
		friend bool operator>(const Fraction& left, const Fraction& right);
		friend bool operator<=(const Fraction& left, const Fraction& right);
		friend bool operator>=(const Fraction& left, const Fraction& right);
		friend bool operator==(const Fraction& left, const Fraction& right);
		friend bool operator!=(const Fraction& left, const Fraction& right);
		Fraction operator+=(const Fraction& right);
		Fraction operator-=(const Fraction& right);
		Fraction operator*=(const Fraction& right);
		Fraction operator/=(const Fraction& right);
		Fraction operator++();
		Fraction operator++(int);
		Fraction operator--();
		Fraction operator--(int);
		
	private:
		void simplify();
		int integers;
		int numerator;
		int denominator;
	};
}

#endif

/*
----- Testing basic Fraction creation & printing
(Fractions should be in reduced form, and as mixed numbers.)
Fraction [0] = 1/2
Fraction [1] = -5/7
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+2/3
Fraction [6] = 0

----- Now reading Fractions from file
Read Fraction = 1/3
Read Fraction = 1/2
Read Fraction = 3/4
Read Fraction = -4/5
Read Fraction = 6
Read Fraction = 5
Read Fraction = 1+2/5
Read Fraction = -16+2/3
Read Fraction = 1+1/4
Read Fraction = 2
Read Fraction = -4+1/4
Read Fraction = -10+5/6

----- Testing relational operators between Fractions
Comparing 1/2 to 1/2
		Is left < right? false
		Is left <= right? true
		Is left > right? false
		Is left >= right? true
		Does left == right? true
		Does left != right ? false
Comparing 1/2 to -1/2
		Is left < right? false
		Is left <= right? false
		Is left > right? true
		Is left >= right? true
		Does left == right? false
		Does left != right ? true
Comparing -1/2 to 1/10
		Is left < right? true
		Is left <= right? true
		Is left > right? false
		Is left >= right? false
		Does left == right? false
		Does left != right ? true
Comparing 1/10 to 0
		Is left < right? false
		Is left <= right? false
		Is left > right? true
		Is left >= right? true
		Does left == right? false
		Does left != right ? true
Comparing 0 to 0
		Is left < right? false
		Is left <= right? true
		Is left > right? false
		Is left >= right? true
		Does left == right? true
		Does left != right ? false

----- Testing relations between Fractions and integers
Comparing -1/2 to 2
		Is left < right? true
		Is left <= right? true
		Is left > right? false
		Is left >= right? false
		Does left == right? false
		Does left != right ? true
Comparing -3 to 1/4
		Is left < right? true
		Is left <= right? true
		Is left > right? false
		Is left >= right? false
		Does left == right? false
		Does left != right ? true

----- Testing binary arithmetic between Fractions
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

----- Testing arithmetic between Fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on Fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3

C:\Users\Zack\source\repos\Project32\Debug\Project32.exe (process 7828) exited w
ith code 0.
Press any key to close this window . . .
*/