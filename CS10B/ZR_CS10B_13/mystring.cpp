/*
Zachary Robinson, CS10B, 5/2/2019, Dave Harden, ZR_CS10B_13

MyString class containin the c-string pointer data member to deal with c-string and strings. Strings have no size limit
unless entered by an input stream in which it is 127 characters.

*/

#pragma warning(disable:4996)

#include <iostream>
#include <fstream>
#include <cassert>
#include "mystring.h"
using namespace std;

namespace cs_mystring {


	MyString::MyString()
	{
		cstring = new char[1];
		strcpy(cstring, "");
	}





	MyString::MyString(const char *inString)
	{
		cstring = new char[strlen(inString) + 1];
		strcpy(cstring, inString);
	}






	void MyString::setString(const char *inString)
	{
		delete[] cstring;
		cstring = new char[strlen(inString) + 1];
		strcpy(cstring, inString);
	}






	int MyString::length() const
	{
		return strlen(cstring);
	}






	char MyString::operator[](int index) const	//Returns value
	{
		assert(index >= 0 && index < strlen(cstring));
		return cstring[index];
	}







	char& MyString::operator[](int index)	//Returns reference
	{
		assert(index >= 0 && index < strlen(cstring));
		return cstring[index];
	}






	std::ostream& operator<<(std::ostream& out, const MyString& right)
	{
		out << right.cstring;
		return out;
	}





	std::istream& operator>>(std::istream& in, MyString& right)
	{
		char temp[127];

		in >> temp;
		
		delete[] right.cstring;
		right.cstring = new char[strlen(temp) + 1];
		strcpy(right.cstring, temp);
		return in;
	}





	void MyString::read(std::istream& in, const char inChar)
	{
		char temp[127];

		in.getline(temp, 128, inChar);

		delete[] cstring;
		cstring = new char[strlen(temp) + 1];
		strcpy(cstring, temp);
	}





	MyString MyString::operator= (const MyString& right)
	{
		if (this != &right) {
			delete[] cstring;
			cstring = new char[strlen(right.cstring) + 1];
			strcpy(cstring, right.cstring);
		}
		return *this;
	}





	MyString::MyString(const MyString& right)
	{
		cstring = new char[strlen(right.cstring) + 1];
		strcpy(cstring, right.cstring);
	}





	MyString::~MyString()
	{
		delete[] cstring;
	}





	MyString operator+(const MyString& left, const MyString& right)
	{
		MyString answer;

		delete[] answer.cstring;
		answer.cstring = new char[strlen(left.cstring) + strlen(right.cstring) + 1];

		strcpy(answer.cstring, left.cstring);
		strcat(answer.cstring, right.cstring);

		return answer;
	}





	MyString MyString::operator+=(const MyString& right)
	{
		*this = *this + right;


		return *this;
	}




	
	bool operator<(const MyString& left, const MyString& right)
	{
		if (strcmp(left.cstring, right.cstring) < 0)	//All comparisons use ASCII values.
		{
			return true;
		}
		else return false;
	}







	bool operator>(const MyString& left, const MyString& right)
	{
		if (strcmp(left.cstring, right.cstring) > 0)
		{
			return true;
		}
		else return false;
	}





	bool operator<=(const MyString& left, const MyString& right)
	{
		if (strcmp(left.cstring, right.cstring) <= 0)
		{
			return true;
		}
		else return false;
	}







	bool operator>=(const MyString& left, const MyString& right)
	{
		if (strcmp(left.cstring, right.cstring) >= 0)
		{
			return true;
		}
		else return false;
	}







	bool operator==(const MyString& left, const MyString& right)
	{
		if (strcmp(left.cstring, right.cstring) == 0)
		{
			return true;
		}
		else return false;
	}







	bool operator!=(const MyString& left, const MyString& right)
	{
		if (strcmp(left.cstring, right.cstring) != 0)
		{
			return true;
		}
		else return false;
	}
}