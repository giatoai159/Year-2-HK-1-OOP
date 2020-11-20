#pragma once
#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>

using namespace std;

class Teacher
{
private:
	int ID;
	string name;
	double salaryFactor;
	double basicSalary;
	int offDays;
public:
	// Get-Set
	int getID()
	{
		return ID;
	}
	string getName()
	{
		return name;
	}
	double getSalaryFactor()
	{
		return salaryFactor;
	}
	double getBasicSalary()
	{
		return basicSalary;
	}
	int getOffDays()
	{
		return offDays;
	}
	void setID(int value)
	{
		this->ID = value;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setSalaryFactor(double value)
	{
		this->salaryFactor = value;
	}
	void setBasicSalary(double value)
	{
		this->basicSalary = value;
	}
	void setOffDays(int value)
	{
		this->offDays = value;
	}
	//
	Teacher();
	Teacher(int ID, string name, double salaryFactor, double basicSalary, int offDays);
	virtual ~Teacher();
	virtual double calcSalary();
	virtual void Add();
	virtual void Display();

};

class headTeacher : public Teacher
{
private:
	string nameClass;
public:
	//
	string getClassName()
	{
		return nameClass;
	}
	void setClassName(string nameClass)
	{
		this->nameClass = nameClass;
	}
	//
	headTeacher();
	headTeacher(int ID, string name, double salaryFactor, double basicSalary, int offDays, string nameClass);
	~headTeacher();
	double calcSalary();
	void Add();
	void Display();
};

class School
{
private:
	vector<Teacher*>list_Teacher;
public:
	static int TeacherCount;
	static int hTeacherCount;
	//
	double AvgSalary();
	void AddTeacher();
	void PrintList();
	double calcSalary();
	void highestSalaryTeacher();
	void PrintHighSalaryTeacher();
	void FindTeacherWithID();
	void FindTeacherWithName();
	int CountTeachersWith4OffDays();
	//
	~School();
};