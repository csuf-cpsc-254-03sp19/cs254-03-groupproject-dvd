#include <iostream>
#include <string>

using namespace std;

#define underline "\033[4m" 
#define stop_underline "\033[0m"

char **create_crossword(int num_rows, int num_col);

class crossword_board 
{
private:
	char board[22][42];
	
public:
	crossword_board();
	void add_word(string word, int row_start, int col_start, bool direction);
	//row_start is which row the word begins in, for direction True = across
	//False = down
	void print_board();
};

int main()
{
	crossword_board test;
	test.add_word("apple", 0, 0, true);
	test.add_word("apple", 0, 0, false);
	test.print_board();
	return 0;
}

crossword_board::crossword_board()
{
	for (int i = 0; i < 42; i++)
	{
		board[0][i] = '_';
	}
	
	for (int i = 1; i < 21; i++)
	{
		for (int j = 0; j < 42; j++)
		{
			if ( j == 0 || j == 41)
			{
				board[i][j] = '|';
			}
			else
			{
				board[i][j] = ' ';
			}
		}
	}
	
	for (int i = 0; i < 42; i++)
	{
		board[21][i] = '_';
	}
}

void crossword_board::add_word(string word, int row_start, int col_start, bool direction)
{
	int row_insert = row_start + 1;
	int col_insert = col_start + 1;
	int word_length = word.length();
	int current_letter = 0;
	if (direction == false)
	{
		for (int i = row_insert; i < word_length + row_insert; i++)
		{
			board[i][col_insert] = word[current_letter];
			current_letter++;
		}
	}
	else if (direction == true)
	{
		for (int i = col_insert; i < word_length + col_insert; i++)
		{
			board[row_insert][i] = word[current_letter];
			current_letter++;
		}
	}
}

void crossword_board::print_board()
{
	for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 42; j++)
			{
				if (board[i][j] >= 97 && board[i][j] <= 122)
				{
					cout << underline << board[i][j];
				}
				else
				{
					cout << stop_underline << board[i][j];
				}
			}
			cout << endl;
		}
}
