#include "crossword_display.h"

bool level2()
{
	crossword_board level2;
	crossword cw;
	string prevGuess[10];
	bool check_complete = false;

	cout << "Level 2 Return Code: level_2"; //displays jump code for the user

	//false = vertical
	//true = across
	level2.add_word("fitter", 0, 2, true);
	level2.add_word("fir", 0, 2, false);
	level2.add_word("tie", 0, 5, false);
	level2.add_word("rite", 2, 2, true);
	level2.add_word("tire", 2, 4, false);
	level2.add_word("trite", 5, 0, true);
	level2.add_word("fit", 3, 0, false);
	level2.add_word("rift", 4, 4, true);

	int i = -1;
	while (check_complete == false)
	{
		string word;
		i++;
	
		word = level2.user_guess(cw);//check if user's word is on the board
		prevGuess[i] = word; //stores user's guessed word

		cout << "Past attempts: ";
		for (int j = 0; j < 10; j++)
		{
			cout << prevGuess[j] << " "; //displays the user's past 10 guesses
		}

		cout << endl << endl;

		if (i == 9) //resets i to start at first index for previously guessed
		{
			i = -1;
		}
		if (word == "quit!") //quit option
		{
			return false;
		}

		check_complete = level2.is_complete(); //signals the end of the level

	}
	return true;
}
