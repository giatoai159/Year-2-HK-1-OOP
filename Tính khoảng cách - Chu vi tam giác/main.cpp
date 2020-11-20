#include "func.h"

void main()
{
	Diem a, b;
	a.nhap();
	b.nhap();
	double kc;
	kc = a.tinhKhoangCach(b);
	cout << kc << endl;
	Tamgiac t;
	t.nhap();
	cout << t.tinhChuvi();
}