
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
};

void crossword::display()
{
	cout << "\n" << setw(7) << "-------letters available for level 1 -------" << endl;
	cout << "the letter avaible is : a e l p p \n";

}
void crossword::display2() {
	cout << "\n" << setw(7) << "-------letters available for level 2 -------" << endl;
	cout << "the letter avaible is : h o p t n \n";

}
void crossword::display3() {
	cout << "\n" << setw(7) << "-------letters available for level 3 -------" << endl;
	cout << "the letter avaible is : k o s p t u \n";

}
