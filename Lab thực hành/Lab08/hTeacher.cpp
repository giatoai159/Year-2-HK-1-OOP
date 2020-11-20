#include"Classes.h"

double headTeacher::calcSalary()
{
	return (Teacher::calcSalary() + 500000);
}

void headTeacher::Add()
{
	int id, offDays;
	string name, nameClass;
	double salaryFactor, basicSalary;
	cout << "~~INPUT HEAD TEACHER~~" << endl;
	cout << "ID: "; cin >> id; this->setID(id);
	cout << "Name: "; getline(cin >> ws, name); this->setName(name);
	cout << "Salary Factor: "; cin >> salaryFactor; this->setSalaryFactor(salaryFactor);
	cout << "Basic Salary: "; cin >> basicSalary; this->setBasicSalary(basicSalary);
	cout << "Off days: "; cin >> offDays; this->setOffDays(offDays);
	cout << "Class monitoring: "; getline(cin >> ws, nameClass); this->nameClass = nameClass;
}

void headTeacher::Display()
{
	cout << "Head Teacher: " << endl;
	cout << "ID: " << this->getID() << endl;
	cout << "Name: " << this->getName() << endl;
	cout << "Salary Factor: " << this->getSalaryFactor() << endl;
	cout << "Basic Salary: " << this->getBasicSalary() << endl;
	cout << "Off days: " << this->getOffDays() << endl;
	cout << "Class monitoring: " << this->nameClass << endl;
	cout << "Salary: " << this->calcSalary() << endl;
}

headTeacher::headTeacher()
{
	nameClass = "";
}

headTeacher::headTeacher(int ID, string name, double salaryFactor, double basicSalary, int offDays, string nameClass)
{
	this->setID(ID);
	this->setName(name);
	this->setSalaryFactor(salaryFactor);
	this->setBasicSalary(basicSalary);
	this->setOffDays(offDays);
	this->nameClass = nameClass;
}

headTeacher::~headTeacher()
{
	cout << "Deleted head teacher." << endl;
}