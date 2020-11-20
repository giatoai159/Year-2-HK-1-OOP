#include"RectangleV3.h"

int main()
{
	Point* p1 = new Point(3, 3);
	Point* p2 = new Point(4, 4);
	Rectangle* root = new Rectangle(p1, p2);
	Rectangle* copy = new Rectangle(*root);
	cout << "Top left copy: (" << copy->topLeft()->X() << ", " << copy->topLeft()->Y() << ")" << endl;
	cout << "Bottom right copy: (" << copy->bottomRight()->X() << ", " << copy->bottomRight()->Y() << ")" << endl;
	root->~Rectangle();
	system("pause");
	return 0;
}