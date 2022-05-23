#pragma once

#include <string>
#include <ctime>
#include <chrono>
using namespace std;
	struct Tutor { //Implementation of Tutor for array

	//Data Fields
	int tutorId;
	string name;
	time_t dateJoined;
	time_t dateTerminated;
	double hourlyPayRate;
	string phone;
	string address;
	int centerCode;
	string centerName;
	int subjectCode;
	string subjectName;
	int rating;

public: //Constructor
	Tutor();
	Tutor(int tutorId); //Sample of custom constructor
};

void test(string test);  //Sample Function

void definedTutor(Tutor* head);	// Predefined Tutors

void mainMenu(); // Main Menu
void tutorListMenu(Tutor* ptr, int* size, int* currentPage); // Main Menu > Display All Tutor
void tutorMenuControl(int* input, Tutor* head, int* size, int* currentPage); //Tutor List Menu Control

void addTutor(Tutor* head, Tutor* newData); //Adds a new tutor to the list
//void modifyTutor(Tutor* head, string tutorId, string data, string attribute); //Updates the tutor record
bool deleteTutor(Tutor* head, int low, int size, int tutorId); //Deletes the selected tutor and returns True/False to indicate success
void displayTutorList(Tutor* head, int size, int* currentPage); //Displays the list of all tutors
void sortByTutorId(Tutor* head, int size); //Sort the tutor list by tutor id
void sortByHourlyPay(Tutor* head, int low, int high); //Sort the tutor list by hourly pay
void sortByRating(Tutor* head, int low, int high); //Sort the tutor list by rating
void mergeSorting(Tutor* head, int low, int high, int mid); // MergeSort function for sortByRating
//Tutor* searchByTutorId(Tutor* head, int tutorId) {} //Search for a tutor by tutor id
//Tutor* searchhByRating(Tutor* head, int rating) {} //Search for a tutor by rating