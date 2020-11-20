#include<iostream>
#include<stdlib.h>
#include"CircleV1.h"
using namespace std;

int main()
{
	cout << "Tao hinh tron khong doi so:" << endl;
	Circle circle1;
	Point circle1_center = circle1.getCenter();
	cout << "Circle Center: (" << circle1_center.X() << ", " << circle1_center.Y() << ")" << endl;
	cout << "Circle Radius: " << circle1.getRadius() << endl;
	cout << "Tao hinh tron co doi so:" << endl;
	Point circle2_center(4, 2);
	Circle circle2(circle2_center,5);
	Point circle2_center_out = circle2.getCenter();
	cout << "Circle Center: (" << circle2_center_out.X() << ", " << circle2_center_out.Y() << ")" << endl;
	cout << "Circle Radius: " << circle2.getRadius() << endl;
	cout << "Set doi so hinh tron: " << endl;
	Point circle2_center_set(5, 3);
	circle2.setCenter(circle2_center_set);
	circle2.setRadius(6);
	circle2_center_out = circle2.getCenter();
	cout << "Circle Center: (" << circle2_center_out.X() << ", " << circle2_center_out.Y() << ")" << endl;
	cout << "Circle Radius: " << circle2.getRadius() << endl;
	system("pause");
	return 0;
}