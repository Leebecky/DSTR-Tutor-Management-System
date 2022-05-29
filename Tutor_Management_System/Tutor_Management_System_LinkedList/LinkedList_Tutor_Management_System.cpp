/*
Tutor_Management_System_LinkedList
===========================================================
LOGIN CREDENTIALS
===========================================================

Role: Admin
Username: Admin
Password: Admin123

Role: Hr manager
Username: Hr
Password: Hr123

*/


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
	int menuInput = 1;
	Tutor *head = NULL;
	Tutor *tail = NULL;
	int tutorListCount = 0;
	int currentPage = 1;
	string userRole = "";

	bool auth = false;

	cout << "Tutor Linked List System: " << timeStamp << endl;
	cout << "Please login..." << endl;
	//cout << "Login is currently disabled..." << endl;
	do {
		auth = login(&userRole);
	} while (!auth);

	cout << "Welcome, " << userRole << ". Hit Enter to proceed";
	generateData(&head, &tail, &tutorListCount);
	cin.get();

	do
	{
	menuReset:

		mainMenu();
		cin >> menuInput;

		// Input validation
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Invalid input. Please select a valid option" << endl;
			goto menuReset;
		}

		int tutorMenu = -1, addTutorChoice = -1;
		switch (menuInput)
		{
		case 1: // View all Tutors
		resetDisplayMenu:
			cout << endl;
			do
			{
				// Display Tutor List
				displayTutorList(head, tutorListCount, &currentPage);
				tutorListMenu(&userRole);
				cin >> tutorMenu;

				// Input validation
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << endl << "Invalid input. Please provide a valid id" << endl;
					goto resetDisplayMenu;
				}

				tutorListMenuControl(&tutorMenu, &head, &tail, &tutorListCount, &currentPage, &userRole);
				
				cout << endl;
			} while (tutorMenu > 0);

			break;
		case 2: // Add New Tutor
			cout << endl << "Add New Tutor" << endl;
			cout << "==============================" << endl;
			addTutor(&head, &tail, &tutorListCount);
			
			break;
		case 3: // Search by Id
			cout << endl << "Search for Tutor by ID" << endl;
			cout << "==============================" << endl;
			searchByTutorId(head, tail, &tutorListCount, &userRole);
			break;
		case 4: // Search by Rating
			cout << endl << "Search for Tutor by Rating" << endl;
			cout << "==============================" << endl;
			searchByTutorRating(head, &tutorListCount);
			break;
		case 0: // Exit
			cout << endl << "System closing. Please wait..." << endl;
			cout << "Thank you, have a nice day!" << endl;
		default:
			cout << endl << "No corresponding option" << endl;
			break;
		}
	} while (menuInput > 0);


	return 0;
}
