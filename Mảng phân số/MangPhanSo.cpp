#include"MangPhanSo.h"

PHANSO::PHANSO()
{
	tuSo = 0;
	mauSo = 1;
}

PHANSO::PHANSO(int t, int m)
{
	tuSo = t;
	if (m != 0)
		mauSo = m;
	else mauSo = 1;
}

void PHANSO::ganTuSo(int t)
{
	tuSo = t;
}

void PHANSO::ganMauSo(int m)
{
	if (m != 0)
		mauSo = m;
	else mauSo = 0;
}

void PHANSO::nhapPhanSo()
{
	cout << "Nhap tu so: "; cin >> tuSo;
	cout << "Nhap mau so: "; cin >> mauSo;
}

void PHANSO::xuatPhanSo()
{
	cout << tuSo << "/" << mauSo << endl;
}

PHANSO PHANSO::congPhanSo(PHANSO b)
{
	PHANSO s;
	s.ganTuSo(tuSo*b.mauSo + b.tuSo*mauSo);
	s.ganMauSo(mauSo*b.mauSo);
	return s;

}

PHANSO PHANSO::operator+(PHANSO b)
{
	PHANSO kq;
	kq.tuSo = tuSo*b.mauSo + mauSo*b.tuSo;
	kq.mauSo = mauSo*b.mauSo;
	return kq;
}

PHANSO PHANSO::operator/(PHANSO b)
{
	PHANSO kq;
	kq.tuSo = tuSo*b.mauSo;
	kq.mauSo = mauSo*b.tuSo;
	return kq;
}

bool PHANSO::operator>(PHANSO b)
{
	if (tuSo*b.mauSo > mauSo*b.tuSo)
		return true;
	return false;
}

PHANSO PHANSO::operator-(PHANSO b)
{
	PHANSO kq;
	kq.tuSo = tuSo*b.mauSo - mauSo*b.tuSo;
	kq.mauSo = mauSo*b.mauSo;
	return kq;
}

PHANSO PHANSO::operator*(PHANSO b)
{
	PHANSO kq;
	kq.tuSo = tuSo*b.tuSo;
	kq.mauSo = mauSo*b.mauSo;
	return kq;
}

void MANGPS::nhapMangPS()
{
	cout << "Nhap so phan tu cua mang: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan so thu " << i + 1 << ": " << endl;
		mang[i].nhapPhanSo();
		cout << endl;
	}
}
void MANGPS::xuatMangPS()
{
	for (int i = 0; i < n; i++)
	{
		mang[i].xuatPhanSo();
		cout << endl;
	}
}

PHANSO MANGPS::tongMangPS()
{
	PHANSO s;
	s.ganTuSo(0);
	s.ganMauSo(1);
	for (int i = 0; i < n; i++)
	{
		s = s.congPhanSo(mang[i]);
	}
	return s;
}