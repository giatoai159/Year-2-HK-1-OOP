#include"Student.h"

int main()
{
	School s;
	s.Nhap();
	s.Xuat();
	cout << "Tong tien hoc phi: " << s.TienHocPhi() << endl;
	s.~School();
	s.Xuat();
	system("pause");
	return 0;
}