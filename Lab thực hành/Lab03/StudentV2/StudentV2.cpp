#include "StudentV2.h"

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

Student::Student(const Student & copy)
{
	this->_firstName = copy._firstName;
	this->_middleName = copy._middleName;
	this->_lastName = copy._lastName;
}

string Student::toString()
{
	stringstream writer;
	writer << _firstName << " " << _middleName << " " << _lastName;
	return writer.str();
}
