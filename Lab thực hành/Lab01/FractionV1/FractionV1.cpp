#include "FractionV1.h"

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
