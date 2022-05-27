
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
	ofstream logFile("Tutor System Log - Linked List.txt", ios_base::app | ios_base::out);

	logFile << data << endl;

}


// Predefined Data
void generateData(Tutor **head, Tutor** tail, int* tutorListCount) {

	time_t dateJoined = time(NULL) - 31536000;
	time_t withinMonths = time(NULL) - 2592000;
	time_t outsideMonths = time(NULL) - 17280000;

	Tutor *data1 = new Tutor(1, "Zainul bin Zabidin", dateJoined, 45.00, "011-1234567", "19, Jalan A12, Taman Asia, 68000 Ampang, Selangor", 1, "Pusat Asia Jaya", 1, "Bahasa Melayu", 3, outsideMonths);
	Tutor *data2 = new Tutor(2, "Alina Chan Mei Yi", dateJoined, 75.00, "016-5423412", "22, Jalan B1, Taman Bestari, 68000 Ampang, Selangor", 1, "Pusat Asia Jaya", 5, "Biology", 5, 0);
	Tutor *data3 = new Tutor(3, "Dhanyasree a/p Muthusamy", dateJoined, 50.00, "017-3415136", "A12, Block-C, Oakleaf Condominium, 51000 Kuala Lumpur", 1, "Pusat Asia Jaya", 2, "English", 1, outsideMonths);
	Tutor *data4 = new Tutor(4, "Cassim Tan", dateJoined, 65.00, "016-1237568", "97, Jalan ST1, Taman Stadhuys, 68000 Ampang, Selangor", 1, "Pusat Asia Jaya", 3, "Sejarah", 3, 0);
	Tutor *data5 = new Tutor(5, "Nurul Syafiqah", dateJoined, 62.00, "011-845656455", "65, Jalan M1, Taman Mega, 68000 Ampang, Selangor", 1, "Pusat Asia Jaya", 4, "Geografi", 2, outsideMonths);
	Tutor *data6 = new Tutor(6, "Maggie Simon", dateJoined, 58.00, "011-57457823", "11, Jalan M1, Taman Mega, 68000 Ampang, Selangor", 2, "Pusat Megah Jaya", 9, "Mathematics", 2, withinMonths);
	Tutor *data7 = new Tutor(7, "Ai Ling Tan", dateJoined, 78.50, "015-123434656", "65, Jalan M1, Taman Mega, 68000 Ampang, Selangor", 2, "Pusat Megah Jaya", 10, "Additional Mathematics", 5, 0);
	Tutor *data8 = new Tutor(8, "Diviya Nathan", dateJoined, 50.00, "011-958567555", "561, Jalan Sinar 1, Taman Sinar, 68000 Ampang, Selangor", 2, "Pusat Megah Jaya", 2, "English", 1, outsideMonths);
	Tutor *data9 = new Tutor(9, "Daryl Arul", dateJoined, 80.00, "016-98653544", "17, Jalan M2, Taman Mega, 68000 Ampang, Selangor", 2, "Pusat Megah Jaya", 8, "Chemistry", 2, 0);
	Tutor *data10 = new Tutor(10, "Suhaimi bin Suhakam", dateJoined, 64.00, "011-845656455", "65, Jalan M1, Taman Mega, 68000 Ampang, Selangor", 2, "Pusat Megah Jaya", 7, "Physics", 5, 0);
	Tutor *data11 = new Tutor(11, "Paula Maruice", dateJoined, 62.00, "016-45452777", "67, Jalan Bkt Utama, Taman Bukit, 68000 Ampang, Selangor", 3, "Pusat Suru Jaya", 4, "Geografi", 4, withinMonths);
	Tutor *data12 = new Tutor(12, "Chan Mei Kong", dateJoined, 75.00, "012-24562453", "7-A-1, Emerald Condominium, 68000 Ampang, Selangor", 3, "Pusat Suru Jaya", 5, "Biology", 4, 0);
	Tutor *data13 = new Tutor(13, "Cassi Hassan", dateJoined, 80.00, "016-756455554", "97, Jalan Bendara, Taman Antarabangsa, 68000 Ampang, Selangor", 3, "Pusat Suru Jaya", 8, "Chemistry", 5, 0);
	Tutor *data14 = new Tutor(14, "Nurul Aslina", dateJoined, 45.00, "011-673334s76", "65, Jalan M3, Taman Mega, 68000 Ampang, Selangor", 3, "Pusat Suru Jaya", 1, "Bahasa Melayu", 3, outsideMonths);
	Tutor *data15 = new Tutor(15, "Li Su Yan", dateJoined, 78.50, "018-88345346", "99, Jalan B1, Taman Bestari, 68000 Ampang, Selangor", 3, "Pusat Suru Jaya", 10, "Additional Mathematics", 4, outsideMonths);

	data1->next = data2;
	data1->prev = NULL;

	data2->next = data3;
	data2->prev = data1;

	data3->next = data4;
	data3->prev = data2;

	data4->next = data5;
	data4->prev = data3;

	data5->next = data6;
	data5->prev = data4;

	data6->next = data7;
	data6->prev = data5;

	data7->next = data8;
	data7->prev = data6;

	data8->next = data9;
	data8->prev = data7;

	data9->next = data10;
	data9->prev = data8;

	data10->next = data11;
	data10->prev = data9;

	data11->next = data12;
	data11->prev = data10;

	data12->next = data13;
	data12->prev = data11;

	data13->next = data14;
	data13->prev = data12;

	data14->next = data15;
	data14->prev = data13;

	data15->next = NULL;
	data15->prev = data14;

	(*head) = data1;
	(*tail) = data15;
	*tutorListCount = 15;
}


/*
===========================================================
CONSTRUCTOR
===========================================================
*/

Tutor::Tutor() {

}

//Base Constructor
Tutor::Tutor(int tutorId, string name, time_t dateJoined, double hourlyPayRate, string phone, string address, int centerCode, string centerName, int subjectCode, string subjectName, int rating, time_t dateTerminated)
{
	this->tutorId = tutorId;
	this->name = name;
	this->dateJoined = dateJoined;
	this->hourlyPayRate = hourlyPayRate;
	this->phone = phone;
	this->address = address;
	this->centerCode = centerCode;
	this->centerName = centerName;
	this->subjectCode = subjectCode;
	this->subjectName = subjectName;
	this->rating = rating;
	this->dateTerminated = dateTerminated;

	Tutor* nextAddress;
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
void tutorListMenu(string *userRole)
{
	cout << "Tutor List:" << endl;
	cout << "1. View Tutor" << endl;
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
void tutorListMenuControl(int* input, Tutor** head, Tutor** tail, int *tutorListCount, int* currentPage, string *userRole)
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
			Tutor *data = displayTutorDetails((*head), *tutorListCount, tutorIdSelection);

			if (!data) {
				break;
			}

			tutorMenuOptions(userRole);
			cin >> opt;
			tutorIdSelection = tutorMenuControl((*head), (*tail), *tutorListCount, opt, tutorIdSelection);
		} while (opt > 0);
		break;
	case 2:
		cout << "Sort by Tutor Id" << endl;
		sortByTutorId(head, tail, tutorListCount);
		break;
	case 3:
		cout << "Sort by Pay" << endl;
		sortByHourlyPay(head, tail);
		break;
	case 4:
		cout << "Sort by Rating" << endl;
		sortByRating(head, tail);
		break;
	case 5:
	resetInput:
		cout << "Enter tutor id: ";
		cin >> tutorIdSelection;

		// Input validation
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please provide a valid id" << endl;
			goto resetInput;
		}

		sortByTutorId(head, tail, tutorListCount);
		result = deleteTutor(head, tail, *tutorListCount, tutorIdSelection);

		if (result) {
			*tutorListCount = *tutorListCount - 1;
			cout << endl << "Tutor record has been deleted." << endl;
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
int tutorMenuControl(Tutor *head, Tutor *tail, int size, int menuSelection, int tutorId) {
	string dataValue = "";
	bool result = false;

	Tutor *data = binarySearchTutorId(head, size, tutorId);

	// if record not found
	if (!data) {
		cout << endl << "Tutor cannot be modified because tutor Id not found." << endl << endl;
		return -1;
	}

	switch (menuSelection) {

	case 1:
		cout << "Enter the address: ";
		cin.ignore();
		getline(cin, dataValue);
		result = modifyTutor(data, &dataValue, "Address");

		if (result) {
			cout << endl << "Tutor address updated" << endl;
		}

		return data->tutorId;
	case 2:
		cout << "Enter the phone number: ";
		cin.ignore();
		getline(cin, dataValue);
		result = modifyTutor(data, &dataValue, "Phone");

		if (result) {
			cout << endl << "Tutor phone number updated" << endl;
		}

		return data->tutorId;
	case 3:
		if (data->next == NULL) { // if end of list, skip back to front
			return head->tutorId;
		}
		return data->next->tutorId;
	case 4:
		if (data->prev == NULL) { // If start of list, skip to end
			return tail->tutorId;
		}
		return data->prev->tutorId;
	default:
		return data->tutorId;
	}

}

/*
===========================================================
DATA DISPLAY FUNCTIONS
===========================================================
*/

// Display all tutors
void displayTutorList(Tutor* head, int size, int* currentPage) {
	tm* dateTerminated;
	int currentPosition, maxPosition, maxPage;
	Tutor *temp = head;

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
	cout << "Rating" << " | ";
	cout << "Date Terminated" << endl;

	for (int i = 0; i < 120; i++)
	{
		cout << "=";
	}

	// Menu - Tutor Record output
	for (int i = 0; i < maxPosition; i++)
	{
		if (i >= currentPosition) {
			cout << endl << " #" << (temp)->tutorId << "\t| ";
			cout << setw(30) << left << (temp)->name << " | ";
			cout << (temp)->hourlyPayRate << "\t\t| ";
			cout << (temp)->centerName << "\t| ";
			cout << (temp)->rating << "\t | ";

			dateTerminated = localtime(&(temp)->dateTerminated);
			if (dateTerminated->tm_year + 1900 == 1970) {
				cout << " - " << endl;
			}
			else {
				cout << dateTerminated->tm_year + 1900 << "-" << dateTerminated->tm_mon + 1 << "-" << dateTerminated->tm_mday << endl;
			}
		}

		temp = temp->next;

	}

	cout << "\nPage  " << *currentPage << " / " << maxPage << endl;
}

/*
===========================================================
DATA CONTROL FUNCTIONS
===========================================================
*/

// ================== ADD TUTOR VALIDATION ================== //

// Validate Tutor Name
int checkTutorName(string tutorName, Tutor* head)
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

// Validate number of active tutors per center
bool checkCenterCount(int centerCode, Tutor* head)
{
	Tutor* current = head;
	int count = 0;
	while (current != NULL)
	{
		if (current->centerCode == centerCode && current->dateTerminated == 0) {
			count++;
		}
		current = current->next;
	}

	if (count >= 10) {
		return true;
	}
	else {
		return false;
	}
}

// Add New Tutor
void addTutor(Tutor **head, Tutor **tail, int *tutorListCount) {

	int flag = 0, tutorId = 0;
	int centerChoice, subject_choice, centerCode, subjectCode, hourlyPayRate;
	string name, phone, address, centerName, subjectName;
	time_t dateJoined = time(NULL) - 31536000;

	// Retrieving tutor id 
	sortByTutorId(head, tail, tutorListCount);
	if ((*tail) == NULL) {
		if ((*head) == NULL) {
			tutorId = 1;
		}
		else {
			tutorId = (*head)->tutorId + 1;
		}
	}
	else {
		tutorId = (*tail)->tutorId + 1;
	}

	flag = 0;

	while (flag == 0) { // Name
		flag = 1;
		cout << "Enter Tutor Name: ";
		cin.ignore();
		getline(cin, name);

		if (checkTutorName(name, *head)) { // validation
			cout << endl << "Tutor name exists. Please use a different name!" << endl << endl;
			flag = 0;
		}
		if (name.empty()) {
			cout << endl << "Empty inputs are not allowed. Please re-enter!" << endl << endl;
			flag = 0;
		}
	}

resetPhoneInput: // Phone Number
	cout << "Enter Phone Number: ";
	getline(cin, phone);

	if (phone.empty()) {
		cout << endl << "Please enter a phone number" << endl;
		goto resetPhoneInput;
	}

resetAddressInput: // Address
	cout << "Enter Address: ";
	getline(cin, address);

	if (address.empty()) {
		cout << endl << "Please enter an address" << endl;
		goto resetAddressInput;
	}

	flag = 0;

	while (flag == 0) { // Center Selection
		cout << endl << "Choose a center: \n 1- Pusat Asia Jaya \n 2- Pusat Megah Jaya \n 3- Pusat Suru Jaya\n\nEnter your choice: ";
		cin >> centerChoice;

		// Input validation
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Invalid input. Please provide a valid center id" << endl;
			continue;
		}

		centerCode = centerChoice;
		if (centerChoice == 1) {
			centerName = "Pusat Asia Jaya";
			flag = 1;
		}
		else if (centerChoice == 2) {
			centerName = "Pusat Megah Jaya";
			flag = 1;
		}
		else if (centerChoice == 3) {
			centerName = "Pusat Suru Jaya";
			flag = 1;
		}
		else {
			cout << endl << "Centre does not exist" << endl << endl;
			flag = 0;
			continue;
		}
		if (checkCenterCount(centerCode, *head)) {
			cout << endl << "The centre is already full!" << endl;
			flag = 0;
		}
	}


resetSubjectSelection: // Subject Selection + Hourly Pay Rate

	cout << endl << "Choose a subject: " << endl;
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
	cout << "Enter your choice: ";

	cin >> subject_choice;
	subjectCode = subject_choice;

	// Input validation
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "Invalid input. Please provide a valid subject id" << endl;
		goto resetSubjectSelection;
	}

	switch (subject_choice) {
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

	// RNG - Rating
	int rating = (rand() % 5) + 1;

	// Create new Node
	Tutor *newTutor = new Tutor(tutorId, name, dateJoined, hourlyPayRate, phone, address, centerCode, centerName, subjectCode, subjectName, rating, 0);

	insertIntoTheEndofList(newTutor, head, tail, tutorListCount);
}


// Add item into the list
void insertIntoTheEndofList(Tutor *newNode, Tutor** head, Tutor** tail, int *tutorListCount)
{
	// Check whether the list is empty?
	if ((*head) == NULL) // If list is empty
	{
		(*head) = newNode;
		newNode->prev = NULL;
	}
	else // Else list is not empty, update Tail
	{
		Tutor *temp = (*tail);
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = NULL;
		(*tail) = newNode;

	}
	*tutorListCount = *tutorListCount + 1;
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


// Delete Tutor - Binary Search
bool deleteTutor(Tutor** head, Tutor **tail, int size, int tutorId) {
	//To Delete Linked List Node: 
		// 1. Unhook the node
		// 2. Delete [node]

	time_t today = time(NULL);
	Tutor *data = binarySearchTutorId((*head), size, tutorId);

	// if record not found
	if (!data) {
		cout << endl << "Tutor cannot be deleted because tutor Id not found." << endl << endl;
		return false;
	}

	if (data->tutorId == tutorId) {
		// Verify termination date
		if (data->dateTerminated == 0) { // Not Terminated
			cout << endl << "Tutor cannot be deleted because tutor is not terminated." << endl << endl;
			return false;
		}
		else if (today - data->dateTerminated < 15552000) {
			// <6 months
			cout << endl << "Tutor cannot be deleted because terminated date is less than 6 months." << endl << endl;
			return false;
		}
		else { // Tutor can be deleted

			if (data == (*head)) {
				(*head) = data->next;
				(*head)->prev = NULL;
			}
			else if (data == (*tail)) {
				(*tail) = data->prev;
				(*tail)->next = NULL;
			}
			else {
				(data->prev)->next = data->next;
				(data->next)->prev = data->prev;
			}

			delete data;

			return true;
		}
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

//Bubble Sort - Sort tutor list by Tutor Id
void sortByTutorId(Tutor **head, Tutor **tail, int *count) {
	auto startTime = high_resolution_clock::now();

	Tutor **temp = head;

	for (int i = 0; i < *count; i++) {
		temp = head;
		bool swapped = false;

		for (int j = 0; j < *count - i - 1; j++) {
			Tutor* node1 = *temp;
			Tutor* node2 = node1->next;

			// Comparing values for tutor id
			if (node1->tutorId > node2->tutorId) {

				//Swap nodes
				*temp = swapNode(node1, node2);
				swapped = true;
			}

			temp = &(*temp)->next;

		}

		//Break the outer loop if no swap happens
		if (!swapped) {
			break;
		}
	}
	*tail = getTail(*temp);

	auto endTime = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(endTime - startTime);
	logToFile("Bubble Sort: " + to_string(duration.count()) + " microseconds");

}

// Quicksort - Sort by Hourly Pay
void sortByHourlyPay(Tutor** head, Tutor **tail) {
	auto startTime = high_resolution_clock::now();
	(*head) = quickSortRecur((*head), (*tail));
	(*tail) = getTail(*head);

	auto endTime = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(endTime - startTime);
	logToFile("QuickSort: " + to_string(duration.count()) + " microseconds");
}

// Merge Sort - Sort by Tutor Rating
void sortByRating(Tutor **head, Tutor **tail) {
	auto startTime = high_resolution_clock::now();

	MergeSort(head);
	*tail = getTail(*head);

	auto endTime = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(endTime - startTime);
	logToFile("Merge Sort: " + to_string(duration.count()) + " microseconds");
}


/*
===========================================================================
SEARCH FUNCTIONS
===========================================================================
*/

// Search by Tutor Id - Binary Search
void searchByTutorId(Tutor *head, Tutor *tail, int *tutorListSize, string *userRole) {
	int tutorId = -1, opt = -1;
resetTutorIdSearch:

	cout << "Enter tutor id: ";
	cin >> tutorId;

	// Input validation
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please provide a valid id" << endl << endl;
		goto resetTutorIdSearch;
	}

	do {
		Tutor* data = displayTutorDetails(head, *tutorListSize, tutorId);

		if (!data) {
			break;
		}

		tutorMenuOptions(userRole);
		cin >> opt;
		tutorId = tutorMenuControl(head, tail, *tutorListSize, opt, tutorId);
	} while (opt > 0);
}


// Search by Tutor Rating - Linear Search
void searchByTutorRating(Tutor *head, int *tutorListSize) {
	int tutorRating = -1, opt = -1;
resetTutorRatingSearch:

	cout << "Enter tutor rating: ";
	cin >> tutorRating;

	// Input validation
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "Invalid input. Please provide a valid id" << endl << endl;
		goto resetTutorRatingSearch;
	}
	cout << endl;

	Tutor *temp = head;
	tm* dateTerminated;

	// Header Display
	cout << " Id" << "\t| ";
	cout << setw(30) << left << "Tutor Name" << " | ";
	cout << "Pay Rate" << "\t| ";
	cout << "Center Name" << "\t\t| ";
	cout << "Rating" << " | ";
	cout << "Date Terminated" << endl;

	for (int i = 0; i < 120; i++)
	{
		cout << "=";
	}

	// Linear Search for Rating
	while (temp != NULL) {

		if (temp->rating == tutorRating) {

			cout << endl << " #" << (temp)->tutorId << "\t| ";
			cout << setw(30) << left << (temp)->name << " | ";
			cout << (temp)->hourlyPayRate << "\t\t| ";
			cout << (temp)->centerName << "\t| ";
			cout << (temp)->rating << "\t | ";

			// Processing Date Terminated into readable string
			dateTerminated = localtime(&(temp)->dateTerminated);
			if (dateTerminated->tm_year + 1900 == 1970) {
				cout << " - " << endl;
			}
			else {
				cout << dateTerminated->tm_year + 1900 << "-" << dateTerminated->tm_mon + 1 << "-" << dateTerminated->tm_mday << endl;
			}
		}

		temp = temp->next;
	}
	cout << endl;
}


/*
===========================================================================
UTILITY FUNCTIONS FOR SORTING/BINARY SEARCH
===========================================================================
*/

// Binary Search
Tutor *binarySearchTutorId(Tutor* head, int size, int tutorId) {
	int low = 1, mid, high = size;

	Tutor *temp = head;

	while (low <= high) {
		mid = (low + high) / 2;

		// Find Tutor in the middle of list
		Tutor *midTutor = findMid(temp, low, mid);

		// Evaluate if record = tutorId
		if (midTutor->tutorId == tutorId) {
			return midTutor;
		}
		else {
			if (tutorId < midTutor->tutorId) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
				temp = midTutor->next;
			}
		}
	}

	return NULL;
}

// Find the Middle element in the list - for Binary Search
Tutor* findMid(Tutor *head, int index, int mid) {

	if (index == mid) {
		return head;
	}

	// Search from Head
	for (Tutor *i = head; i->next != NULL; i = i->next) {

		if (index == mid) {
			return i;
		}
		index++;
	}
	return NULL;
}

// Swap the nodes in the linked list
Tutor* swapNode(Tutor *node1, Tutor *node2) {
	Tutor *nextNode = node2->next;
	Tutor *prevNode = node1->prev;

	node2->next = node1;
	node2->prev = prevNode;
	node1->next = nextNode;
	node1->prev = node2;

	if (nextNode != NULL) {
		nextNode->prev = node1;
	}

	if (prevNode != NULL) {
		prevNode->next = node2;
	}
	return node2;
}

// Returns the last node of the list
Tutor *getTail(Tutor *cur)
{
	while (cur != NULL && cur->next != NULL) {
		cur = cur->next;
	}

	return cur;
}

// Partitions the list then return the pivot
Tutor *partition(Tutor *head, Tutor *tail, Tutor **newHead, Tutor **newEnd)
{
	Tutor *pivot = tail;
	Tutor  *current = head, *listEnd = pivot;
	Tutor *prev = NULL;


	while (current != pivot)
	{
		if (current->hourlyPayRate < pivot->hourlyPayRate)
		{
			// First node that has a value less than the pivot - becomes the new head
			if ((*newHead) == NULL) {
				(*newHead) = current;
			}

			prev = current;
			current = current->next;
		}
		else // If current Tutor is greater than pivot
		{
			// Move current Tutor to next of listEnd, and change listEnd
			if (prev) {
				prev->next = current->next;
			}

			Tutor *tmp = current->next;
			tmp->prev = current->prev;
			current->next = NULL;
			current->prev = listEnd;
			listEnd->next = current;
			listEnd = current;
			current = tmp;

		}
	}

	// If the pivot data is the smallest element in the current list, pivot becomes the head
	if ((*newHead) == NULL) {
		(*newHead) = pivot;
	}

	// Update newEnd to the current last node
	(*newEnd) = listEnd;

	return pivot;
}

Tutor *quickSortRecur(Tutor *head, Tutor *tail)
{
	if (!head || head == tail) {
		return head;
	}

	Tutor *newHead = NULL, *newEnd = NULL;

	// Partition the list
	Tutor *pivot = partition(head, tail, &newHead, &newEnd);

	// If pivot is the smallest element no recursion needed for the left side.
	if (newHead != pivot)
	{
		// Set the Tutor before the pivot Tutor as NULL		
		Tutor *tmp = pivot->prev;
		tmp->next = NULL;

		// Recur for the list before pivot
		newHead = quickSortRecur(newHead, tmp);

		// Change next of last Tutor of the left half to pivot
		tmp = getTail(newHead);
		tmp->next = pivot;
	}

	// Recur for the list after the pivot element
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;
}

Tutor* Merge(Tutor* h1, Tutor* h2)
{
	Tutor *t1 = new Tutor();
	Tutor *t2 = new Tutor();
	Tutor *temp = new Tutor();

	// Return if the first list is empty.
	if (h1 == NULL)
		return h2;

	// Return if the Second list is empty.
	if (h2 == NULL)
		return h1;

	t1 = h1;

	// Loop 2nd list, merge with 1st list
	while (h2 != NULL)
	{
		t2 = h2;

		// Shifting second list head to the next.
		h2 = h2->next;
		t2->prev = NULL;
		t2->next = NULL;

		// If the data value is lesser than the head of first list add that Tutor at the beginning.
		if (h1->rating > t2->rating)
		{
			h1->prev = t2;
			t2->next = h1;
			h1 = t2;
			t1 = h1;
			continue;
		}

		// Traverse the first list.
	flag:
		if (t1->next == NULL)
		{
			t1->next = t2;
			t2->prev = t1;
			t1 = t1->next;
		}
		// Traverse first list until t2->data more than Tutor's data.
		else if ((t1->next)->rating <= t2->rating)
		{
			t1 = t1->next;
			goto flag;
		}
		else
		{
			// Insert the Tutor as t2->data is lesser than the next Tutor.
			temp = t1->next;
			t1->next = t2;
			t2->next = temp;
			t2->prev = t1;
			temp->prev = t2;
		}
	}

	// Return the head of new sorted list.
	return h1;
}


// Merge Sort
void MergeSort(Tutor **head)
{
	Tutor *first = new Tutor;
	Tutor *second = new Tutor;
	Tutor *temp = new Tutor;
	first = *head;
	temp = *head;

	// Return if list have less than two nodes.
	if (first == NULL || first->next == NULL)
	{
		return;
	}
	else
	{
		// Break the list into two half as first and second as head of list.
		while (first->next != NULL)
		{
			first = first->next;
			if (first->next != NULL)
			{
				temp = temp->next;
				first = first->next;
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *head;
	}

	// MergeSort both lists
	MergeSort(&first);
	MergeSort(&second);

	// Merge the both lists into a single list.      
	*head = Merge(first, second);
}

