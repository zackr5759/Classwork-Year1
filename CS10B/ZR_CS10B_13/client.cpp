
#include "mystring.h"
#include <fstream>
#include <cctype> 
#include <string>     
#include <cassert>
#include <iostream>
using namespace std;
using namespace cs_mystring;

void PalindromeTest();

bool isAPalindrome(MyString inString, int boundL, int boundR);

int main()
{
	PalindromeTest();
}

void PalindromeTest()
{
	MyString s;
	char temp[127];

	cout << "----- Testing palindromes" << endl;
	cout << "Enter a string: ";
	cin.getline(temp, 128);
	s.setString(temp);
	

	while (s != "quit")
	{
		if (isAPalindrome(s, 0, (s.length()) - 1) == true)
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
		cout << "Enter a string: ";
		cin.getline(temp, 128);
		s.setString(temp);
	}
}





bool isAPalindrome(MyString inString, int boundL, int boundR)
{
	while (ispunct(inString[boundL]) || isspace(inString[boundL]))
	{
		boundL++;
	}
	while (ispunct(inString[boundR]) || isspace(inString[boundR]))
	{
		boundR--;
	}

	if (boundL < boundR)
	{
		if (toupper(inString[boundL]) == toupper(inString[boundR]))
		{
			boundL++;
			boundR--;
		}
		else
		{
			return false;
		}

		return isAPalindrome(inString, boundL, boundR);;
	}

	return true;
}