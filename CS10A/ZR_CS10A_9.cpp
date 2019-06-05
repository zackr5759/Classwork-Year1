#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream infile; //Define an input file stream, and our variables
	string filename;
	int wordCount;



	while (filename != "Q" && filename != "q") { //Entire program in a while loop to test for quitting.

		cout << "Enter file name or enter (Q) to quit: ";
		cin >> filename;

		infile.open(filename); //Associate the stream variable with our actual file.

		if (!infile) { //If the stream wasn't able to open the file, this error plays.
			if (filename != "Q" && filename != "q") {
				cout << "couldn't open file." << endl;
				
			}
		}
		else {
			wordCount = 0;
			infile >> filename; //Stream reads the txt file.
			while (infile) { //Loop increments word count whenever the stream reaches a new string.
				wordCount++;
				infile >> filename; //Read txt file inside the loop.
			}
			cout << "There are " << wordCount << " words." << endl;
			infile.close(); //We need to close the file or we wont be able to open another.
		}

		
	}
	cout << "Goodbye!" << endl;
/*
Enter file name or enter (Q) to quit: file1.txt
There are 7 words.
Enter file name or enter (Q) to quit: file2.txt
There are 10 words.
Enter file name or enter (Q) to quit: file3.txt
There are 21 words.
Enter file name or enter (Q) to quit: file4.txt
There are 19 words.
Enter file name or enter (Q) to quit: file5.txt
There are 22 words.
Enter file name or enter (Q) to quit: Q
Goodbye!
*/
}