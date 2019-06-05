/*
Zachary Robinson, CS10B, 5/2/2019, Dave Harden, ZR_CS10B_13

MyString class representing capable of handling strings and c-strings. Actual data member is a pointer, the
constructors build dynamic arrays that are assigned to the pointer. Contains functions for acessing members of the
dynamic array, inputting and outputting with streams, the "big-3" functions for dynamic memory, and relational 
operators to compare strings.


		MyString();

		pre: There are no pre-conditions.
		post:[C-string is constructed to an empty dynamic array with a null terminator.]

		MyString(const char *inString);

		pre: There are no pre-conditions.
		post:[C-string is constructed to the inString with a null terminator.]

		
		void setString(const char *inString);

		pre: There are no pre-conditions.
		post:[C-string is updated to the inString with a null terminator.]

		
		int length() const;

		pre: There are no pre-conditions.
		post:[Returns the length of c-string.]

		
		char operator[](int index) const;

		pre: Index must be inside the bound of the c-string array.
		post:[Returns the value of the member of the array specified by index.]

		
		char& operator[](int index);

		pre: Index must be inside the bound of the c-string array.
		post:[Returns a reference to the member of the array specified by index.]

		
		friend std::ostream& operator<<(std::ostream& out, const MyString& right);

		pre: There are no pre-conditions.
		post: [Outputs c-string to an output stream and returns the stream.]

		
		friend std::istream& operator>>(std::istream& in, MyString& right);

		pre: C-strings created by this function may never have more than 127 characters.
		post:[Reads an in stream into c-string using the extraction operator, stops on whitespace, returns the stream.]

		
		friend bool operator<(const MyString& left, const MyString& right);

		pre: There are no pre-conditions.
		post:[Returns true or false based on if the left operand is less than the right.]

		
		friend bool operator>(const MyString& left, const MyString& right);

		pre: There are no pre-conditions.
		post:[Returns true or false based on if the left operand is greater than the right.]

		
		MyString operator= (const MyString& right);	//Assignment operator

		pre: There are no pre-conditions.
		post:[Returns true or false based on if the left operand is equal to the right.]

		
		MyString(const MyString& right);	//Copy constructor

		pre:There are no pre-conditions.
		post:[Overides default copy mechanism and makes a deep copy of c-string.]

		
		~MyString();	//Destructor

		pre: C-string is initialized.
		post:[C-string is deleted.]

		
		friend MyString operator+(const MyString& left, const MyString& right);

		pre: There are no pre-conditions.
		post:[Returns the right string added to the left string.]

		
		MyString operator+=(const MyString& right);

		pre: There are no pre-conditions.
		post:[Returns the right string added to the calling string.]

		
		friend bool operator<=(const MyString& left, const MyString& right);

		pre: There are no pre-conditions.
		post:[Returns true or false based on if the left operand is less than or equal to the right.]

		
		friend bool operator>=(const MyString& left, const MyString& right);

		pre: There are no pre-conditions.
		post:[Returns true or false based on if the left operand is greater than or equal to the right.]

		
		friend bool operator==(const MyString& left, const MyString& right);

		pre: There are no pre-conditions.
		post:[Returns true or false based on if the left operand is equal to the right.]
		
		friend bool operator!=(const MyString& left, const MyString& right);

		pre: There are no pre-conditions.
		post:[Returns true or false based on if the left operand is not equal to the right.]

		
		void read(std::istream& in, const char inChar);

		pre: There are no pre-conditions.
		post:[Reads into c-string from an input stream until the inChar is met or the end of the file is reached.]

		

*/
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

namespace cs_mystring {
	class MyString {
	public:
		MyString();
		MyString(const char *inString);
		void setString(const char *inString);
		int length() const;
		char operator[](int index) const;
		char& operator[](int index);
		friend std::ostream& operator<<(std::ostream& out, const MyString& right);
		friend std::istream& operator>>(std::istream& in, MyString& right);
		friend bool operator<(const MyString& left, const MyString& right);
		friend bool operator>(const MyString& left, const MyString& right);
		MyString operator= (const MyString& right);	//Assignment operator
		MyString(const MyString& right);	//Copy constructor
		~MyString();	//Destructor
		friend MyString operator+(const MyString& left, const MyString& right);
		MyString operator+=(const MyString& right);
		friend bool operator<=(const MyString& left, const MyString& right);
		friend bool operator>=(const MyString& left, const MyString& right);
		friend bool operator==(const MyString& left, const MyString& right);
		friend bool operator!=(const MyString& left, const MyString& right);
		void read(std::istream& in, const char inChar);
		


	private:
		char *cstring;
	};
}
#endif

/*
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Now reading MyStrings from file

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next
Read string = we read whole lines

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between MyStrings
Comparing app to apple
		Is left < right? true
		Is left <= right? true
		Is left > right? false
		Is left >= right? false
		Does left == right? false
		Does left != right ? true
Comparing apple to
		Is left < right? false
		Is left <= right? false
		Is left > right? true
		Is left >= right? true
		Does left == right? false
		Does left != right ? true
Comparing  to Banana
		Is left < right? true
		Is left <= right? true
		Is left > right? false
		Is left >= right? false
		Does left == right? false
		Does left != right ? true
Comparing Banana to Banana
		Is left < right? false
		Is left <= right? true
		Is left > right? false
		Is left >= right? true
		Does left == right? true
		Does left != right ? false

----- Testing relations between MyStrings and char *
Comparing he to hello
		Is left < right? true
		Is left <= right? true
		Is left > right? false
		Is left >= right? false
		Does left == right? false
		Does left != right ? true
Comparing why to wackity
		Is left < right? false
		Is left <= right? false
		Is left > right? true
		Is left >= right? true
		Does left == right? false
		Does left != right ? true

----- Testing concatentation on MyStrings
outrageous + milk = outrageousmilk
milk +  = milk
 + cow = cow
cow + bell = cowbell

----- Testing concatentation between MyString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

----- Testing shorthand concat/assign on MyStrings
who += what = whowhatandwhowhat
what += WHEN = whatWHENandwhatWHEN
WHEN += Where = WHENWhereandWHENWhere
Where += why = WherewhyandWherewhy

----- Testing shorthand concat/assign using char *
I love  += programming = I love programming

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo

C:\Users\Zack\source\repos\Project33\Debug\Project33.exe (process 8124) exited w
ith code 0.
Press any key to close this window . . .
*/