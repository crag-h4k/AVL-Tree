
// An interactive test program for the new AVL class

#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "AVL.h"
using namespace std;


// PROTOTYPES for functions used by this test program:
void print_menu();
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command();
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters),
// and this character has been returned.

void show_list(AVL& display);
// Postcondition: The items on display have been printed to cout (one per line).

int get_number();
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.

int main()
{
/*	int test_1[] = { 10, 15, 20, 25, 30, 35 };
	int test_2[] = { 10, 15, 20, 25, 30, 22 };
	int test_3[] = { 35, 30, 25, 20, 15, 10 };
	int test_4[] = { 35, 30, 25, 20, 15, 22 };*/

	AVL test; // A sequence that we�ll perform tests on
	char choice;   // A command character entered by the user

	cout << "I have initialized an empty sequence of real numbers." << endl;

	do
	{
		print_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{
		case 'I': test.insert(get_number());
			break;
		case 'P': test.print();
			break;
		case 'Q': cout << "Have a good day!" << endl;
			break;
		default:  cout << choice << " is invalid." << endl;
		}
	} while ((choice != 'Q'));

	return EXIT_SUCCESS;
}

void print_menu()
// Library facilities used: iostream.h
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " I   Insert a new number with the insert( ) function" << endl;//
	cout << " P   Print a copy of the entire AVL" << endl;//
	cout << " Q   Quit this test program" << endl;
}

char get_user_command()
// Library facilities used: iostream
{
	char command;

	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

int get_number()
// Library facilities used: iostream
{
	int result;

	cout << "Please enter an integer: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}
