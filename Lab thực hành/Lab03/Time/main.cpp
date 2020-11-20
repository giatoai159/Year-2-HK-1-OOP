#include"TimeV1.h"

int main()
{
	TimeV1 time;
	cout << "Time: " << time.toString() << endl;
	TimeV1 time2(23,25,46);
	cout << "Time : " << time2.toString() << endl;
	system("pause");
	return 0;
}