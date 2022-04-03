// Tutor_Management_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct Tutors {
	int tutorID;	// Tutor ID in the center
	string name;	// Tutor name in the center
	string dateJoined;	// Date of joining the center
	string dateTerminated;	// Date of leaving the center
	float payRate;	// Tutor pay rate in the center
	string phone;	// Tutor phone number
	string address;	// Tutor home address
	int centreCode;	// Code of centre tutor working at
	string cntreName;	// Name of centre tutor working at
	int subjectCode;	// Code of subject tutor teaching
	string subjectName;	// Name of subject tutor teaching
	int rating;		// Tutor Performance in the center
};

void sortID(Tutors *ptr, int id);	// Display tutor list by Tutor ID

void sortPayRate(Tutors *ptr, float pr);	// Display tutor list by hourly pay rate 

void sortRating(Tutors *ptr, int r);	// Display tutor list by overall performance

void modifyTutor(Tutors *ptr, string p, string a);	// Modify tutor phone number and home address

void deleteTutor(Tutors *ptr, string n);	// Delete tutor record

int main()
{
	Tutors tutorList[100];	// Declare array of tutor with maximum 100 records
	Tutors *tutorPtr = tutorList;	// Pointer points to the array of tutor
}

void sortID(Tutors *ptr, int id) {

}

void sortPayRate(Tutors *ptr, float pr) {

}

void sortRating(Tutors *ptr, int r) {

}

void modifyTutor(Tutors *ptr, string p, string a) {

}

void deleteTutor(Tutors *ptr, string n) {

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
