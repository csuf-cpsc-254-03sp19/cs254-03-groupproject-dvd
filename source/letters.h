
#include <iostream>

#include <iomanip>

#include <cstring>

using namespace std;


class crossword

{

private:

public:
	void display();
	void display2();
	void display3();
	void display4();
	void display5();
};

void crossword::display()
{
	cout << "\n" << setw(7) << "-------letters available for level 1 -------" << endl;
	cout << "the letter avaible is : o h o p t n \n";

}
void crossword::display2() {
	cout << "\n" << setw(7) << "-------letters available for level 2 -------" << endl;
	cout << "the letter avaible is : o h o p t n \n";

}
void crossword::display3() {
	cout << "\n" << setw(7) << "-------letters available for level 3 -------" << endl;
	cout << "the letter avaible is : k o s p t u \n";

}
void crossword::display4() {
	cout << "\n" << setw(7) << "-------letters available for level 4 -------" << endl;
	cout << "the letter avaible is : k o s p t u \n";

}
void crossword::display5() {
	cout << "\n" << setw(7) << "-------letters available for level 5 -------" << endl;
	cout << "the letter avaible is : k o s p t u \n";

}
