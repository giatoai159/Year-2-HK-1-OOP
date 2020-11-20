#include"DonThuc.h"

int main()
{
	// Tao don thuc khong co doi so
	DonThuc a;
	cout << "Don thuc duoc tao khong doi so: ";
	a.Xuat();
	cout << endl;
	// Tao don thuc co doi so
	DonThuc b(4,5);
	cout << "Don thuc duoc tao co doi so: ";
	b.Xuat();
	cout << endl;
	// Kiem tra phuong thuc nhap xuat
	cout << "Kiem tra phuong thuc nhap xuat: " << endl;
	a.Nhap();
	a.Xuat();
	cout << endl;
	// Kiem tra toan tu nhap xuat
	cout << "Kiem tra toan tu nhap xuat: " << endl;
	DonThuc c;
	cin >> c;
	cout << c << endl;
	int x;
	// Kiem tra ham tinh gia tri voi x cho truoc
	cout << "Kiem tra ham tinh gia tri voi x cho truoc: " << endl;
	DonThuc d;
	cin >> d;
	cout << "Nhap x: "; cin >> x;
	cout << "Ket qua " << d.getA() << "*" << x <<"^" << d.getB() << " la: " << d.TinhGiaTri(x) << endl;
	// Kiem tra cac toan tu *,/,*=,/= va toan tu =
	cout << "Kiem tra cac toan tu *,/,*=,/= va toan tu =: " << endl;
	DonThuc e, f, g;
	cout << "Nhap don thuc thu 1: " << endl;
	cin >> e;
	cout << "Nhap don thuc thu 2: " << endl;
	cin >> f;
	g = e * f; // Toan tu =
	cout << "Ket qua don thuc 1 * don thuc 2: " << g << endl;
	g = e / f; // Toan tu =
	cout << "Ket qua don thuc 1 / don thuc 2: " << g << endl;
	e *= f;
	cout << "Ket qua don thuc 1 *= don thuc 2: " << e << endl;
	cout << "Chu y don thuc 1 luc nay la: " << e << endl;
	e /= f;
	cout << "Ket qua don thuc 1 /= don thuc 2: " << e << endl;
	// Kiem tra toan tu so sanh ==, !=
	cout << "Kiem tra cac toan tu so sanh ==, !=: " << endl;
	cout << "Nhap don thuc thu 1: " << endl;
	cin >> e;
	cout << "Nhap don thuc thu 2: " << endl;
	cin >> f;
	if (e == f) cout << "Don thuc 1 bang don thuc 2" << endl;
	if (e != f) cout << "Don thuc 1 khong bang don thuc 2";
	cout << endl;
	system("pause");
	return 0;
}