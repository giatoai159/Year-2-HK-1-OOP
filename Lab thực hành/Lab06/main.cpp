#include"Pet.h"

int main()
{
	Home h;
	h.NhapDS();
	h.XuatDS();
	cout << "Tong tien an: " << h.totalFoodCost() << endl;
	h.~Home();
	system("pause");
	return 0;
}