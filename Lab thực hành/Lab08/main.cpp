#include"Classes.h"
int School::TeacherCount = 0;
int School::hTeacherCount = 0;
int main()
{
	School d;
	d.AddTeacher();
	cout << "~~~~OUTPUT~~~~" << endl;
	d.PrintList();
	cout << "Total Salary: " << d.calcSalary() << endl;
	cout << "Average Salary: " << d.AvgSalary() << endl;
	d.PrintHighSalaryTeacher();
	d.highestSalaryTeacher();
	cout << "Number of normal Teacher: " << d.TeacherCount << endl;
	cout << "Number of head Teacher: " << d.hTeacherCount << endl;
	d.FindTeacherWithID();  cout << endl;
	d.FindTeacherWithName(); cout << endl;
	cout << "Number of teachers who have more than 4 off days: " << d.CountTeachersWith4OffDays();
	d.~School();
	system("pause");
	return 1;
}