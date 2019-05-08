#include <iostream>
#include <string>
#include "Level1.h"

using namespace std;

int main()
{
	int user_input;
	string level_code;
	bool level_1_complete = false;
	bool level_2_complete = false;
	bool level_3_complete = false;
	cout << "Welcome to Word Maker" << endl;
	cout << endl;
	cout << "1) Start New Game" << endl;
	cout << "2) Enter in level code" << endl;
	cout << "3) Exit" << endl;
	cin >> user_input;
	
	while(user_input < 1 || user_input > 3)
	{
		cout << "Error: Invalid input please try again: ";
		cin >> user_input;
	}
	
	while(user_input == 2)
	{
		cout << "Please enter in a level code: ";
		cin >> level_code;
		if(level_code == "level_2")
		{
			level_1_complete = true;
			user_input = 1;
		}
		else if(level_code == "level_3")
		{
			level_1_complete = true;
			level_2_complete = true;
			user_input = 1;
		}
		else
		{
			cout << "Error: Not a valid code" << endl;
			cout << endl;
			cout << "1) Start New Game" << endl;
			cout << "2) Enter in level code" << endl;
			cout << "3) Exit" << endl;
			cin >> user_input;
			while(user_input < 1 || user_input > 3)
			{
				cout << "Error: Invalid input please try again: ";
				cin >> user_input;
			}
		}
	}
	
	if(user_input == 3)
	{
		cout << "Thank you for playing" << endl;
		return 0;
	}
	while(level_1_complete == false)
	{
		level_1_complete = level1();
		if(level_1_complete == false)
		{
			return 0;
		}
	}
	/*while(level_2_complete == false)
	{
		level_2_complete = level_2();
		if(level_2_complete == false)
		{
			return 0;
		}
	}
	while(level_3_complete == false)
	{
		level_3_complete = level_3();
		if(level_3_complete == false)
		{
			return 0;
		}
	}*/
	
	return 0;
}
