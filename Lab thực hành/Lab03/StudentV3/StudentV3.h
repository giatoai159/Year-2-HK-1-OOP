#pragma once
#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>

using namespace std;

class Student
{
private:
	string _firstName;
	string _middleName;
	string _lastName;
public:
	string getFirstName() { return _firstName; }
	string getMiddleName() { return _middleName; }
	string getLastName() { return _lastName; }
	void setFirstName(string firstName) { _firstName = firstName; }
	void setMiddleName(string middleName) { _middleName = middleName; }
	void setLastName(string lastName) { _lastName = lastName; }
public:
	Student();
	Student(string firstName, string middleName, string lastName);
	~Student();
public:
	string toString() const;
	friend istream& operator>>(istream&in, Student*stu);
	friend ostream& operator<<(ostream&out, Student*stu);
};