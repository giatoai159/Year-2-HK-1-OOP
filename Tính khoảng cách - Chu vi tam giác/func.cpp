#include "func.h"

void Diem::nhap()
{
	cout << "Nhap X: "; cin >> X ;
	cout << "Nhap Y: "; cin >> Y ;
}
void Tamgiac::nhap()
{
	cout << "Nhap diem A: " << endl; A.nhap();
	cout << "Nhap diem B: " << endl; B.nhap();
	cout << "Nhap diem C: " << endl; C.nhap();
}
double Diem::tinhKhoangCach(Diem b)
{
	double kq;
	kq = sqrt(pow(X - b.X,2) + pow(Y - b.Y,2));
	return kq;
}
double Tamgiac::tinhChuvi()
{
	double kq;
	kq = A.tinhKhoangCach(B) + B.tinhKhoangCach(C) + C.tinhKhoangCach(A);
	return kq;
}

