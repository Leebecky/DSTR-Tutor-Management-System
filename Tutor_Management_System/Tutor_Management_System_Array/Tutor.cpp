#include "Tutor.h"

#pragma warning(disable : 4996)

/*
===========================================================
GENERAL FUNCTIONS
===========================================================
*/

//Login Account Authentication
bool login(string *userRole) {
	string username, password;
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);

	if (username == "Admin" && password == "Admin123") { //Admin account
		*userRole = "Admin";
		return true;
	}
	else if (username == "Hr" && password == "Hr123") { //HR account
		*userRole = "HR";
		return true;
	}
	else {
		cout << endl << "Error logging in. Please check your credentials and try again!" << endl << endl;
		return false;
	}

}

// Log to File
void logToFile(string data) {
	ofstream logFile("Tutor System Log - Array.txt", ios_base::app | ios_base::out);
	logFile << data << endl;
}

// Predefined Data
void generateData(Tutor* head) {
	time_t dateJoined = time(NULL) - 31536000;
	time_t withinMonths = time(NULL) - 2592000;
	time_t outsideMonths = time(NULL) - 17280000;

	int tutorIdList[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

	string nameList[15] = { "Zainul bin Zabidin", "Alina Chan Mei Yi", "Dhanyasree a/p Muthusamy", "Cassim Tan", "Nurul Syafiqah", "Maggie Simon", "Ai Ling Tan", "Diviya Nathan", "Daryl Arul", "Suhaimi bin Suhakam", "Paula Maruice", "Chan Mei Kong", "Cassi Hassan", "Nurul Aslina", "Li Su Yan" };
	time_t dateTerminated[15] = { outsideMonths, 0, outsideMonths, 0, outsideMonths, withinMonths, 0, withinMonths, 0, 0,  withinMonths, 0, 0, outsideMonths, outsideMonths };
	double hourlyPayRateList[15] = { 45.00, 75.00, 50.00, 65.00, 62.00, 58.00, 78.50, 50.00, 80.00, 64.00, 62.00, 75.00, 80.00, 45.00, 78.50 };
	string phoneList[15] = { "011-1234567" , "016-5423412" , "017-3415136" , "016-1237568" , "011-845656455" , "011-57457823", "015-123434656", "011-958567555", "016-98653544", "011-845656455", "016-45452777", "012-24562453", "016-756455554", "011-673334s76", "018-88345346" };
	string addressList[15] = { "19, Jalan A12, Taman Asia, 68000 Ampang, Selangor", "22, Jalan B1, Taman Bestari, 68000 Ampang, Selangor", "A12, Block-C, Oakleaf Condominium, 51000 Kuala Lumpur", "97, Jalan ST1, Taman Stadhuys, 68000 Ampang, Selangor", "65, Jalan M1, Taman Mega, 68000 Ampang, Selangor", "11, Jalan M1, Taman Mega, 68000 Ampang, Selangor", "65, Jalan M1, Taman Mega, 68000 Ampang, Selangor", "561, Jalan Sinar 1, Taman Sinar, 68000 Ampang, Selangor", "17, Jalan M2, Taman Mega, 68000 Ampang, Selangor", "65, Jalan M1, Taman Mega, 68000 Ampang, Selangor", "67, Jalan Bkt Utama, Taman Bukit, 68000 Ampang, Selangor", "7-A-1, Emerald Condominium, 68000 Ampang, Selangor", "97, Jalan Bendara, Taman Antarabangsa, 68000 Ampang, Selangor", "65, Jalan M3, Taman Mega, 68000 Ampang, Selangor", "99, Jalan B1, Taman Bestari, 68000 Ampang, Selangor" };
	int centerCodeList[15] = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3 };
	string centerNameList[15] = { "Pusat Asia Jaya", "Pusat Asia Jaya", "Pusat Asia Jaya", "Pusat Asia Jaya", "Pusat Asia Jaya", "Pusat Megah Jaya", "Pusat Megah Jaya", "Pusat Megah Jaya", "Pusat Megah Jaya", "Pusat Megah Jaya", "Pusat Suru Jaya", "Pusat Suru Jaya", "Pusat Suru Jaya", "Pusat Suru Jaya", "Pusat Suru Jaya" };
	int subjectCodeList[15] = { 1, 5, 2, 3, 4, 9, 10, 2, 8, 7, 4 ,5, 3, 1, 10 };
	string subjectNameList[15] = { "Bahasa Melayu", "Biology", "English", "Sejarah", "Geografi", "Mathematics", "Additional Mathematics", "English", "Chemistry", "Physics", "Geografi", "Biology", "Chemistry", "Bahasa Melayu", "Additional Mathematics" };
	int ratingList[15] = { 3, 5, 1, 3, 2, 2, 5, 1, 2, 5, 4, 4, 5, 3, 4 };

	for (int i = 0; i < 15; i++) {
		(head + i)->tutorId = tutorIdList[i];
		(head + i)->name = nameList[i];
		(head + i)->dateJoined = dateJoined;
		(head + i)->dateTerminated = dateTerminated[i];
		(head + i)->hourlyPayRate = hourlyPayRateList[i];
		(head + i)->phone = phoneList[i];
		(head + i)->address = addressList[i];
		(head + i)->centerCode = centerCodeList[i];
		(head + i)->centerName = centerNameList[i];
		(head + i)->subjectCode = subjectCodeList[i];
		(head + i)->subjectName = subjectNameList[i];
		(head + i)->rating = ratingList[i];
	}
}

/*
===========================================================
MENU DISPLAY & CONTROL FUNCTIONS
===========================================================
*/

//Display the main menu
void mainMenu()
{
	cout << endl << "Main Menu:" << endl;
	cout << "1. Display All Tutor" << endl;
	cout << "2. Add New Tutor" << endl;
	cout << "3. Search by Tutor ID" << endl;
	cout << "4. Search by Tutor Rating" << endl;
	cout << "0. Exit" << endl;
	cout << "Please enter the desired menu option: ";
}

//Display the menu when viewing the tutor list
void tutorListMenu(string *userRole, Tutor* head, int* size, int* currentPage)
{
	cout << "Tutor List:" << endl;
	displayTutorList(head, *size, currentPage);
	cout << "\n1. View Tutor" << endl;
	cout << "2. Sort by Tutor ID" << endl;
	cout << "3. Sort by Tutor Hourly Pay" << endl;
	cout << "4. Sort by Tutor Rating" << endl;

	if (*userRole == "HR") {
		cout << "5. Delete Tutor" << endl;
	}

	cout << "6. Next page" << endl;
	cout << "7. Previous page" << endl;
	cout << "0. Back to Main Menu" << endl;
	cout << "Please enter the desired menu option: ";
}

// Single Tutor View Menu
void tutorMenuOptions(string *userRole) {
	int menuSelection = -1;
	cout << "Tutor Record:" << endl;
	if (*userRole == "HR") {
		cout << "1. Modify Address" << endl;
		cout << "2. Modify Phone Number" << endl;
	}
	cout << "3. Next Tutor Record" << endl;
	cout << "4. Previous Tutor Record" << endl;
	cout << "0. Back to Display Menu" << endl;
	cout << "Please enter the desired menu option: ";
}

// Menu control for Tutor List Menu
void tutorListMenuControl(int* input, Tutor** head, int* size, int* currentPage, string *userRole)
{
	int tutorIdSelection = -1, opt = -1;
	bool  result = false;

	switch (*input)
	{
	case 1:
	resetTutorView:
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
			Tutor *data = displayTutorDetails((*head), *size, tutorIdSelection);

			if (!data) {
				break;
			}

			tutorMenuOptions(userRole);
			cin >> opt;
			tutorIdSelection = tutorMenuControl((*head), *size, opt, tutorIdSelection);
		} while (opt > 0);
		break;
	case 2:
		sortByTutorId((*head), *size);
		cout << "Sort by Tutor Id" << endl;
		break;
	case 3:
		sortByHourlyPay((*head), 0, *size - 1);
		cout << "Sort by Pay" << endl;
		break;
	case 4:
		sortByRating((*head), 0, *size - 1);
		cout << "Sort by Rating" << endl;
		break;
	case 5:
		cout << "Enter tutor id: ";
		cin >> tutorIdSelection;
		sortByTutorId((*head), *size);
		result = deleteTutor(head, 0, *size - 1, tutorIdSelection);

		if (result) {
			*size = *size - 1;
			cout << "Tutor deleted." << endl;
		}
		break;
	case 6:
		*currentPage = *currentPage + 1;
		break;
	case 7:
		*currentPage = *currentPage - 1;
		break;
	default:
		break;
	}
}

// Single Tutor View Menu Control
int tutorMenuControl(Tutor *head, int size, int menuSelection, int tutorId) {
	string dataValue = "";
	bool result = false;

	Tutor *data = binarySearchTutorId(head, size, tutorId);
	int dataIndex = binarySearchTutorIndex(head, size, tutorId);

	// if record not found
	if (!data) {
		cout << endl << "Tutor cannot be modified because tutor Id not found." << endl << endl;
		return -1;
	}

	switch (menuSelection) {

	case 1: // modify address
		cout << "Enter the address: ";
		cin.ignore();
		getline(cin, dataValue);
		result = modifyTutor(data, &dataValue, "Address");

		if (result) {
			cout << endl << "Tutor address updated" << endl;
		}

		return data->tutorId;
	case 2: // modify phone number
		cout << "Enter the phone number: ";
		cin.ignore();
		getline(cin, dataValue);
		result = modifyTutor(data, &dataValue, "Phone");

		if (result) {
			cout << endl << "Tutor phone number updated" << endl;
		}

		return data->tutorId;
	case 3:  // Next record
		if (dataIndex + 1 == size) {
			dataIndex = 0;
		}
		else {
			dataIndex = dataIndex + 1;
		}

		return head[dataIndex].tutorId;
	case 4: // Previous Record
		if (dataIndex - 1 < 0) {
			dataIndex = size - 1;
		}
		else {
			dataIndex = dataIndex - 1;
		}

		return head[dataIndex].tutorId;
	default:
		return tutorId;
	}

}

/*
===========================================================
DATA DISPLAY FUNCTIONS
===========================================================
*/

// Display all tutors
void displayTutorList(Tutor* head, int size, int* currentPage) {
	int currentPosition, maxPosition, maxPage;
	tm* dateTerminated;

	// Pagination Control
	if (size % 5 != 0) {
		maxPage = (size / 5) + 1;
	}
	else {
		maxPage = size / 5;
	}

	if (*currentPage == 0) {
		*currentPage = maxPage;
	}
	else if (*currentPage > maxPage) {
		*currentPage = 1;
	}

	if (*currentPage == maxPage) {
		maxPosition = 5 * (size / 5) + (size % 5);
	}
	else {
		maxPosition = 5 * *currentPage;
	}

	currentPosition = (*currentPage - 1) * 5;

	// Menu Header
	cout << " Id" << "\t| ";
	cout << setw(30) << left << "Tutor Name" << " | ";
	cout << "Pay Rate" << "\t| ";
	cout << "Center Name" << "\t\t| ";
	cout << "Rating" << "\t| ";
	cout << "Date Terminated" << endl;

	for (int i = 0; i < 120; i++) {
		cout << "=";
	}

	// Menu - Tutor Record output
	for (int i = currentPosition; i < maxPosition; i++)
	{
		cout << "\n #" << (head + i)->tutorId << "\t| ";
		cout << setw(30) << left << (head + i)->name << " | ";
		cout << (head + i)->hourlyPayRate << "\t\t| ";
		cout << (head + i)->centerName << "\t| ";
		cout << (head + i)->rating << "\t\t| ";

		dateTerminated = localtime(&(head + i)->dateTerminated);

		if ((head + i)->dateTerminated == 0) {
			cout << " - " << endl;
		}
		else {
			cout << dateTerminated->tm_year + 1900 << "-" << dateTerminated->tm_mon + 1 << "-" << dateTerminated->tm_mday << endl;
		}
	}

	cout << "\nPage  " << *currentPage << " / " << maxPage << endl;
}

// Display the details of an individual record
Tutor *displayTutorDetails(Tutor *head, int size, int tutorId) {
	Tutor *data = binarySearchTutorId(head, size, tutorId);
	tm *dateTerminated, *dateJoined;
	// if record not found
	if (!data) {
		cout << endl << "Tutor not found." << endl << endl;
		return NULL;
	}

	cout << endl << "=================================================================" << endl;
	cout << "\t#" << data->tutorId << "\t" << data->name << endl;
	cout << "=================================================================" << endl;
	cout << "Address: \t" << data->address << endl;
	cout << "Phone Number: \t" << data->phone << endl;
	cout << "Rating: \t" << data->rating << endl;
	cout << "Hourly Pay Rate:" << data->hourlyPayRate << endl;

	// Date Joined
	dateJoined = localtime(&(data)->dateJoined);
	if (dateJoined->tm_year + 1900 == 1970) {
		cout << "Date Joined: \t- " << endl;
	}
	else {
		cout << "Date Joined: \t" << dateJoined->tm_year + 1900 << "-" << dateJoined->tm_mon + 1 << "-" << dateJoined->tm_mday << endl;
	}

	cout << "Center Code: \t" << data->centerCode << endl;
	cout << "Center Name: \t" << data->centerName << endl;
	cout << "Subject Code: \t" << data->subjectCode << endl;
	cout << "Subject Name: \t" << data->subjectName << endl;

	// Date Terminated
	dateTerminated = localtime(&(data)->dateTerminated);
	if (dateTerminated->tm_year + 1900 == 1970) {
		cout << "Date Terminated: - " << endl;
	}
	else {
		cout << "Date Terminated: " << dateTerminated->tm_year + 1900 << "-" << dateTerminated->tm_mon + 1 << "-" << dateTerminated->tm_mday << endl;
	}

	cout << "=================================================================" << endl << endl;

	return data;
}

/*
===========================================================
DATA CONTROL FUNCTIONS
===========================================================
*/


// ================== ADD TUTOR VALIDATION ================== //

// Validate Tutor Name
int checkTutorName(string tutorName, Tutor* head, int size)
{
	Tutor* current = head;

	for (int i = 0; i < size; i++)
	{
		if ((current + i)->name == tutorName) {
			return 1;
		}

	}
	return 0;
}

// Validate number of active tutors per center
bool checkCenterCount(int centerCode, Tutor* head, int size)
{
	Tutor* current = head;
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if ((current + i)->centerCode == centerCode && (current + i)->dateTerminated == 0) {
			count++;
		}
	}

	if (count >= 10) {
		return true;
	}
	else {
		return false;
	}
}

//Add Tutor
void addTutor(Tutor **head, int* size)
{
	std::string name, phone, address, centerName, subjectName;

	double hourlyPayRate;
	int centerCode, subjectCode;
	time_t dateJoined = time(NULL) - 31536000;
	bool isValid = true;

resetNameInput:
	cout << "Enter Tutor Name: ";
	cin.ignore();
	getline(cin, name);

	if (checkTutorName(name, *head, *size)) { // validation
		cout << endl << "Tutor name exists. Please use a different name!" << endl << endl;
		goto resetNameInput;
	}
	if (name.empty()) {
		cout << endl << "Empty inputs are not allowed. Please re-enter!" << endl << endl;
		goto resetNameInput;
	}

	//cout << "Hourly Pay Rate: ";
	//cin >> hourlyPayRate; cout << endl;
	////Input validation
	//while (!(hourlyPayRate >= 40 && hourlyPayRate <= 80))
	//{
	//	cout << "Invalid Input. Try Again." << endl;
	//	cout << "Enter a Rate from 40.00 - 80.00: ";
	//	cin >> hourlyPayRate; cout << endl;
	//}

resetPhoneInput: // Phone Number
	cout << "Phone: ";
	cin >> phone;

	if (phone.empty()) {
		cout << endl << "Please enter a phone number" << endl;
		goto resetPhoneInput;
	}
	

resetAddressInput: // Address
	cout << "Address: ";
	cin >> address;
	if (address.empty()) {
		cout << endl << "Please enter an address" << endl;
		goto resetAddressInput;
	}
	

resetCenterSelection:
	cout << endl << "Select a center" << endl;
	cout << "1 - Pusat Asia Jaya" << endl;
	cout << "2 - Pusat Megah Jaya" << endl;
	cout << "3 - Pusat Suru Jaya" << endl;
	cout << "Center Code: ";
	cin >> centerCode;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "Invalid input. Please provide a valid center id" << endl;
		goto resetCenterSelection;
	}
	
	if (checkCenterCount(centerCode, *head, *size)) {
		cout << endl << "The centre is already full!" << endl;
		goto resetCenterSelection;
	}

	switch (centerCode)
	{
	case 1:
		centerName = "Pusat Asia Jaya";
		break;
	case 2:
		centerName = "Pusat Megah Jaya";
		break;
	case 3:
		centerName = "Pusat Suru Jaya";
		break;
	default:
		cout << endl << "Centre does not exist" << endl << endl;
		goto resetCenterSelection;
	}

resetSubjectSelection: // Subject Selection + Hourly Pay Rate

	cout << endl << "Select a subject: " << endl;
	cout << "1- Bahasa Melayu\t\t| RM 45.00" << endl;
	cout << "2- English\t\t\t| RM 50.00" << endl;
	cout << "3- Sejarah\t\t\t| RM 65.00" << endl;
	cout << "4- Geografi\t\t\t| RM 62.00" << endl;
	cout << "5- Biology\t\t\t| RM 75.00" << endl;
	cout << "6- Accounts\t\t\t| RM 60.00" << endl;
	cout << "7- Physics\t\t\t| RM 64.00" << endl;
	cout << "8- Chemistry\t\t\t| RM 80.00" << endl;
	cout << "9- Mathematics\t\t\t| RM 58.00" << endl;
	cout << "10- Additional Mathematics\t| RM 78.50" << endl;
	cout << "Subject Code: ";
	cin >> subjectCode;
	// Input validation
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "Invalid input. Please provide a valid subject id" << endl;
		goto resetSubjectSelection;
	}


	cout << endl;

	switch (subjectCode)
	{
	case 1:
		subjectName = "Bahasa Melayu";
		hourlyPayRate = 45.00;
		break;
	case 2:
		subjectName = "English";
		hourlyPayRate = 50.00;
		break;
	case 3:
		subjectName = "Sejarah";
		hourlyPayRate = 65.00;
		break;
	case 4:
		subjectName = "Geografi";
		hourlyPayRate = 62.00;
		break;
	case 5:
		subjectName = "Biology";
		hourlyPayRate = 75.00;
		break;
	case 6:
		subjectName = "Accounts";
		hourlyPayRate = 60.00;
		break;
	case 7:
		subjectName = "Physics";
		hourlyPayRate = 64.00;
		break;
	case 8:
		subjectName = "Chemistry";
		hourlyPayRate = 80.00;
		break;
	case 9:
		subjectName = "Mathematics";
		hourlyPayRate = 58.00;
		break;
	case 10:
		subjectName = "Additional Mathematics";
		hourlyPayRate = 78.50;
		break;
	default:
		cout << endl << "Subject does not exist!" << endl;
		goto resetSubjectSelection;
	}

	//cout << "Rating: ";
	//cin >> rating; cout << endl;
	////Input Validation
	//while (!(rating >= 1 && rating <= 5))
	//{
	//	cout << "Invalid Input. Try Again." << endl;
	//	cout << "Enter a Rating from 1 - 5: ";
	//	cin >> rating; cout << endl;
	//}

	// RNG - Rating
	int rating = (rand() % 5) + 1;

	// Resize array
	sortByTutorId(*head, *size);
	int tutorId = (*head + *size - 1)->tutorId + 1;
	int newSize = *size + 1;
	int newIndex = newSize - 1;
	Tutor *newArray = new Tutor[newSize];
	std::copy((*head), (*head) + (*size), newArray);

	*size = newSize;

	// Deallocate old array
	delete[] * head;
	*head = newArray;

	// Set new node values
	((*head) + newIndex)->tutorId = tutorId;
	((*head) + newIndex)->name = name;
	((*head) + newIndex)->dateJoined = dateJoined;
	((*head) + newIndex)->dateTerminated = 0;
	((*head) + newIndex)->hourlyPayRate = hourlyPayRate;
	((*head) + newIndex)->phone = phone;
	((*head) + newIndex)->address = address;
	((*head) + newIndex)->centerCode = centerCode;
	((*head) + newIndex)->centerName = centerName;
	((*head) + newIndex)->subjectCode = subjectCode;
	((*head) + newIndex)->subjectName = subjectName;
	((*head) + newIndex)->rating = rating;
}

// Delete Tutor - Binary Search
bool deleteTutor(Tutor** head, int low, int size, int tutorId) {
	int mid, p = 0, high = size;
	time_t today = time(NULL);

	while (low <= high) {
		mid = (low + high) / 2;

		if (tutorId == (*head + mid)->tutorId) {
			cout << "\n\n";

			if ((*head + mid)->dateTerminated == 0) {
				cout << "Tutor cannot be deleted because tutor is not terminated." << endl;
				return false;
			}
			else if (today - (*head + mid)->dateTerminated < 15552000) {
				cout << "Tutor cannot be deleted because terminated date is less than 6 months." << endl;
				return false;
			}
			else {
				Tutor *newArray = new Tutor[size];
				std::copy((*head), (*head) + mid, newArray);
				std::copy((*head) + mid + 1, (*head) + size + 1, newArray + mid);
				delete[](*head);
				(*head) = newArray;

				p = 1;
				return true;
			}
		}
		else {
			if (tutorId < (*head + mid)->tutorId) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}

	if (p != 1) {
		cout << "\n\nTutor cannot be deleted because tutor Id not found." << endl;
		return false;
	}

}

// Modify Tutor Record
bool modifyTutor(Tutor *data, string *dataValue, string updateAttribute) {
	if (*dataValue == "") {

		cout << endl << "No data provided. " << updateAttribute << " not updated" << endl;
		return false;
	}

	if (updateAttribute == "Phone") {
		data->phone = *dataValue;
	}
	else {
		data->address = *dataValue;
	}

	return true;
}

/*
===========================================================================
SORTING FUNCTIONS
===========================================================================
*/


// Bubble Sort
void sortByTutorId(Tutor* head, int size) {
	for (int i = 0; i < size - 1; i++) {
		bool swapped = false;
		for (int j = i + 1; j < size; j++) {
			if ((head + i)->tutorId > (head + j)->tutorId) {

				Tutor temp = head[i];
				head[i] = head[j];
				head[j] = temp;
				swapped = true;
			}
		}

		//Break the outer loop if no swap happens
		if (!swapped) {
			break;
		}
	}

}

// Quick Sort
void sortByHourlyPay(Tutor* head, int low, int high) {
	if (low < high)
	{
		int pivot = (head + high)->hourlyPayRate;
		int i = (low - 1);

		for (int j = low; j <= high - 1; j++)
		{
			if ((head + j)->hourlyPayRate <= pivot)
			{
				i++;

				Tutor temp = head[i];
				head[i] = head[j];
				head[j] = temp;
			}
		}

		Tutor temp = head[i + 1];
		head[i + 1] = head[high];
		head[high] = temp;

		pivot = (i + 1);

		sortByHourlyPay(head, low, pivot - 1);
		sortByHourlyPay(head, pivot + 1, high);
	}

}

// Merge Sort
void sortByRating(Tutor* head, int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		sortByRating(head, low, mid);
		sortByRating(head, mid + 1, high);

		mergeSorting(head, low, high, mid);
	}
}


/*
===========================================================================
SEARCH FUNCTIONS
===========================================================================
*/

// Binary Search
Tutor* binarySearchTutorId(Tutor* head, int size, int tutorId) {
	int low = 0, mid, high = size;

	while (low <= high) {
		mid = (low + high) / 2;

		if (tutorId == (head + mid)->tutorId) {
			return (head + mid);
		}
		else {
			if (tutorId < (head + mid)->tutorId) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}

	return NULL;
}


int binarySearchTutorIndex(Tutor* head, int size, int tutorId) {
	int low = 0, mid, high = size;

	while (low <= high) {
		mid = (low + high) / 2;

		if (tutorId == (head + mid)->tutorId) {
			return mid;
		}
		else {
			if (tutorId < (head + mid)->tutorId) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}

	return NULL;
}

// Search by Tutor Rating - Linear Search
void SearchByRating(Tutor* head, int rating, int size) {
	tm* dateTerminated;
	cout << " Id" << "\t| ";
	cout << setw(30) << left << "Tutor Name" << " | ";
	cout << "Pay Rate" << "\t| ";
	cout << "Center Name" << "\t\t| ";
	cout << "Rating" << "\t| ";
	cout << "Date Terminated" << endl;

	for (int i = 0; i < 120; i++) {
		cout << "=";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if ((head + i)->rating == rating) {
			cout << "\n #" << (head + i)->tutorId << "\t| ";
			cout << setw(30) << left << (head + i)->name << " | ";
			cout << (head + i)->hourlyPayRate << "\t\t| ";
			cout << (head + i)->centerName << "\t| ";
			cout << (head + i)->rating << "\t\t| ";

			dateTerminated = localtime(&(head + i)->dateTerminated);

			if ((head + i)->dateTerminated == 0) {
				cout << " - " << endl;
			}
			else {
				cout << dateTerminated->tm_year + 1900 << "-" << dateTerminated->tm_mon + 1 << "-" << dateTerminated->tm_mday << endl;
			}
		}
	}
}


/*
===========================================================================
UTILITY FUNCTIONS FOR SORTING FUNCTIONS
===========================================================================
*/
void mergeSorting(Tutor* head, int low, int high, int mid) {
	int i, j, k;
	Tutor c[50];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high) {
		if ((head + i)->rating < (head + j)->rating) {
			c[k] = head[i];
			k++;
			i++;
		}
		else {
			c[k] = head[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		c[k] = head[i];
		k++;
		i++;
	}

	while (j <= high) {
		c[k] = head[j];
		k++;
		j++;
	}

	for (i = low; i < k; i++) {
		head[i] = c[i];
	}
}
