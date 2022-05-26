// Tutor_Management_System_LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Tutor.h"



//Only works when I put the code here SORRY
int check_subjectName(int subjectCode, int centerCode, Tutor* head)
{
	Tutor* current = head;

	while (current != NULL)
	{
		if (current->centerCode == centerCode) {
			if (current->subjectCode == subjectCode) {
				return 1;
			}
		}
		current = current->next;
	}
	return 0;
}

int check_tutorName(string tutorName, Tutor* head)
{
	Tutor* current = head;

	while (current != NULL)
	{
		if (current->name == tutorName) {
			return 1;
		}
		current = current->next;
	}
	return 0;
}

int check_centerName(string centerName, Tutor* head)
{
	Tutor* current = head;
	int count = 0;
	while (current != NULL)
	{
		if (current->centerName == centerName) {
			count++;
		}
		current = current->next;
	}
	return count;
}













int main()
{
	// Logging start up time
	time_t end_time = system_clock::to_time_t(system_clock::now());
	char timeStamp[26] = {};
	string timeStampStr = "";
	ctime_s(timeStamp, 26, &end_time);
	logToFile("\nSystem Start: " + timeStampStr.append(timeStamp));

	time_t now = time(0);

	tm* ltm = localtime(&now);


	//Variables
	int menuInput = 1;
	Tutor *head = NULL;
	Tutor *tail = NULL;
	int tutorListCount = 0;
	int currentPage = 1;

  //from Farah
	int displaytutor;
	int choice = 1;
	int flag = 0;
	int tutorId = 6;
	int center_choice, subject_choice, centerCode, subjectCode, hourlyPayRate;
	string name, phone, address, centerName, subjectName;
	char seperator;
	time_t dateJoined = time(NULL) - 31536000;


	string userRole = "HR";

	bool auth = false;

	cout << "Tutor Linked List System: " << timeStamp << endl;
	cout << "Please login..." << endl;
	cout << "Login is currently disabled..." <<endl;
	/*do {
		auth = login(&userRole);
	} while (!auth);
*/
	cout << "Welcome, " << userRole << ". Hit Enter to proceed" << endl;

	cin.get();


	do
	{
	menuReset:
		generateData(&head, &tail, &tutorListCount);
		mainMenu();
		cin >> menuInput;

		// Input validation
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Invalid input. Please provide a valid id"  << endl;
			goto menuReset;
		}

		int tutorMenu = -1;
		switch (menuInput)
		{
		case 1:
		resetDisplayMenu:
			cout << endl;
			do
			{
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
		case 2:
			cout << "Add New Tutor" << endl;
			do
			{
				flag = 0;
				/*
				string day = to_string(ltm->tm_mday);
				string month = to_string(1 + ltm->tm_mon);
				string year = to_string(1900 + ltm->tm_year);

				if (day.length() == 1) {
					day = "0" + day;
				}

				if (month.length() == 1) {
					month = "0" + month;
				}

				dateJoined = day + "-" + month + "-" + year;*/

				while (flag == 0) {
					flag = 1;
					cout << "Enter Tutor Name: ";
					getline(cin, name);
					if (check_tutorName(name, head)) { // validation
						cout << "\nTutor name exists. Please use a different name!\n\n";
						flag = 0;
					}
					if (name.empty()) {
						cout << "\nEmpty inputs are not allowed. Please re-enter!\n\n";
						flag = 0;
					}
				}

				cout << "Enter Phone Number: ";
				cin >> phone;

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter Address: ";
				getline(cin, address);
				flag = 0;

				while (flag == 0) {
					flag = 1;
					cout << "Choose a center: \n 1- Pusat Asia Jaya \n 2- Pusat Megah Jaya \n 3- Pusat Suru Jaya\n\nEnter your choice: ";
					cin >> center_choice;
					centerCode = center_choice;
					if (center_choice == 1) {
						centerName = "Pusat Asia Jaya";
					}
					else if (center_choice == 2) {
						centerName = "Pusat Megah Jaya";
					}
					else if (center_choice == 3) {
						centerName = "Pusat Suru Jaya";
					}
					else {
						cout << "\nCentre does not exist\n\n";
						flag = 0;
						continue;
					}
					if (check_centerName(centerName, head) >= 10) {
						cout << "\nThe centre is already full!\n";
						flag = 0;
					}
				}

				flag = 0;
				while (flag == 0) {
					flag = 1;
					cout << "\nChoose a subject: \n 1- Physics \n 2- Biology \n 3- Chemistry \n 4- Mathematics \n 5- English \n 6- Chinese \n 7- Malay \n 8- Accounting \n 9- Economics \n 10- History \n\nEnter your choice: ";
					cin >> subject_choice;
					subjectCode = subject_choice;

					switch (subject_choice) {
					case 1:
						subjectName = "Physics";
						hourlyPayRate = 40;
						break;
					case 2:
						subjectName = "Biology";
						hourlyPayRate = 44;
						break;
					case 3:
						subjectName = "Chemistry";
						hourlyPayRate = 48;
						break;
					case 4:
						subjectName = "Mathematics";
						hourlyPayRate = 52;
						break;
					case 5:
						subjectName = "English";
						hourlyPayRate = 56;
						break;
					case 6:
						subjectName = "Chinese";
						hourlyPayRate = 60;
						break;
					case 7:
						subjectName = "Malay";
						hourlyPayRate = 64;
						break;
					case 8:
						subjectName = "Accounting";
						hourlyPayRate = 68;
						break;
					case 9:
						subjectName = "Economics";
						hourlyPayRate = 72;
						break;
					case 10:
						subjectName = "History";
						hourlyPayRate = 76;
						break;
					default:
						cout << "Subject does not exist\n";
						flag = 0;
					}

					//if (check_subjectName(subjectCode, centerCode, head)) { // validation
					//	cout << "One center can only have one subject!\n";
					//	flag = 0;
					//}
				}

				Tutor* newnode = CreateNewNnode(tutorId, name, dateJoined, 0, phone, address, centerCode, centerName, subjectCode, subjectName, hourlyPayRate, 0);
				Tutor* insertIntoTheEndofList(newnode);
				tutorId += 1;

				cout << endl << "Do you still want to add a new tutor record?"
					<< " 3- yes, others -No : ";

				cin >> choice;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (tutorMenu > 1);


			break;
		case 3:
			cout << "Search ID" << endl;
			Tutor* searchTutorID();
			break;
		case 4:
			cout << "Search Rating" << endl;
			Tutor* searchTutorRating();
			break;
		default:
			break;
		}
	} while (menuInput > 0);


	return 0;
}
