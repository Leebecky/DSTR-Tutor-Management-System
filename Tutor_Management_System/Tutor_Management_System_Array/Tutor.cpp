#include "Tutor.h"
#include <string>
#include <iostream>

Tutor tutorArray[3];

Tutor::Tutor() {}

Tutor::Tutor(int tutorId)
{
	this->tutorId = tutorId;
}


void test(std::string test) {

	tutorArray[0] = Tutor(1);
	//tutorArray[1] = Tutor(2);
	//tutorArray[2] = Tutor(3);


	std::cout << test << " | " << tutorArray[0].tutorId;
}
