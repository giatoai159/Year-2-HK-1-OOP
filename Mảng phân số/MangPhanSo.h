#pragma once
#include<iostream>
#include<stdio.h>

using namespace std;

class PHANSO
{
private:
	int tuSo;
	int mauSo;
public:
	PHANSO();
	PHANSO(int t, int m);
	void ganTuSo(int t);
	void ganMauSo(int m);
	void nhapPhanSo();
	void xuatPhanSo();
	PHANSO congPhanSo(PHANSO b);
	PHANSO operator+(PHANSO b);
	PHANSO operator-(PHANSO b);
	PHANSO operator*(PHANSO b);
	PHANSO operator/(PHANSO b);
	bool operator>(PHANSO b);
};

class MANGPS
{
private:
	PHANSO mang[100];
	int n;
public:
	void nhapMangPS();
	void xuatMangPS();
	PHANSO tongMangPS();
};