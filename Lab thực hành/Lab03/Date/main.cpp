#include"Date.h"

int main()
{
	DateV1 date1;
	cout << "Date: " << date1.toString() << endl;
	DateV1 date2(29, 2, 2012);
	cout << "Date: " << date2.toString() << endl;
	system("pause");
	return 0;
}