#pragma once

#include<string>
#include<ctime>

using namespace std;
struct Tutor { //Implementation of Tutor for linked list

	//Data Fields
	int tutorId;
	std::string name;
	tm dateJoined;
	tm dateTerminated;
	double hourlyPayRate;
	std::string phone;
	std::string address;
	int centerCode;
	std::string centerName;
	int subjectCode;
	std::string subjectName;
	int rating;

	// Link address
	Tutor* next;
	Tutor* prev;

public: //Constructor
	Tutor(int tutorId, string name, tm dateJoined, double hourlyPayRate, string phone, string address, int centerCode, string centreName, int subjectCode, string subjectName, int rating); //Base constructor
};

void test(std::string test); //Sample Function

void mainMenu(); // Main Menu
void tutorListMenu(); // Main Menu > Display All Tutor
void tutorMenuControl(int* input); //Tutor List Menu Control

void addTutor(Tutor* head, Tutor* newData); //Adds a new tutor to the list
//void modifyTutor(Tutor* head, std::string tutorId, std::string data, std::string attribute); //Updates the tutor record
//bool deleteTutor(Tutor* head, std::string tutorId); //Deletes the selected tutor and returns True/False to indicate success
//void displayTutorList(Tutor* head) {} //Displays the list of all tutors
//void sortByTutorId(Tutor** head){} //Sort the tutor list by tutor id
//void sortByHourlyPay(Tutor** head) {} //Sort the tutor list by hourly pay
//void sortByRating(Tutor** head) {} //Sort the tutor list by rating
//Tutor* searchByTutorId(Tutor* head, int tutorId) {} //Search for a tutor by tutor id
//Tutor* searchhByRating(Tutor* head, int rating) {} //Search for a tutor by rating