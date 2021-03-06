#include <iostream>
#include <string>
//#include "letters.h"

using namespace std;

#define underline "\033[4m" //used for display of crossword
#define stop_underline "\033[0m"
#define max_words 100 //max_words that are allowed in crossword

struct word_bank//used to keep track of words that have been guessed
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
	crossword_board();//constructor
	void add_word(string word, int row_start, int col_start, bool direction);
	//row_start is which row the word begins in, for direction True = across
	//False = down
	void print_board();//prints completed crossword
	void print_user_board();//prints what words the user has already guessed
	string user_guess();//asks user to guess the word
	void user_add_word(string word, int row_start, int col_start, bool direction);//if user guessed correctly it adds word to user_board
	bool is_complete();//checks if user has guessed every word
};

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
	int col_insert = 2 * col_start;
	int word_length = word.length();
	int current_letter = 0;
	if (direction == false)//this stores for words that are down
	{
		for (int i = row_insert; i < word_length + row_insert; i++)
		{
			board[i][col_insert] = word[current_letter];//inserts letters into board
			user_board[i][col_insert] = '_';//for every letter put into board we put a blank
			current_letter++;
		}
	}
	else if (direction == true)
	{
		for (int i = col_insert; i < 2 * word_length + col_insert; i++)
		{
			if(i%2 == 0)
			{
				board[row_insert][i] = word[current_letter];
				user_board[row_insert][i] = '_';//for every letter put into board we put a blank
				current_letter++;
			}
		}	
	}
	
	//here we store the new word in the word bank array
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
				if (board[i][j] >= 97 && board[i][j] <= 122)//used to check if char in array is a letter
				{
					cout << underline << board[i][j];//underlines letter
				}
				else
				{
					cout << stop_underline << board[i][j];//stops underlining empty spaces
				}
			}
			cout << endl;
		}
}

void crossword_board::print_user_board()//prints what words the user has already guessed
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
string crossword_board::user_guess()
{
	string guess;
	bool correct_word = false;//flag for if guessed corectly
	
	//displays board for the user
	print_user_board();
	cout << "Please enter in a word: ";
	cin >> guess;
	
	//if they guess correctly changes is_guessed in the word_storage to true
	for(int i = 0; i < word_bank_size; i++)
	{
		if(guess == word_storage[i].word)//loops through the word bank to check if the word is in it
		{
			word_storage[i].is_guessed = true;
			correct_word = true;
			user_add_word(word_storage[i].word, word_storage[i].row_start, word_storage[i].col_start, word_storage[i].direction);
		}
	}
	
	if(correct_word == true)
	{
		cout << guess << " is a correct word" << endl;
	}
	else
	{
		cout << guess << " is an incorrect word" << endl;
	}
	return guess;
}

void crossword_board::user_add_word(string word, int row_start, int col_start, bool direction)
{
	int row_insert = row_start + 1;//since we have a box need to increment 1 over
	int col_insert = col_start * 2;//want to have a space between letters horizantally so we double the number
	int word_length = word.length();
	int current_letter = 0;
	if (direction == false)//this stores for words that are down
	{
		for (int i = row_insert; i < word_length + row_insert; i++)
		{
			user_board[i][col_insert] = word[current_letter];
			current_letter++;
		}
	}
	else if (direction == true)
	{
		for (int i = col_insert; i < 2 * word_length + col_insert; i++)
		{
			if(i%2 == 0)//used so it only prints on even values horizantally
			{
				user_board[row_insert][i] = word[current_letter];
				current_letter++;
			}
		}
	}
}

bool crossword_board::is_complete()//determines if it is complete
{
	for(int i = 0; i < word_bank_size; i++)//loops through word_bank to determine if every word has been guessed
	{
		if(word_storage[i].is_guessed == false)
		{
			return false;
		}
	}
	print_board();
	cout << "Congratulations the level is complete" << endl;
	return true;
}
