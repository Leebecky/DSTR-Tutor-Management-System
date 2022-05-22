#include<string>
#include<iostream>
#include<ctime>

#include "Tutor.h"

using namespace std;

Tutor::Tutor(int tutorId, string name, tm dateJoined, double hourlyPayRate, string phone, string address, int centerCode, string centerName, int subjectCode, string subjectName, int rating)  //Base Constructor
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

}


//Display the main menu
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


//Display the menu when viewing the tutor list
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


//Redirects the user based on given input
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


void preDefinedData(Tutor *head) {
	Tutor *data1 = new Tutor("1", "Zainul bin Zabidin", tm(), 150.00, "011-1234567", "19, Jalan A12, Taman Asia, 68000 Ampang, Selangor", 1, "Pusat Asia Jaya", 1, "Bahasa Melayu", 4);
	Tutor *data2 = new Tutor("2", "Alina Chan Mei Yi", tm(), 250.00, "016-5423412", "22, Jalan B1, Taman Bestari, 68000 Ampang, Selangor", 1, "Pusat Asia Jaya", 5, "Biology", 5);
	Tutor *data3 = new Tutor("3", "Dhanyasree a/p Muthusamy", tm(), 200.00, "017-3415136", "A12, Block-C, Oakleaf Condominium, 51000 Kuala Lumpur", 1, "Pusat Asia Jaya", 2, "English", 4);
	Tutor *data4 = new Tutor("4", "Zainul bin Zabidin", tm(), 150.00, "011-1234567", "19, Jalan A12, Taman Asia, 68000 Ampang, Selangor", 1, "Pusat Asia Jaya", 1, "Bahasa Melayu", 4.5);
	Tutor *data5 = new Tutor("5", "Zainul bin Zabidin", tm(), 150.00, "011-1234567", "19, Jalan A12, Taman Asia, 68000 Ampang, Selangor", 1, "Pusat Asia Jaya", 1, "Bahasa Melayu", 4.5);
}

void addTutor(Tutor * head, Tutor * newData)
{

}

