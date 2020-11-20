#pragma once
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

class DonThuc
{
private:
	int _a;
	int _b;
public: 
	// Khoi tao & Xoa
	DonThuc(void);
	DonThuc(int a, int b);
	DonThuc(const DonThuc &dt);
	~DonThuc(void);
	// Getter // Setter
	int getA() { return _a; }
	int getB() { return _b; }
	void setA(int a) { _a = a; }
	void setB(int b) { _b = b; }
	// Nhap xuat
	void Nhap();
	void Xuat();
	// Toan tu nhap xuat
	friend ostream& operator<<(ostream &os, const DonThuc &dt);
	friend istream& operator>>(istream &is, DonThuc &dt);
	// Tinh gia tri voi x cho truoc
	int TinhGiaTri(int x);
	// Toan tu gan
	DonThuc& operator=(const DonThuc&dt);
	// Cac toan tu *,/,*=,/=
	DonThuc operator*(const DonThuc&dt);
	DonThuc operator/(const DonThuc&dt);
	DonThuc& operator*=(const DonThuc&dt);
	DonThuc& operator/=(const DonThuc&dt);
	// Toan tu so sanh
	bool operator==(const DonThuc&dt);
	bool operator!=(const DonThuc&dt);
};



