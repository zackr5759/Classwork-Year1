#include <iostream>
using namespace std;


int lastIndexOf(const char* inString, char target);	//Checks each character against the target and return the place of the last location.

void reverse(char* inString);	//Flips the c-strings by replacing the first and (last minus one) characters to avoid the closing char.

int replace(char* inString, char target, char replacementChar);	//Similar to lastIndexOf but just replaces the target instead. 

bool isPalindrome(const char* inString);	//Checks if the first and (last minus one) characters are the same, then moves inwards
											//one slot both directions and checks again.

void toupper(char* inString);				//Replaces all characters in the inString with their uppercase version.

int numLetters(const char* inString);		//Called by several other functions to get the length of the c-strings. I could have
											//accounted for the closing char in c-strings here but decided to do it in the other functions.

int main()
{
	char str1[] = "Hello World";	//A few random strings, a few palindromes, some that are close, one with all alpha characters.
	char str2[] = "C++ is fun!";
	char str3[] = "Racecar";
	char str4[] = "racecar";
	char str5[] = "taco cat";
	char str6[] = "TacocAt";
	char str7[] = "The quick brown fox jumps over the laxy dog";
	char str8[] = "haN Nah";
	char str9[] = "haN nah";
	char str10[] = "C++ is usually fun!";


	cout << "The last 'l' in \"" << str1 << "\" is in slot " << lastIndexOf(str1, 'l') + 1 << endl;	//Plus one otherwise first slot would be 0;
	cout << "The last 'r' in \"" << str3 << "\" is in slot " << lastIndexOf(str3, 'r') + 1 << endl;
	cout << "The last 't' in \"" << str5 << "\" is in slot " << lastIndexOf(str5, 't') + 1 << endl;
	cout << "The last 'T' in \"" << str6 << "\" is in slot " << lastIndexOf(str6, 'T') + 1 << endl;
	cout << "The last 'N' in \"" << str8 << "\" is in slot " << lastIndexOf(str8, 'N') + 1 << endl;
	cout << "The last 'N' in \"" << str9 << "\" is in slot " << lastIndexOf(str9, 'N') + 1 << endl;

	cout << endl;


	cout << "\"" << str1 << "\" is ";	//Reversing and printing to console.
	reverse(str1);
	cout << str1 << " backwards." << endl;

	cout << "\"" << str2 << "\" is ";
	reverse(str2);
	cout << str2 << " backwards." << endl;

	cout << "\"" << str3 << "\" is ";
	reverse(str3);
	cout << str3 << " backwards." << endl;

	cout << "\"" << str4 << "\" is ";
	reverse(str4);
	cout << str4 << " backwards." << endl;

	cout << "\"" << str5 << "\" is ";
	reverse(str5);
	cout << str5 << " backwards." << endl;

	cout << "\"" << str6 << "\" is ";
	reverse(str6);
	cout << str6 << " backwards." << endl;

	cout << "\"" << str7 << "\" is ";
	reverse(str7);
	cout << str7 << " backwards." << endl;

	cout << "\"" << str8 << "\" is ";
	reverse(str8);
	cout << str8 << " backwards." << endl;

	cout << "\"" << str8 << "\" is ";
	reverse(str8);
	cout << str8 << " backwards." << endl;

	cout << "\"" << str9 << "\" is ";
	reverse(str9);
	cout << str9 << " backwards." << endl;

	cout << "\"" << str10 << "\" is ";
	reverse(str10);
	cout << str10 << " backwards." << endl << endl;
	

	reverse(str1);	//Reverse all back to normal.
	reverse(str2);
	reverse(str3);
	reverse(str4);
	reverse(str5);
	reverse(str6);
	reverse(str7);
	reverse(str8);
	reverse(str9);
	reverse(str10);

	replace(str1, 'l', 'L');	//Running our replace function for all strings.
	replace(str2, '+', '-');
	replace(str3, 'r', 't');
	replace(str4, 'c', 'g');
	replace(str5, ' ', '!');
	replace(str6, 'T', 'P');
	replace(str7, ' ', '.');
	replace(str8, 'N', 'n');
	replace(str9, 'h', 'B');
	replace(str10, 'f', 'r');

	cout << str1 << endl;	//Print to console.
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;
	cout << str7 << endl;
	cout << str8 << endl;
	cout << str9 << endl;
	cout << str10 << endl;

	cout << endl;

	replace(str1, 'L', 'l');	//Putting the strings back to normal.
	replace(str2, '-', '+');
	replace(str3, 't', 'r');
	replace(str4, 'g', 'c');
	replace(str5, '!', ' ');
	replace(str6, 'p', 'T');
	replace(str7, '.', ' ');
	replace(str8, 'n', 'N');
	replace(str9, 'b', 'h');
	replace(str10, 'r', 'f');
	
	if (isPalindrome(str1) == true)	//Check for palindromes.
	{
		cout << "\"" << str1 << "\" is a palindrome" << endl;
	} else cout << "\"" << str1 << "\" is not a palindrome" << endl;

	if (isPalindrome(str3) == true)
	{
		cout << "\"" << str3 << "\" is a palindrome" << endl;
	}
	else cout << "\"" << str3 << "\" is not a palindrome" << endl;

	if (isPalindrome(str4) == true)
	{
		cout << "\"" << str4 << "\" is a palindrome" << endl;
	}
	else cout << "\"" << str4 << "\" is not a palindrome" << endl;

	if (isPalindrome(str5) == true)
	{
		cout << "\"" << str5 << "\" is a palindrome" << endl;
	}
	else cout << "\"" << str5 << "\" is not a palindrome" << endl;

	if (isPalindrome(str6) == true)
	{
		cout << "\"" << str6 << "\" is a palindrome" << endl;
	}
	else cout << "\"" << str6 << "\" is not a palindrome" << endl;

	if (isPalindrome(str8) == true)
	{
		cout << "\"" << str8 << "\" is a palindrome" << endl;
	}
	else cout << "\"" << str8 << "\" is not a palindrome" << endl;

	if (isPalindrome(str9) == true)
	{
		cout << "\"" << str9 << "\" is a palindrome" << endl;
	}
	else cout << "\"" << str9 << "\" is not a palindrome" << endl;

	cout << endl;

	toupper(str1);	//All c-strings into uppercase.
	toupper(str2);
	toupper(str3);
	toupper(str4);
	toupper(str5);
	toupper(str6);
	toupper(str7);
	toupper(str8);
	toupper(str9);
	toupper(str10);

	cout << str1 << endl;	//Print to console.
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;
	cout << str7 << endl;
	cout << str8 << endl;
	cout << str9 << endl;
	cout << str10 << endl;



	cout << endl << endl;
}







int lastIndexOf(const char* inString, char target)
{
	int index = -1;	
	int count = 0;

	while (inString[count] != '\0')	//Used throughout many functions to terminate loops with c-strings with closing char.
	{

		if (inString[count] == target)
		{
			index = count;
		}
		count++;
	}
	return index;

}





void reverse(char* inString)
{
	char temp;
	
	for (int i = 0; i < (numLetters(inString) / 2); i++)	//Works perfectly that c++ leaves of the remainder, 
	{														//odd functions can keep the middle char.
		temp = inString[i];
		inString[i] = inString[(numLetters(inString) - i) - 1];	//The minus one to deal with the closing char.
		inString[(numLetters(inString) - i) - 1] = temp;
	}
}







int replace(char* inString, char target, char replacementChar)
{
	int count = 0;
	int i = 0;	//This function returning an int seemed pointless but I just used i to keep track
				//of if 0 was to be returned or not.

	while (inString[count] != '\0')
	{

		if (inString[count] == target)
		{
			inString[count] = replacementChar;
			i++;
		}
		count++;
	}
	return i;

}





bool isPalindrome(const char* inString)
{
	{
		for (int i = 0; i < (numLetters(inString) / 2); i++)	//Same logic as reverse function just check if they aren't equal and dont move anything.
		{
			if (inString[i] != inString[(numLetters(inString) - i) - 1])
			{
				return false;
			}

		}	return true;
	}
}






void toupper(char* inString)
{
	int count = 0;

	while (inString[count] != '\0')
	{
		inString[count] = toupper(inString[count]);	//Very simply replaces each char with its uppercase version.
		count++;
	}
}








int numLetters(const char* inString)
{
	int count = 0;
	while (inString[count] != '\0')	//Called by the functions that needed to know the size of the arrays I guess I could
									//have printed the amount of chars for each array to the console but it seemed overkill.
	{
		count++;
	}
	return count;
} 

/*
The last 'l' in "Hello World" is in slot 10
The last 'r' in "Racecar" is in slot 7
The last 't' in "taco cat" is in slot 8
The last 'T' in "TacocAt" is in slot 1
The last 'N' in "haN Nah" is in slot 5
The last 'N' in "haN nah" is in slot 3

"Hello World" is dlroW olleH backwards.
"C++ is fun!" is !nuf si ++C backwards.
"Racecar" is racecaR backwards.
"racecar" is racecar backwards.
"taco cat" is tac ocat backwards.
"TacocAt" is tAcocaT backwards.
"The quick brown fox jumps over the laxy dog" is god yxal eht revo spmuj xof nwo
rb kciuq ehT backwards.
"haN Nah" is haN Nah backwards.
"haN Nah" is haN Nah backwards.
"haN nah" is han Nah backwards.
"C++ is usually fun!" is !nuf yllausu si ++C backwards.

HeLLo WorLd
C-- is fun!
Racecat
ragegar
taco!cat
PacocAt
The.quick.brown.fox.jumps.over.the.laxy.dog
han nah
BaN naB
C++ is usually run!

"Hello World" is not a palindrome
"Racecar" is not a palindrome
"racecar" is a palindrome
"taco cat" is not a palindrome
"PacocAt" is not a palindrome
"haN Nah" is a palindrome
"BaN naB" is not a palindrome

HELLO WORLD
C++ IS FUN!
RACECAR
RACECAR
TACO CAT
PACOCAT
THE QUICK BROWN FOX JUMPS OVER THE LAXY DOG
HAN NAH
BAN NAB
C++ IS USUALLY FUN!

 */