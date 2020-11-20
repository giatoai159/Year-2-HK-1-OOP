#include"LineV3.h"

int main()
{
	Point* p1=new Point(3, 3);
	Point* p2=new Point(4, 4);
	Line* root=new Line(p1, p2);
	Line* copy= new Line(*root);
	cout << "Start copy: (" << copy->getStart()->X() << ", " << copy->getStart()->Y() << ")" << endl;
	cout << "End copy: (" << copy->getEnd()->X() << ", " << copy->getEnd()->Y() << ")" << endl;
	root->~Line();
	system("pause");
	return 0;
}