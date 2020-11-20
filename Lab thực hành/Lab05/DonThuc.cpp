#include "DonThuc.h"



DonThuc::DonThuc()
{
	_a = 1;
	_b = 1;
}

DonThuc::DonThuc(int a, int b)
{
	_a = a;
	_b = b;
}

DonThuc::DonThuc(const DonThuc & dt)
{
	_a = dt._a;
	_b = dt._b;
}

DonThuc::~DonThuc()
{
	return;
}

void DonThuc::Nhap()
{
	do
	{
		cout << "Nhap a: "; cin >> _a;
		if (_a == 0)
			cout << "a khong the bang 0, vui long nhap lai.";
	} while (_a == 0);
	do
	{
		cout << "Nhap b: "; cin >> _b;
		if (_b == 0)
			cout << "b khong the bang 0, vui long nhap lai.";
	} while (_b == 0);
}

void DonThuc::Xuat()
{
	if (_a != 1)
	{
		if (_b != 1)
			cout << _a << "x^" << _b;
		else cout << _a << "x";
	}
	else
	{
		if (_b != 1)
			cout << "x^" << _b;
		else cout << "x";
	}
}

int DonThuc::TinhGiaTri(int x)
{
	return (_a*pow(x, _b));
}

DonThuc & DonThuc::operator=(const DonThuc & dt)
{
	this->_a = dt._a;
	this->_b = dt._b;
	return *this;
}

DonThuc DonThuc::operator*(const DonThuc & dt)
{
	DonThuc kqdt;
	kqdt._a = this->_a*dt._a;
	kqdt._b = this->_b + dt._b;
	return kqdt;
}

DonThuc DonThuc::operator/(const DonThuc & dt)
{
	DonThuc kqdt;
	kqdt._a = this->_a / dt._a;
	kqdt._b = this->_a - dt._a;
	return kqdt;
}

DonThuc & DonThuc::operator*=(const DonThuc & dt)
{
	this->_a = this->_a * dt._a;
	this->_b = this->_b + dt._b;
	return *this;
}

DonThuc & DonThuc::operator/=(const DonThuc & dt)
{
	this->_a = this->_a / dt._a;
	this->_b = this->_b - dt._b;
	return *this;
}

bool DonThuc::operator==(const DonThuc & dt)
{
	if (this->_a == dt._a&&this->_b == dt._b) return true;
	else return false;
}

bool DonThuc::operator!=(const DonThuc & dt)
{
	if (*this==dt) return false;
	else return true;	
}

ostream & operator<<(ostream & os, const DonThuc & dt)
{
	if (dt._a != 1)
	{
		if (dt._b != 1)
			cout << dt._a << "x^" << dt._b;
		else cout << dt._a << "x";
	}
	else
	{
		if (dt._b != 1)
			cout << "x^" << dt._b;
		else cout << "x";
	}
	return os;
	// TODO: insert return statement here
}

istream & operator>>(istream & is, DonThuc & dt)
{
	do
	{
		cout << "Nhap a: "; is >> dt._a;
		if (dt._a == 0)
			cout << "a khong the bang 0, vui long nhap lai.";
	} while (dt._a == 0);
	do
	{
		cout << "Nhap b: "; is >> dt._b;
		if (dt._b == 0)
			cout << "b khong the bang 0, vui long nhap lai.";
	} while (dt._b == 0);
	return is;
	// TODO: insert return statement here
}
