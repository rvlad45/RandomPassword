/////////////////////////////////////////////////
//                                             //
//  The best ever offline password generator.  //
//                                             //
//      Created during the facebook scare.     //
//      Best way to be sure your passwords     //
//              are untraceable.               //
//                                             //
//                    Tips:                    //
//                                             //
//  1. Use longer than 10 for more security.   //
//  2. Write them down, because you're not     //
//     going to remember them, most likely.    //
//  3. Change them out every couple of years.  //
//                                             //
/////////////////////////////////////////////////

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	// 70 symbols used on majority of website authenticators.
	char symbols[70] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJLMNOPQRSTUVWXYZ0123456789!@#$%^&*";

	// Variables.
	short int answer1 = 0;
	short int answer2 = 0;
	int temp = 0;
	string passw = "                                                 ";
	string again = "";
	
	// This loop keeps the process going until the user has
	// all the passwords they need. Terminates when user enters
	// '0' after receiving their passwords.
	while (again != "0")
	{
		cout << "How many passwords do you want to generate? : ";
		cin >> answer1;

		// This loop keeps the user stuck until they input a number.
		while (cin.fail())
		{
			cin.clear(); 
			cin.ignore(100, '\n');
			cout << "That wasn't a number, try again: ";
			cin >> answer1;
		}

		cout << "How many characters would you like your passwords to have? (Max = 50) : ";
		cin >> answer2;

		// Same as the previous loop.
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "That wasn't a number, try again: ";
			cin >> answer2;
		}

		system("cls");

		// Generates a random string that will pick the symbol.
		srand(time(NULL));
		for (int h = 0; h < answer1; h++)
		{
			for (int i = 0; i < answer2; i++)
			{
				temp = rand() % 69;
				passw[i] = symbols[temp];
			}
			cout << "Password[" << h + 1 << "] : " << passw << endl;
		}

		cout << endl << "Do you want to try again? ('Anything' = yes; '0' = no) : ";
		cin >> again;
		passw = "                                                 ";
		system("cls");
	}

	return 0;
}