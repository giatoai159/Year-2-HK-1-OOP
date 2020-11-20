#include"random.h"

int main()
{
	Random a;
	cout << "Test Next() = " << a.Next() << endl;
	cout << "Test Next(int max=10) = " << a.Next(10) << endl;
	system("pause");
	return 0;
}