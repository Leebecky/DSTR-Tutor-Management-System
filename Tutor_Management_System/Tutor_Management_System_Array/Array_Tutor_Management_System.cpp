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
	int menuInput = -1;
	Tutor* ptr = new Tutor[15];
	int size = 15;
	int currentPage = 1;
	int rating;
	int tutorIdSelection = -1, opt = -1;
	bool  result = false;

	string userRole = "";
	bool auth = false;

	cout << "Tutor Array System: " << timeStamp << endl;
	cout << "Please login..." << endl;
	//cout << "Login is currently disabled...";
	do {
		auth = login(&userRole);
	} while (!auth);

	cout << "Welcome, " << userRole << ". Hit Enter to proceed" << endl;
	generateData(ptr);
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

		int tutorMenu = -1;
		switch (menuInput)
		{
		case 1: // View all Tutors
		resetDisplayMenu:
			cout << endl;
			do
			{
				tutorListMenu(&userRole, ptr, &size, &currentPage);
				cin >> tutorMenu;

				// Input validation
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << endl << "Invalid input. Please provide a valid id" << endl;
					goto resetDisplayMenu;
				}

				tutorListMenuControl(&tutorMenu, &ptr, &size, &currentPage, &userRole);

				cout << endl;
			} while (tutorMenu > 0);

			break;
		case 2: // Add new tutor
			cout << endl << "Add New Tutor" << endl;
			addTutor(&ptr, &size);
			break;
		case 3: // Search by Id
		resetTutorView:

			cout << "Search ID" << endl;
			cout << "Enter tutor id: ";
			cin >> tutorIdSelection;

			// Input validation
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please provide a valid id" << endl;
				goto resetTutorView;
			}

			do {
				Tutor* data = displayTutorDetails(ptr, size, tutorIdSelection);

				if (!data) {
					break;
				}

				tutorMenuOptions(&userRole);
				cin >> opt;
				tutorIdSelection = tutorMenuControl(ptr, size, opt, tutorIdSelection, &userRole);
			} while (opt > 0);
			break;
		case 4: // Search by Rating
			cout << "Search Rating" << endl;
			cout << "Enter rating: ";
			cin >> rating;
			SearchByRating(ptr, rating, size);
			break;
		case 0:
			cout << endl << "System closing. Please wait..." << endl;
			cout << "Thank you, have a nice day!" << endl << endl;
			break;
		default:
			break;
		}
	} while (menuInput > 0);


	return 0;
}
