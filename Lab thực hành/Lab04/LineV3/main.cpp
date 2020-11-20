#include"LineV3.h"

int Line::InstanceCount = 0;

int main()
{
	Point* p1=new Point(4, 2);
	Point* p2=new Point(3, 8);
	Line* root=new Line(p1, p2);
	Line* copy= new Line(*root);
	cout << "Do dai duong thang start (4,2) end (3,8) la: " << root->getLength() << endl;
	cout << "So duong thang da duoc tao ra: " << Line::InstanceCount << endl;
	system("pause");
	return 0;
}