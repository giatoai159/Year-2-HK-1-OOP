#pragma once
#include<iostream>
#include<stdlib.h>

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
	Fraction();
	Fraction(int num, int den);
	~Fraction();
};