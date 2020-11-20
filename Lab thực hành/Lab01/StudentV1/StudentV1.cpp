#include "StudentV1.h"

Student::Student()
{
	_firstName = "";
	_middleName = "";
	_lastName = "";
}

Student::Student(string firstName, string middleName, string lastName)
{
	_firstName = firstName;
	_middleName = middleName;
	_lastName = lastName;
}

Student::~Student()
{
}
