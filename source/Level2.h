#pragma once
#include "crossword_display.h"
#include "letters.h"

//level 2///////////////////////////////////////
bool level2()
{
	crossword_board test;
	crossword cw;
	string prevGuess[10];
	bool check_complete = false;

	//false = vertical
	//true = across
	test.add_word("judged", 5, 0, true);
	test.add_word("dud", 5, 2, false);
	test.add_word("dude", 7, 2, true);
	test.add_word("due", 5, 5, false);
	test.add_word("judge", 0, 4, false);
	test.add_word("jug", 0, 4, true);

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
