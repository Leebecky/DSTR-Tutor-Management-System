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


void tutorListMenu()
{
	cout << "Tutor List:" << endl;
	cout << "1. View Tutor" << endl;
	cout << "2. Sort by Tutor ID" << endl;
	cout << "3. Sort by Tutor Hourly Pay" << endl;
	cout << "4. Sort by Tutor Rating" << endl;
	cout << "5. Delete Tutor" << endl;
	cout << "Next page" << endl;
	cout << "Previous page" << endl;
	cout << "0. Back to Main Menu" << endl;
	cout << "Please enter the desired menu option: ";
}

void tutorMenuControl(int* input)
{
	switch (*input)
	{
	case 1:
		cout << "Tutor Details Here" << endl;
		break;
	case 2:
		cout << "Sort by Tutor Id" << endl;
		break;
	case 3:
		cout << "Sort by Pay" << endl;
		break;
	case 4:
		cout << "Sort by Rating" << endl;
		break;
	case 5:
		cout << "Enter tutor id: " << endl;
		break;
	default:
		break;
	}
}


void addTutor(Tutor * head, Tutor * newData)
{

}
