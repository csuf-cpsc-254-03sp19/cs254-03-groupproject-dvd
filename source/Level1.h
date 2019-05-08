#pragma once
#include "crossword_display.h"
#include "letters.h"

//level 1///////////////////////////////////////
bool level1()
{
	crossword_board test;
	crossword cw;
	string prevGuess[10];
	bool check_complete = false;

	test.add_word("photon", 0, 3, false);
	test.add_word("opt", 0, 2, true);
	test.add_word("hoot", 2, 1, true);
	test.add_word("hop", 2, 1, false);
	test.add_word("photo", 4, 1, true);
	test.add_word("hot", 3, 5, false);
	test.add_word("hoop", 3, 5, true);
	test.add_word("onto", 0, 7, false);
	test.add_word("not", 1, 7, true);

	int i = -1;
	while (check_complete == false)
	{
		string word;
		i++;
	
		word = test.user_guess(cw);//check if user's word is on the board
		prevGuess[i] = word;
		cout << "Past attempts: ";
		for (int j = 0; j < 10; j++)
		{
			cout << prevGuess[j] << " ";
		}
		cout << endl << endl;
		if (i == 9) //resets i to start at first index for previously guessed
		{
			i = -1;
		}
		test.print_user_board(); //print the board again to make updates
		if (word == "quit!")
		{
			return false;
		}
	}
	return true;
}
/////////////////////////////////////////////////
