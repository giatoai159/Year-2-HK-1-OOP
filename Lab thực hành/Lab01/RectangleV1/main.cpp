#include<iostream>
#include<stdlib.h>
#include"RectangleV1.h"
using namespace std;

int main()
{
	Rectangle rec1;
	Point rec1_topLeft = rec1.topLeft();
	Point rec1_bottomRight = rec1.bottomRight();
	cout << "Top Left: (" << rec1_topLeft.X() << ", " << rec1_topLeft.Y() << ")" << endl;
	cout << "Bottom Right: (" << rec1_bottomRight.X() << ", " << rec1_bottomRight.Y() << ")" << endl;
	//
	Point rec2_p1(3, 9);
	Point rec2_p2(4, 7);
	Rectangle rec2(rec2_p1, rec2_p2);
	Point rec2_topLeft = rec2.topLeft();
	Point rec2_bottomRight = rec2.bottomRight();
	cout << "Top Left: (" << rec2_topLeft.X() << ", " << rec2_topLeft.Y() << ")" << endl;
	cout << "Bottom Right: (" << rec2_bottomRight.X() << ", " << rec2_bottomRight.Y() << ")" << endl;
	system("pause");
	return 0;
}