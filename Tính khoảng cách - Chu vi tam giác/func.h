#include<iostream>
#include<math.h>
using namespace std;
class Diem
{
public:
	double X, Y;
	void nhap();
	double tinhKhoangCach(Diem b);
};
class Tamgiac
{
public:
	Diem A, B, C;
	void nhap();
	double tinhChuvi();
};