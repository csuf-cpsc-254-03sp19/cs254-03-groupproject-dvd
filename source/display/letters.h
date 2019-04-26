#include <iostream>

#include <iomanip>

#include <cstring>

using namespace std;


class crossword

{

private:
	//available letters 

	char availLetters[2][11] = { {'a',' ', 'l',' ', 'e',' ', 'p',' ', 'p',' ','p'},
	

	 };
	

public:
	void userDisplay();
	void display();

};
void crossword::userDisplay()
{
	cout << "  ";
	cout << endl;
}
void crossword::display()
{
	cout << "\n" << setw(7) << "-------letters available-------" << endl;
	for (int i = 0; i < 2; i++)

	{

		for (int j = 0; j < 11; j++)

		{

			cout << availLetters[i][j];

		}

		cout << endl;

	}

}
