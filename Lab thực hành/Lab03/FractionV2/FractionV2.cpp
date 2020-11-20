#include "FractionV2.h"

Fraction::Fraction()
{
	_num = 0;
	_den = 1;
}

Fraction::Fraction(int num, int den)
{
	_num = num;
	if (den != 0) _den = den;
	else cout << "Invalid Data.";
}

Fraction::~Fraction()
{
}

string Fraction::toString() const
{
	stringstream writer;
	writer << _num << "/" << _den;
	return writer.str();
}

istream & operator>>(istream & in, Fraction* frac)
{
	cout << "Nhap tu: ";
	in >> frac->_num;
	cout << "Nhap mau: ";
	in >> frac->_den;
	return in;
	// TODO: insert return statement here
}

ostream & operator<<(ostream & out, const Fraction * frac)
{
	out << frac->toString();
	return out;
	// TODO: insert return statement here
}
