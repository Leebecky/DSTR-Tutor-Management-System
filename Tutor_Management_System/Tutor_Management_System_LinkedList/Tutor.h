#pragma once

#include<string>
#include<ctime>
#include<chrono>
#include<fstream> //header file used for file i/o

using namespace std;
using namespace std::chrono;

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
	Tutor();
	Tutor(int tutorId, string name, tm dateJoined, double hourlyPayRate, string phone, string address, int centerCode, string centreName, int subjectCode, string subjectName, int rating); //Base constructor
};


//General Functions
bool login(string *userRole);
void mainMenu(); // Main Menu
void tutorListMenu(string *userRole); // Main Menu > Display All Tutor
void tutorMenuControl(int* input, Tutor** head, Tutor** tail, int *count, int* currentPage); //Tutor List Menu Control
void generateData(Tutor **head, Tutor** tail, int *tutorListCount); // Contains the predefined data
void logToFile(string data); // log time taken to file

//void addTutor(Tutor* head, Tutor* newData); //Adds a new tutor to the list
//void modifyTutor(Tutor* head, std::string tutorId, std::string data, std::string attribute); //Updates the tutor record
//bool deleteTutor(Tutor* head, std::string tutorId); //Deletes the selected tutor and returns True/False to indicate success
void displayTutorList(Tutor* head, int size, int* currentPage); //Displays the list of all tutors
void sortByTutorId(Tutor **head, Tutor **tail, int *count); //Sort the tutor list by tutor id
Tutor *getTail(Tutor *cur);
Tutor* swapNode(Tutor* node1, Tutor* node2);
void sortByHourlyPay(Tutor** head, Tutor **tail); //Sort the tutor list by hourly pay
void sortByRating(Tutor** head, Tutor **tail); //Sort the tutor list by rating
void MergeSort(Tutor** head); //MergeSort the tutor list by rating

//Tutor* searchByTutorId(Tutor* head, int tutorId) {} //Search for a tutor by tutor id
//Tutor* searchhByRating(Tutor* head, int rating) {} //Search for a tutor by rating