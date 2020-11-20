#include "StudentV3.h"

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

string Student::toString() const
{
	stringstream writer;
	writer << _firstName << " " << _middleName << " " << _lastName;
	return writer.str();
}

istream & operator>>(istream & in, Student * stu)
{
	cout << "Nhap first name: ";
	in >> stu->_firstName;
	cout << "Nhap middle name: ";
	in >> stu->_middleName;
	cout << "Nhap last name: ";
	in >> stu->_lastName;
	return in;
	// TODO: insert return statement here
}

ostream & operator<<(ostream & out, Student * stu)
{
	out << stu->toString();
	return out;
	// TODO: insert return statement here
}
