// Tutor_Management_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Tutor.h"

using namespace std;

int main()
{
	//Sample Function Call
	//test("test");

	//Variables
	int menuInput = -1;

	cout << "Login to be implemented..." << endl;
	cout << "Hit Enter to proceed" << endl;

	cin.get();

	//cout << "Main Menu:" << endl;
	//cout << "1. Display All Tutor" << endl;
	//cout << "2. Add New Tutor" << endl;
	//cout << "3. Search by Tutor ID" << endl;
	//cout << "4. Search by Tutor Rating" << endl;
	//cout << "5. Exit" << endl;
	//cout << "Please enter the desired menu option: ";

	do
	{
		mainMenu();
		cin >> menuInput;

		int tutorMenu = -1;
		switch (menuInput)
		{
		case 1:
			cout << endl;
			do
			{
				tutorListMenu();
				cin >> tutorMenu;
				tutorMenuControl(&tutorMenu);

				cout << endl;
			} while (tutorMenu > 0);

			break;
		case 2:
			cout << "Add New Tutor" << endl;
			break;
		case 3:
			cout << "Search ID" << endl;
			break;
		case 4:
			cout << "Search Rating" << endl;
			break;
		default:
			break;
		}
	} while (menuInput > 0);


	return 0;
}
