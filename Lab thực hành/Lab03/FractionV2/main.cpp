#include"FractionV2.h"

int main()
{
	Fraction frac1;
	cout << "Tao phan so khong doi so: " << endl;
	cout << frac1.getNum() << "/" << frac1.getDen() << endl;
	cout << "Tao phan so co doi so: " << endl;
	Fraction frac2(2, 3);
	cout << frac2.getNum() << "/" << frac2.getDen() << endl;
	cout << "Set doi so cua phan so: " << endl;
	frac2.setNum(4);
	frac2.setDen(6);
	cout << frac2.getNum() << "/" << frac2.getDen() << endl;
	Fraction frac3;
	cin >> &frac3;
	cout << &frac3 << endl;
	system("pause");
	return 0;
}