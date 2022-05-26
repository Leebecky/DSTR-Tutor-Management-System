#include "Tutor.h"

#pragma warning(disable : 4996)

//Login Account Credentials
bool login(string *userRole) {
	string username, password;
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);

	if (username == "Admin" && password == "admin123") { //Admin account
		*userRole = "Admin";
		return true;
	}
	else if (username == "Tutor" && password == "Tutor123") { //Tutor account
		*userRole = "Tutor";
		return true;
	}
	else {
		cout << endl << "Error logging in. Please check your credentials and try again!" << endl << endl;
		return false;
	}

}

void logToFile(string data) {
	ofstream logFile("Tutor System Log - Array.txt", ios_base::app | ios_base::out);

	logFile << data << endl;

}

void definedTutor(Tutor* head) {
	time_t dateJoined = time(NULL) - 31536000;
	time_t withinMonths = time(NULL) - 2592000;
	time_t outsideMonths = time(NULL) - 17280000;

	int tutorIdList[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	//int tutorIdList[15] = { 9, 10, 1, 4, 5, 8, 11, 2, 3, 12, 13, 15, 14, 6, 7};		// test sort Id
	string nameList[15] = {"Zainul bin Zabidin", "Alina Chan Mei Yi", "Dhanyasree a/p Muthusamy", "Cassim Tan", "Nurul Syafiqah", "Maggie Simon", "Ai Ling Tan", "Diviya Nathan", "Daryl Arul", "Suhaimi bin Suhakam", "Paula Maruice", "Chan Mei Kong", "Cassi Hassan", "Nurul Aslina", "Li Su Yan"};
	time_t dateTerminated[15] = { 0, withinMonths, outsideMonths, 0, withinMonths, 0, 0, outsideMonths, withinMonths, outsideMonths,  0, withinMonths, withinMonths, outsideMonths, 0 };
	double hourlyPayRateList[15] = {75.00, 80.00, 60.00, 75.00, 65.00, 50.00, 75.00, 50.00, 75.00, 55.00, 60.00, 55.00, 80.00, 50.00, 78.50};
	string phoneList[15] = { "011-1234567" , "016-5423412" , "017-3415136" , "016-1237568" , "011-845656455" , "011-57457823", "015-123434656", "011-958567555", "016-98653544", "011-845656455", "016-45452777", "012-24562453", "016-756455554", "011-673334s76", "018-88345346" };
	string addressList[15] = { "19, Jalan A12, Taman Asia, 68000 Ampang, Selangor", "22, Jalan B1, Taman Bestari, 68000 Ampang, Selangor", "A12, Block-C, Oakleaf Condominium, 51000 Kuala Lumpur", "97, Jalan ST1, Taman Stadhuys, 68000 Ampang, Selangor", "65, Jalan M1, Taman Mega, 68000 Ampang, Selangor", "11, Jalan M1, Taman Mega, 68000 Ampang, Selangor", "65, Jalan M1, Taman Mega, 68000 Ampang, Selangor", "561, Jalan Sinar 1, Taman Sinar, 68000 Ampang, Selangor", "17, Jalan M2, Taman Mega, 68000 Ampang, Selangor", "65, Jalan M1, Taman Mega, 68000 Ampang, Selangor", "67, Jalan Bkt Utama, Taman Bukit, 68000 Ampang, Selangor", "7-A-1, Emerald Condominium, 68000 Ampang, Selangor", "97, Jalan Bendara, Taman Antarabangsa, 68000 Ampang, Selangor", "65, Jalan M3, Taman Mega, 68000 Ampang, Selangor", "99, Jalan B1, Taman Bestari, 68000 Ampang, Selangor" };
	int centerCodeList[15] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3};
	string centerNameList[15] = { "Pusat Asia Jaya", "Pusat Asia Jaya", "Pusat Asia Jaya", "Pusat Asia Jaya", "Pusat Asia Jaya", "Pusat Megah Jaya", "Pusat Megah Jaya", "Pusat Megah Jaya", "Pusat Megah Jaya", "Pusat Megah Jaya", "Pusat Suru Jaya", "Pusat Suru Jaya", "Pusat Suru Jaya", "Pusat Suru Jaya", "Pusat Suru Jaya"};
	int subjectCodeList[15] = {1, 5, 2, 3, 4, 9, 10, 2, 8, 7, 4 ,5, 3, 1, 10};
	string subjectNameList[15] = { "Bahasa Melayu", "Biology", "English", "Sejarah", "Geografi", "Mathematics", "Additional Mathematics", "English", "Chemistry", "Physics", "Geografi", "Biology", "Chemistry", "Bahasa Melayu", "Additioanl Mathematics" };
	int ratingList[15] = {3, 5, 1, 3, 2, 2, 5, 1, 2, 5, 4, 4, 5, 3, 4};

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

void mainMenu()
{
	cout << "Main Menu:" << endl;
	cout << "1. Display All Tutor" << endl;
	cout << "2. Add New Tutor" << endl;
	cout << "3. Search by Tutor ID" << endl;
	cout << "4. Search by Tutor Rating" << endl;
	cout << "0. Exit" << endl;
	cout << "Please enter the desired menu option: ";
}


void tutorListMenu(string *userRole, Tutor* head, int* size, int* currentPage)
{
	cout << "Tutor List:" << endl;
	displayTutorList(head, *size, currentPage);
	cout << "\n1. View Tutor" << endl;
	cout << "2. Sort by Tutor ID" << endl;
	cout << "3. Sort by Tutor Hourly Pay" << endl;
	cout << "4. Sort by Tutor Rating" << endl;
	
	if (*userRole == "Admin") {
		cout << "5. Delete Tutor" << endl;
	}

	cout << "6. Next page" << endl;
	cout << "7. Previous page" << endl;
	cout << "0. Back to Main Menu" << endl;
	cout << "Please enter the desired menu option: ";
}

// View Tutor > Menu
void tutorMenuOptions(string *userRole) {
	int menuSelection = -1;
	if (*userRole == "Admin") {
		cout << "1. Modify Address" << endl;
		cout << "2. Modify Phone Number" << endl;
	}
	cout << "3. Next Tutor Record" << endl;
	cout << "4. Previous Tutor Record" << endl;
	cout << "0. Back to Display Menu" << endl;
	cout << "Please enter the desired menu option: ";
}

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

// View Tutor > Menu Control
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
		if (dataIndex + 1 == size) {
			dataIndex = 0;
		}
		else {
			dataIndex = dataIndex + 1;
		}

		return head[dataIndex].tutorId;
	case 4:
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

void displayTutorList(Tutor* head, int size, int* currentPage) {
	int currentPosition, maxPosition, maxPage;
	tm* dateTerminated;
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

	cout << " Id" << "\t| ";
	cout << setw(30) << left << "Tutor Name" << " | ";
	cout << "Pay Rate" << "\t| ";
	cout << "Center Name" << "\t\t| ";
	cout << "Rating" << "\t| ";
	cout << "Date Terminated" << endl;

	for (int i = 0; i < 120; i++) {
		cout << "=";
	}

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

Tutor *displayTutorDetails(Tutor *head, int size, int tutorId) {
	Tutor *data = binarySearchTutorId(head, size, tutorId);

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
	cout << "Hourly Pay Rate: " << data->hourlyPayRate << endl;
	cout << "Date Joined: \t" << data->dateJoined << endl;
	cout << "Center Code: \t" << data->centerCode << endl;
	cout << "Center Name: \t" << data->centerName << endl;
	cout << "Subject Code: \t" << data->subjectCode << endl;
	cout << "Subject Name: \t" << data->subjectName << endl;
	cout << "Date Terminated: " << data->dateTerminated << endl;
	cout << "=================================================================" << endl << endl;

	return data;
}

// Binary Search
Tutor *binarySearchTutorId(Tutor* head, int size, int tutorId) {
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

void addTutor(Tutor * head, Tutor * newData)
{

}

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
