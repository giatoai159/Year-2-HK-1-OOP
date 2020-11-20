#include"RectangleV3.h"

int Rectangle::InstanceCount = 0;

int main()
{
	Point* p1 = new Point(3, 3);
	Point* p2 = new Point(4, 4);
	Rectangle* root = new Rectangle(p1, p2);
	Rectangle* copy = new Rectangle(*root);
	cout << "So hinh chu nhat da duoc tao ra: " << Rectangle::InstanceCount << endl;
	system("pause");
	return 0;
}