#include <iostream>
#include <string>
#include "crossword_display.h"
#include "letters.h"

using namespace std;

int main()
{
	//level 1///////////////////////////////////////
	crossword_board test;
	cout << "Welcome to level 1\n";

	test.add_word("photon", 0, 3, false);
	test.add_word("opt", 0, 2, true);
	test.add_word("hoot", 2, 1, true);
	test.add_word("hop", 2, 1, false);
	test.add_word("photo", 4, 1, true);
	test.add_word("hot", 3, 5, false);
	test.add_word("hoop", 3, 5, true);
	test.add_word("onto", 0, 7, false);
	test.add_word("not", 1, 7, true);
	//test.print_board();
	/////////////////////////////////////////////////

	crossword cw;
	string prevGuess[10];// declare previous guess into array of 10
	string word;         //declare the word variable
	crossword cd;
	
	for (int i = 0; i < 10; i++)
	{
		string word;
		word = test.user_guess(cw);//return user guess word
		prevGuess[i] = word;				// assign the variable word to array of previousGuess[]
		cout << "Past attempts: ";	// showing the user pass attempt
		for (int j = 0; j < 10; j++)
		{
			cout << prevGuess[j] << ' '; // return preGuess[j]
		}
		cout << "\n";
		cout << endl;
		if (i == 9)
		{
			i = -1; // if the array is full, which is =10, it will now start from first index.
		}
	}
	cw.display();
	test.print_user_board();
	return 0;
}
