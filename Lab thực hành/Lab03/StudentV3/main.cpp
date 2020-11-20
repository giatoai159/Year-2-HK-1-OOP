#include"StudentV3.h"

int main()
{
	Student student1;
	cout << "Tao sinh vien rong khong co ten:" << endl;
	cout << "Ho ten: " << student1.getFirstName() << " " << student1.getMiddleName() << " " << student1.getLastName() << endl;
	Student student2("Nguyen", "Van", "A");
	cout << "Tao sinh vien co ten:" << endl;
	cout << "Ho ten: " << student2.getFirstName() << " " << student2.getMiddleName() << " " << student2.getLastName() << endl;
	cout << "Sua ten sinh vien: " << endl;
	student2.setLastName("B");
	cout << "Ho ten: " << student2.getFirstName() << " " << student2.getMiddleName() << " " << student2.getLastName() << endl;
	Student student3;
	cin >> &student3;
	cout << &student3 << endl;
	system("pause");
	return 0;
}