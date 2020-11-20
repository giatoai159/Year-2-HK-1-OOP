#include"Classes.h"

double School::AvgSalary()
{
	return (calcSalary() / (TeacherCount + hTeacherCount));
}

void School::AddTeacher()
{
	int n;
	int teacherType;
	cout << "Input the amount of teachers you want to add: "; cin >> n;
	for (int i = 0; i<n; i++)
	{
		cout << "Input the type of teacher you want to add: " << endl << "1 for normal Teacher, 2 for head Teacher." << endl << "-> "; cin >> teacherType;
		if (teacherType == 1)
		{
			Teacher *temp = new Teacher;
			TeacherCount++;
			temp->Add();
			list_Teacher.push_back(temp);
		}
		if (teacherType == 2)
		{
			Teacher *temp = new headTeacher;
			hTeacherCount++;
			temp->Add();
			list_Teacher.push_back(temp);
		}
	}
}

void School::PrintList()
{
	for (unsigned int i = 0; i < list_Teacher.size(); i++)
	{
		list_Teacher[i]->Display();
		cout << endl;
	}
}

double School::calcSalary()
{
	double total = 0;
	for (unsigned int i = 0; i < list_Teacher.size(); i++)
	{
		total += list_Teacher[i]->calcSalary();
	}
	return total;
}

void School::highestSalaryTeacher()
{
	int max = 0;
	if (list_Teacher.size() == 1)
	{
		cout << "The teacher with the highest salary is: " << list_Teacher[max]->getName() << " with " << list_Teacher[max]->calcSalary() << endl;
	}
	else
	{
		for (unsigned int i = 1; i < list_Teacher.size(); i++)
		{
			if (list_Teacher[i]->calcSalary() > list_Teacher[max]->calcSalary())
				max = i;
		}
		cout << "The teacher with the highest salary is: " << list_Teacher[max]->getName() << " with " << list_Teacher[max]->calcSalary() << endl;
	}
}

void School::PrintHighSalaryTeacher()
{
	cout << "Teacher(s) with salary over 10.000.000 VND is(are): " << endl;
	for (unsigned int i = 0; i < list_Teacher.size(); i++)
	{
		if (list_Teacher[i]->calcSalary() > 10000000)
			cout << list_Teacher[i]->getName() << endl;
	}
}

void School::FindTeacherWithID()
{
	int ID;
	cout << "Input the ID of the teacher you want to find: "; cin >> ID;
	for (unsigned int i = 0; i < list_Teacher.size(); i++)
	{
		if (list_Teacher[i]->getID() == ID)
		{
			cout << "Teacher with the ID: " << ID << " is " << list_Teacher[i]->getName();
			break;
		}
	}
}

void School::FindTeacherWithName()
{
	string name;
	cout << "Input the name of the teacher you want to find: "; cin >> name;
	for (unsigned int i = 0; i < list_Teacher.size(); i++)
	{
		if (list_Teacher[i]->getName() == name)
		{
			cout << "Teacher with the Name: " << name << " has the ID: " << list_Teacher[i]->getID();
			break;
		}
	}
}

int School::CountTeachersWith4OffDays()
{
	int count = 0;
	for (unsigned int i = 0; i < list_Teacher.size(); i++)
	{
		if (list_Teacher[i]->getOffDays() >= 4)
			count++;
	}
	return count;
}

School::~School()
{
	for (unsigned int i = 0; i < list_Teacher.size(); i++)
		delete list_Teacher[i];
	list_Teacher.clear();
}