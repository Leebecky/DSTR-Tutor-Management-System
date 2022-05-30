#pragma once

#include <iomanip>
#include<string>
#include<ctime>
#include<chrono>
#include<iostream>
#include<fstream> //header file used for file i/o

using namespace std;
using namespace std::chrono;

struct Tutor { //Implementation of Tutor for linked list

	//Data Fields
	int tutorId;
	std::string name;
	time_t dateJoined;
	time_t dateTerminated;
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
	Tutor();
	Tutor(int tutorId, string name, time_t dateJoined, double hourlyPayRate, string phone, string address, int centerCode, string centreName, int subjectCode, string subjectName, int rating, time_t dateTerminated); //Base constructor
};

/*
===========================================================
GENERAL FUNCTIONS
===========================================================
*/
bool login(string *userRole); // User login authentication
void logToFile(string data); // log time taken to file
void generateData(Tutor **head, Tutor** tail, int *tutorListCount); // Contains the predefined data


/*
===========================================================
MENU DISPLAY & CONTROL FUNCTIONS
===========================================================
*/

void mainMenu(); // Main Menu
void tutorListMenu(string *userRole); // Main Menu > Display All Tutor
void tutorListMenuControl(int* input, Tutor** head, Tutor** tail, int *count, int* currentPage, string *userRole); //Tutor List Menu Control
void tutorMenuOptions(string *userRole);
int tutorMenuControl(Tutor *head, Tutor *tail, int size, int menuSelection, int tutorId, string *userRole);

/*
===========================================================
DATA DISPLAY FUNCTIONS
===========================================================
*/

void displayTutorList(Tutor* head, int size, int* currentPage); //Displays the list of all tutors
Tutor *displayTutorDetails(Tutor *head, int size, int tutorId); //Displays the details of a tutor

/*
===========================================================
DATA CONTROL FUNCTIONS
===========================================================
*/

void addTutor(Tutor **head, Tutor **tail, int *tutorListCount); //Adds a new tutor to the list

void insertIntoTheEndofList(Tutor* newNode, Tutor** head, Tutor** tail, int *tutorListCount);

bool modifyTutor(Tutor *data, string *dataValue, string updateAttribute); //Updates the tutor record
bool deleteTutor(Tutor** head, Tutor  **tail, int size, int tutorId); //Deletes the selected tutor and returns True/False to indicate success


/*
===========================================================
SORTING FUNCTIONS
===========================================================
*/
void sortByTutorId(Tutor **head, Tutor **tail, int *count); //Sort the tutor list by tutor id
void sortByHourlyPay(Tutor** head, Tutor **tail); //Sort the tutor list by hourly pay
void sortByRating(Tutor** head, Tutor **tail); //Sort the tutor list by rating

// ==== Utility Sorting Functions  //
Tutor *getTail(Tutor *cur);
Tutor* swapNode(Tutor* node1, Tutor* node2);
void MergeSort(Tutor** head); //MergeSort the tutor list by rating
Tutor *quickSortRecur(Tutor *head, Tutor *tail);
Tutor* findMid(Tutor *head, int index, int mid);

/*
===========================================================
SEARCHING FUNCTIONS
===========================================================
*/
Tutor *binarySearchTutorId(Tutor* head, int size, int tutorId);
void searchByTutorId(Tutor *head, Tutor *tail, int *tutorListSize, string *userRole); //Search for a tutor by tutor id
void searchByTutorRating(Tutor *head, int *tutorListSize); //Search for a tutor by rating