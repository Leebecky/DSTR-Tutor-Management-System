#include "Tutor.h"
#include <string>
#include <iostream>
using namespace std;

Tutor tutorArray[3];

Tutor::Tutor() {}

Tutor::Tutor(int tutorId)  //Sample of custom constructor
{
	this->tutorId = tutorId;
}


void test(std::string test) { //Sample Function

	tutorArray[0] = Tutor(1);
	//tutorArray[1] = Tutor(2);
	//tutorArray[2] = Tutor(3);


	std::cout << test << " | " << tutorArray[0].tutorId;
}

void definedTutor(Tutor* head) {
	int tutorIdList[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	//int tutorIdList[15] = { 9, 10, 1, 4, 5, 8, 11, 2, 3, 12, 13, 15, 14, 6, 7};		// test sort Id
	string nameList[15] = {"Ali", "Abu", "Ahmad", "Amin", "Bubu", "Cici", "Ken", "Ray", "Mei", "Den", "Kai", "Ben", "Wen", "Jay", "Lim"};
	double hourlyPayRateList[15] = {20.0, 35.5, 15.5, 20.0, 30.0, 45.0, 20.5, 21.5, 33.0, 10.5, 15.0, 30.0, 25.5, 27.0, 40.0};
	int centerCodeList[15] = {1, 1, 2, 2, 3, 4, 5, 2, 4, 3, 5, 1, 2, 4, 5};
	string centerNameList[15] = {"KL", "KL", "BM", "BM", "JB", "KK", "SG", "BM", "KK", "JB", "SG", "KL", "BM", "KK", "JB"};
	int ratingList[15] = {4, 5, 3, 5, 4, 3 , 4, 2, 5, 4, 3, 5, 2, 4, 3};

	for (int i = 0; i < 15; i++) {
		(head + i)->tutorId = tutorIdList[i];
		(head + i)->name = nameList[i];
		(head + i)->hourlyPayRate = hourlyPayRateList[i];
		(head + i)->centerCode = centerCodeList[i];
		(head + i)->centerName = centerNameList[i];
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


void tutorListMenu(Tutor* head, int* size, int* currentPage)
{
	cout << "Tutor List:" << endl;
	displayTutorList(head, *size, currentPage);
	cout << "\n1. View Tutor" << endl;
	cout << "2. Sort by Tutor ID" << endl;
	cout << "3. Sort by Tutor Hourly Pay" << endl;
	cout << "4. Sort by Tutor Rating" << endl;
	cout << "5. Delete Tutor" << endl;
	cout << "6. Next page" << endl;
	cout << "7. Previous page" << endl;
	cout << "0. Back to Main Menu" << endl;
	cout << "Please enter the desired menu option: ";
}

void tutorMenuControl(int* input, Tutor* head, int* size, int* currentPage)
{
	int inputId;
	bool result;

	switch (*input)
	{
	case 1:
		cout << "Tutor Details Here" << endl;
		break;
	case 2:
		sortByTutorId(head, *size);
		cout << "Sort by Tutor Id" << endl;
		break;
	case 3:
		sortByHourlyPay(head, 0, *size - 1);
		cout << "Sort by Pay" << endl;
		break;
	case 4:
		sortByRating(head, 0, *size - 1);
		cout << "Sort by Rating" << endl;
		break;
	case 5:
		cout << "Enter tutor id: ";
		cin >> inputId;
		sortByTutorId(head, *size);
		result = deleteTutor(head, 0, *size - 1, inputId);

		if (result) {
			*size = *size - 1;
			cout << "tutorMenuControl *size = " << *size << endl;
			cout << "Tutor deleted." << endl;
		}
		else {
			cout << "Tutor cannot be deleted." << endl;
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

void displayTutorList(Tutor* head, int size, int* currentPage) {
	int currentPosition, maxPosition, maxPage;
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
	cout << "Tutor Name" << "\t| ";
	cout << "Pay Rate" << "\t| ";
	cout << "Center Code" << "\t| ";
	cout << "Center Name" << "\t| ";
	cout << "Rating" << endl;

	for (int i = currentPosition; i < maxPosition; i++)
	{
		cout << " #" << (head + i)->tutorId << "\t| ";
		cout << (head + i)->name << "\t\t| ";
		cout << (head + i)->hourlyPayRate << "\t\t| ";
		cout << (head + i)->centerCode << "\t\t| ";
		cout << (head + i)->centerName << "\t\t| ";
		cout << (head + i)->rating << endl;
	}

	cout << "\nPage  " << *currentPage << " / " << maxPage << endl;
}

void addTutor(Tutor * head, Tutor * newData)
{

}

// Bubble Sort
void sortByTutorId(Tutor* head, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((head + i)->tutorId > (head + j)->tutorId) {

				Tutor temp = head[i];
				head[i] = head[j];
				head[j] = temp;
			}
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

bool deleteTutor(Tutor* head, int low, int size, int tutorId) {
	int mid, p = 0, high = size;

	while (low <= high) {
		mid = (low + high) / 2;

		if (tutorId == (head + mid)->tutorId) {
			// Need check terminated date

			cout << endl;
			for (int i = mid; i < size; i++) {
				cout << "i = " << i << endl;
				head[i] = head[i + 1];
			}

			p = 1;
			return true;
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

	if (p != 1) {
		return false;
	}

}
