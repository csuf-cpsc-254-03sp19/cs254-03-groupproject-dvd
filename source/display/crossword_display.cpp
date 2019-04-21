#include <iostream>
#include <string>

using namespace std;

#define underline "\033[4m" 
#define stop_underline "\033[0m"
#define max_words 100

char **create_crossword(int num_rows, int num_col);

struct word_bank
{
	string word;
	int row_start;
	int col_start;
	bool direction;
	bool is_guessed;//This determines whether the user has guess the word or not
};

class crossword_board 
{
private:
	char board[22][42];//full board with every word displayed
	char user_board[22][42];//used to display what the user has guessed
	word_bank word_storage[max_words];//used to store words on the board
	int word_bank_size;//used to keep track of how many words we have
	
public:
	crossword_board();
	void add_word(string word, int row_start, int col_start, bool direction);
	//row_start is which row the word begins in, for direction True = across
	//False = down
	void print_board();
	void print_user_board();
};

int main()
{
	crossword_board test;
	test.add_word("apple", 4, 7, true);
	test.add_word("apple", 4, 7, false);
	test.print_board();
	test.print_user_board();
	return 0;
}

crossword_board::crossword_board()
{
	for (int i = 0; i < 42; i++)
	{
		board[0][i] = '_';
		user_board[0][i] = '_';
	}
	
	for (int i = 1; i < 21; i++)
	{
		for (int j = 0; j < 42; j++)
		{
			if ( j == 0 || j == 41)
			{
				board[i][j] = '|';
				user_board[i][j] = '|';
			}
			else
			{
				board[i][j] = ' ';
				user_board[i][j] = ' ';
			}
		}
	}
	
	for (int i = 0; i < 42; i++)
	{
		board[21][i] = '_';
		user_board[21][i] = '_';
	}
	
	//This is to initialize the word bank as empty
	for (int i = 0; i < max_words; i++)
	{
		word_storage[i].word = "";
		word_storage[i].row_start = 0;
		word_storage[i].col_start = 0;
		word_storage[i].direction = true;
		word_storage[i].is_guessed = false;
	}
	word_bank_size = 0;
}

void crossword_board::add_word(string word, int row_start, int col_start, bool direction)
{
	int row_insert = row_start + 1;//since we have a box need to increment 1 over
	int col_insert = col_start + 1;
	int word_length = word.length();
	int current_letter = 0;
	if (direction == false)//this stores for words that are down
	{
		for (int i = row_insert; i < word_length + row_insert; i++)
		{
			board[i][col_insert] = word[current_letter];
			user_board[i][col_insert] = '_';//for every letter put into board we put a blank
			current_letter++;
		}
	}
	else if (direction == true)
	{
		for (int i = col_insert; i < word_length + col_insert; i++)
		{
			board[row_insert][i] = word[current_letter];
			user_board[row_insert][i] = '_';//for every letter put into board we put a blank
			current_letter++;
		}
	}
	
	//here we store the new word in the word bank array
	//change names if u feel it is too confusing with same names
	word_storage[word_bank_size].word = word;
	word_storage[word_bank_size].row_start = row_start;
	word_storage[word_bank_size].col_start = col_start;
	word_storage[word_bank_size].direction = direction;
	word_bank_size++;
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

void crossword_board::print_user_board()
{
	for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 42; j++)
			{
				if (user_board[i][j] >= 97 && user_board[i][j] <= 122)
				{
					cout << underline << user_board[i][j];
				}
				else
				{
					cout << stop_underline << user_board[i][j];
				}
			}
			cout << endl;
		}
}
