#pragma once

#include <string>
#include <ctime>
#include <chrono>
#include<iostream>
#include<fstream> //header file used for file i/o
#include<iomanip>

using namespace std;
using namespace std::chrono;

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
};

/*
===========================================================
GENERAL FUNCTIONS
===========================================================
*/
void generateData(Tutor* head);	// Predefined Tutors
bool login(string *userRole);
void logToFile(string data);
/*
===========================================================
MENU DISPLAY & CONTROL FUNCTIONS
===========================================================
*/

void mainMenu(); // Main Menu
void tutorListMenu(string *userRole, Tutor* ptr, int* size, int* currentPage); // Main Menu > Display All Tutor
void tutorListMenuControl(int* input, Tutor** head, int* size, int* currentPage, string *userRole); //Tutor List Menu Control
void tutorMenuOptions(string *userRole);
int tutorMenuControl(Tutor *head, int size, int menuSelection, int tutorId, string *userRole);


/*
===========================================================
DATA DISPLAY FUNCTIONS
===========================================================
*/

Tutor *displayTutorDetails(Tutor *head, int size, int tutorId);
void displayTutorList(Tutor* head, int size, int* currentPage); //Displays the list of all tutors

/*
===========================================================
DATA CONTROL FUNCTIONS
===========================================================
*/

void addTutor(Tutor** head, int* size); //Adds a new tutor to the list
bool modifyTutor(Tutor *data, string *dataValue, string updateAttribute); //Updates the tutor record
bool deleteTutor(Tutor** head, int low, int size, int tutorId); //Deletes the selected tutor and returns True/False to indicate success

void resize(Tutor **test, int *currentSize);
/*
===========================================================
SORTING FUNCTIONS
===========================================================
*/
void sortByTutorId(Tutor* head, int size); //Sort the tutor list by tutor id
void sortByHourlyPay(Tutor* head, int low, int high); //Sort the tutor list by hourly pay
void sortByRating(Tutor* head, int low, int high); //Sort the tutor list by rating

// ==== Utility Sorting Functions  //
void mergeSorting(Tutor* head, int low, int high, int mid); // MergeSort function for sortByRating

/*
===========================================================
SEARCHING FUNCTIONS
===========================================================
*/

Tutor *binarySearchTutorId(Tutor* head, int size, int tutorId); //Search tutor record by IF
int binarySearchTutorIndex(Tutor* head, int size, int tutorId);
void SearchByRating(Tutor* head, int rating, int size); // Search/filter tutor(s) by rating