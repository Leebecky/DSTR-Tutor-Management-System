#pragma once

#include<string>
#include<ctime>

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
};

void test(std::string test);
//void addTutor(Tutor* head, Tutor* newData); //Adds a new tutor to the list
//void modifyTutor(Tutor* head, std::string tutorId, std::string data, std::string attribute); //Updates the tutor record
//bool deleteTutor(Tutor* head, std::string tutorId); //Deletes the selected tutor and returns True/False to indicate success
//void displayTutorList(Tutor* head) {} //Displays the list of all tutors
//void sortByTutorId(Tutor** head){} //Sort the tutor list by tutor id
//void sortByHourlyPay(Tutor** head) {} //Sort the tutor list by hourly pay
//void sortByRating(Tutor** head) {} //Sort the tutor list by rating
//Tutor* searchByTutorId(Tutor* head, int tutorId) {} //Search for a tutor by tutor id
//Tutor* searchhByRating(Tutor* head, int rating) {} //Search for a tutor by rating