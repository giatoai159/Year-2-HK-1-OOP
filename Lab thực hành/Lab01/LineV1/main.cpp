#include<iostream>
#include<stdlib.h>
#include"LineV1.h"
using namespace std;

int main()
{
	// Khong doi so
	Line line1;
	Point line1_start = line1.getStart();
	Point line1_end = line1.getEnd();
	cout << "Line start: (" << line1_start.X() << ", " << line1_start.Y() << ")" << endl;
	cout << "Line end: (" << line1_end.X() << ", " << line1_end.Y() << ")" << endl;
	// Co doi so
	Point p1(3, 5);
	Point p2(4, 6);
	Line line2(p1,p2);
	Point line2_start = line2.getStart();
	Point line2_end = line2.getEnd();
	cout << "Line start: (" << line2_start.X() << ", " << line2_start.Y() << ")" << endl;
	cout << "Line end: (" << line2_end.X() << ", " << line2_end.Y() << ")" << endl;
	// Pointer
	Point _p1(23, 45);
	Point _p2(34, 56);
	Line* pline = new Line(_p1, _p2);
	Point pline_start = pline->getStart();
	Point pline_end = pline->getEnd();
	cout << "Line start: (" << pline_start.X() << ", " << pline_start.Y() << ")" << endl;
	cout << "Line end: (" << pline_end.X() << ", " << pline_end.Y() << ")" << endl;
	system("pause");
	return 0;
}