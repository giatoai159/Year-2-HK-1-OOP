#include"MangPhanSo.h"

using namespace std;
// Tao mang phan so va tinh tong mang


void main()
{
	/*
	MANGPS a;
	a.nhapMangPS();
	a.xuatMangPS();
	PHANSO s = a.tongMangPS();
	s.xuatPhanSo();
	cout << endl;
	return;
	*/
	PHANSO a(4, 5);
	PHANSO b(2, 3);
	PHANSO kq = a - b;
	kq.xuatPhanSo();
	kq = a + b;
	kq.xuatPhanSo();
	kq = a*b;
	kq.xuatPhanSo();
	kq = a / b;
	kq.xuatPhanSo();
	if (a > b)
		cout << "a>b" << endl;
}