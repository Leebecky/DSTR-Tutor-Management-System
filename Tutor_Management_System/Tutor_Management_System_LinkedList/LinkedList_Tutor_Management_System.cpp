// Tutor_Management_System_LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Tutor.h"


int main()
{
	// Logging start up time
	time_t end_time = system_clock::to_time_t(system_clock::now());
	char timeStamp[26] = {};
	string timeStampStr = "";
	ctime_s(timeStamp, 26, &end_time);
	logToFile("\nSystem Start: " + timeStampStr.append(timeStamp));


	//Variables
	int menuInput = -1;
	Tutor *head = NULL;
	Tutor *tail = NULL;
	int tutorListCount = 0;
	int currentPage = 1;

	string userRole = "Admin";
	bool auth = false;

	cout << "Tutor Linked List System: " << timeStamp << endl;
	cout << "Please login..." << endl;
	cout << "Login is currently disabled...";
	/*do {
		auth = login(&userRole);
	} while (!auth);*/

	cout << "Welcome, " << userRole << ". Hit Enter to proceed" << endl;

	cin.get();


	do
	{
		generateData(&head, &tail, &tutorListCount);
		mainMenu();
		cin >> menuInput;

		int tutorMenu = -1;
		switch (menuInput)
		{
		case 1:
			cout << endl;
			do
			{
				displayTutorList(head, tutorListCount, &currentPage);
				tutorListMenu(&userRole);
				cin >> tutorMenu;
				tutorMenuControl(&tutorMenu, &head, &tail, &tutorListCount, &currentPage);

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
