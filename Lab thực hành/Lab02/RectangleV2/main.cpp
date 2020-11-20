#include"RectangleV2.h"

int main()
{
	Rectangle* rec=new Rectangle;
	cout << "Chu vi HCN: " << rec->Perimeter() << endl;
	cout << "Dien tich HCN: " << rec->Area() << endl;
	rec->~Rectangle();
	system("pause");
	return 0;
}