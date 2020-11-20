#include "StudentV2.h"

int main()
{
	Student*student = new Student("Nguyen", "Van", "A");
	cout << "Ho ten: " << student->toString() << endl;
	system("pause");
	return 0;
}