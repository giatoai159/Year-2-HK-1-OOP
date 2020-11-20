#pragma once
#include<iostream>
#include<stdlib.h>
#include<sstream>
#include<string.h>
using namespace std;

class Fraction
{
private:
	int _num;
	int _den;
public:
	int getNum() { return _num; }
	int getDen() { return _den; }
	void setNum(int num) { _num = num; }
	void setDen(int den) { _den = den; }
public:
	Fraction();
	Fraction(int num, int den);
	~Fraction();
public:
	string toString() const;
	friend istream& operator>>(istream&in, Fraction* frac);
	friend ostream& operator<<(ostream&out, const Fraction* frac);
};