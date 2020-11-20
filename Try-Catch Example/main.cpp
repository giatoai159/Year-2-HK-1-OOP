#include<iostream>

using namespace std;

double Chia(double a, double b)
{
	if (b == 0)
		throw "Chia cho 0";
	double kq = a / b;
	return kq;
}

void main()
{
	double a, b, kq;
	a = 5;
	b = 0;
	try
	{
		kq = Chia(a, b);
		cout << kq;
	}
	catch (const char *s)
	{
		cout << s;
	}
	catch (...)
	{
		cout << "Co loi gi do.";
	}
}