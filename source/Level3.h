#include "crossword_display.h"

bool level3()
{
	crossword_board level3;
	crossword cw;
	string prevGuess[10];
	bool check_complete = false;

	cout << "Level 3 Return Code: level_3";
	//false = vertical
	//true = across
	level3.add_word("vector", 0, 2, true);
	level3.add_word("tore", 0, 5, false);
	level3.add_word("voter", 3, 2, true);
	level3.add_word("core", 2, 3, false);
	level3.add_word("cover", 5, 0, true);
	level3.add_word("rot", 5, 4, false);
	level3.add_word("ore", 6, 4, true);
	level3.add_word("rove", 3, 6, false);
	level3.add_word("vet", 5, 6, true);
	level3.add_word("covet", 1, 8, false);
	level3.add_word("cove", 1, 8, true);
	level3.add_word("over", 0, 10, false);
	level3.add_word("covert", 5, 0, false);

	int i = -1;
	while (check_complete == false)
	{
		string word;
		i++;
	
		word = level3.user_guess(cw);//check if user's word is on the board
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
		if (word == "quit!")
		{
			return false;
		}
		check_complete = level3.is_complete();

	}
	return true;
}
