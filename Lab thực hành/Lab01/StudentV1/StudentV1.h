#pragma once
#include<iostream>
#include<stdlib.h>
#include<string>

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
	Student();
	Student(string firstName, string middleName, string lastName);
	~Student();
};