#include<iostream>
#include<stdlib.h>
#include"TriangleV1.h"
using namespace std;

int main()
{
	Triangle tri1;
	Point tri1_a = tri1.A();
	Point tri1_b = tri1.B();
	Point tri1_c = tri1.C();
	cout << "Khoi tao tam giac khong doi so:" << endl;
	cout << "A: (" << tri1_a.X() << ", " << tri1_a.Y() << ")" << endl;
	cout << "B: (" << tri1_b.X() << ", " << tri1_b.Y() << ")" << endl;
	cout << "C: (" << tri1_c.X() << ", " << tri1_c.Y() << ")" << endl;
	cout << "Set doi so tam giac:" << endl;
	tri1_a.setX(3);
	tri1_a.setY(5);
	tri1.setA(tri1_a);
	tri1_b.setX(4);
	tri1_b.setY(2);
	tri1.setB(tri1_b);
	tri1_c.setX(2);
	tri1_c.setY(7);
	tri1.setC(tri1_c);
	cout << "A: (" << tri1_a.X() << ", " << tri1_a.Y() << ")" << endl;
	cout << "B: (" << tri1_b.X() << ", " << tri1_b.Y() << ")" << endl;
	cout << "C: (" << tri1_c.X() << ", " << tri1_c.Y() << ")" << endl;
	cout << "Khoi tao tam giac co doi so:" << endl;
	Point tri2_a(3,3);
	Point tri2_b(4,4);
	Point tri2_c(5,5);
	Triangle tri2(tri2_a, tri2_b, tri2_c);
	Point tri2_a_out = tri2.A();
	Point tri2_b_out = tri2.B();
	Point tri2_c_out = tri2.C();
	cout << "A: (" << tri2_a_out.X() << ", " << tri2_a_out.Y() << ")" << endl;
	cout << "B: (" << tri2_b_out.X() << ", " << tri2_b_out.Y() << ")" << endl;
	cout << "C: (" << tri2_c_out.X() << ", " << tri2_c_out.Y() << ")" << endl;
	system("pause");
	return 0;
}