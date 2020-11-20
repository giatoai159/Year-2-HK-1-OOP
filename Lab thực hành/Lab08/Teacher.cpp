#include "Classes.h"

Teacher::Teacher()
{
	this->ID = NULL;
	this->name = "";
	this->salaryFactor = NULL;
	this->basicSalary = NULL;
	this->offDays = NULL;
}

Teacher::Teacher(int ID, string name, double salaryFactor, double basicSalary, int offDays)
{
	this->ID = ID;
	this->name = name;
	this->salaryFactor = salaryFactor;
	this->basicSalary = basicSalary;
	this->offDays = offDays;
}

Teacher::~Teacher()
{
	cout << "Deleted teacher." << endl;
}

double Teacher::calcSalary()
{
	return ((salaryFactor*basicSalary)-(offDays*100000));
}

void Teacher::Add()
{
	int id, offDays;
	string name;
	double salaryFactor, basicSalary;
	cout << "~~INPUT TEACHER~~" << endl;
	cout << "ID: "; cin >> id; this->ID = id;
	cout << "Name: "; getline(cin >> ws, name); this->name = name;
	cout << "Salary Factor: "; cin >> salaryFactor; this->salaryFactor = salaryFactor;
	cout << "Basic Salary: "; cin >> basicSalary; this->basicSalary = basicSalary;
	cout << "Off days: "; cin >> offDays; this->offDays = offDays;
}

void Teacher::Display()
{
	cout << "Teacher: " << endl;
	cout << "ID: " << this->ID << endl;
	cout << "Name: " << this->name << endl;
	cout << "Salary Factor: " << this->salaryFactor << endl;
	cout << "Basic Salary: " << this->basicSalary << endl;
	cout << "Off days: " << this->offDays << endl;
	cout << "Salary: " << this->calcSalary() << endl;
}