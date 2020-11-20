#pragma once
#include<math.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
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
	Student(const Student& copy);
public:
	string toString();
};