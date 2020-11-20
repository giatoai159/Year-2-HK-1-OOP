#include "Student.h"

Student::Student()
{
	name = "";
	age = NULL;
	mssv = NULL;
	SoMonDK = NULL;
	SoMonDKThiLai = NULL;
	SoMonDKHocLai = NULL;
}

Student::Student(string name, int age, int mssv, int SoMonDK, int SoMonDKThiLai, int SoMonDKHocLai)
{
	this->name = name;
	this->age = age;
	this->mssv = mssv;
	this->SoMonDK = SoMonDK;
	this->SoMonDKThiLai = SoMonDKThiLai;
	this->SoMonDKHocLai = SoMonDKHocLai;
}

Student::~Student()
{
	cout << "Xoa student thanh cong." << endl;
}

void Student::Nhap()
{
	string name;
	int age, mssv, SoMonDK, SoMonDKThiLai, SoMonDKHocLai;
	cout << "Nhap ten: "; getline(cin >> ws, name);
	this->name = name;
	cout << "Nhap tuoi: "; cin >> age; this->age = age;
	cout << "Nhap MSSV: "; cin >> mssv; this->mssv = mssv;
	cout << "Nhap so mon DK: "; cin >> SoMonDK; this->SoMonDK = SoMonDK;
	cout << "Nhap so mon DK thi lai: "; cin >> SoMonDKThiLai; this->SoMonDKThiLai = SoMonDKThiLai;
	cout << "Nhap so mon DK hoc lai: "; cin >> SoMonDKHocLai; this->SoMonDKHocLai = SoMonDKHocLai;
}

void Student::Xuat()
{
	cout << "Ten: " << name << endl;
	cout << "Tuoi: " << age << endl;
	cout << "MSSV: " << mssv << endl;
	cout << "So mon DK: " << SoMonDK << endl;
	cout << "So mon DK thi lai: " << SoMonDKThiLai << endl;
	cout << "So mon DK hoc lai: " << SoMonDKHocLai;
}

int Student::TienHocPhi()
{
	return 0;
}

int Student::CheckValid()
{
	return 0;
}

CNTN::CNTN()
{
	setName("");
	setAge(NULL);
	setMSSV(NULL);
	setMonDK(NULL);
	setMonDKThiLai(NULL);
	setMonDKHocLai(NULL);
}

CNTN::CNTN(string name, int age, int mssv, int SoMonDK, int SoMonDKThiLai, int SoMonDKHocLai)
{
	setName(name);
	setAge(age);
	setMSSV(mssv);
	setMonDK(SoMonDK);
	setMonDKThiLai(SoMonDKThiLai);
	setMonDKHocLai(SoMonDKHocLai);
}

CNTN::~CNTN()
{
	cout << "Xoa thanh cong SV CNTN." << endl;
}

int CNTN::TienHocPhi()
{
	if (getMonDK() + getMonDKHocLai() < 5)
		return -1;
	else return (500000 + (getMonDK() * 200000) + (getMonDKThiLai() * 50000) + (getMonDKHocLai() * 100000));
}

void CNTN::Xuat()
{
	cout << "SV CNTN: " << endl;
	Student::Xuat();
	cout << endl;
	cout << "Tien hoc phi CNTN: " << TienHocPhi();
}

int CNTN::CheckValid()
{
	if (getMonDK() + getMonDKHocLai() < 5)
		return 0;
	else return 1;
}

CTTT::CTTT()
{
	setName("");
	setAge(NULL);
	setMSSV(NULL);
	setMonDK(NULL);
	setMonDKThiLai(NULL);
	setMonDKHocLai(NULL);
}

CTTT::CTTT(string name, int age, int mssv, int SoMonDK, int SoMonDKThiLai, int SoMonDKHocLai)
{
	setName(name);
	setAge(age);
	setMSSV(mssv);
	setMonDK(SoMonDK);
	setMonDKThiLai(SoMonDKThiLai);
	setMonDKHocLai(SoMonDKHocLai);
}

CTTT::~CTTT()
{
	cout << "Xoa thanh cong SV CTTT." << endl;
}

int CTTT::TienHocPhi()
{
	if (getMonDK() + getMonDKHocLai() < 3)
		return -1;
	else return (10000000 + (getMonDK() * 1000000) + (getMonDKThiLai() * 100000) + (getMonDKHocLai() * 500000));
}

void CTTT::Xuat()
{
	cout << "SV CTTT: " << endl;
	Student::Xuat();
	cout << endl;
	cout << "Tien hoc phi CTTT: " << TienHocPhi();
}

int CTTT::CheckValid()
{
	if (getMonDK() + getMonDKHocLai() < 3)
		return 0;
	else return 1;
}

void School::Nhap()
{
	int n;
	int loaiSV;
	cout << "Nhap so sinh vien: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap 1 de nhap sv CNTN, 2 de nhap sv CTTT: "; cin >> loaiSV;
		if (loaiSV == 1)
		{
			Student *temp = new CNTN;
			temp->Nhap();
			ds_SinhVien.push_back(temp);
		}
		if (loaiSV == 2)
		{
			Student *temp = new CTTT;
			temp->Nhap();
			ds_SinhVien.push_back(temp);
		}
	}
}

void School::Xuat()
{
	for(int i=0;i<ds_SinhVien.size();i++)
	{
		ds_SinhVien[i]->Xuat();
		cout << endl;
	}
}

int School::TienHocPhi()
{
	int tongHP=0;
	for(int i=0;i<ds_SinhVien.size();i++)
	{
		if(ds_SinhVien[i]->CheckValid()==1)
			tongHP += ds_SinhVien[i]->TienHocPhi();
	}
	return tongHP;
}

School::~School()
{
	for (int i = 0; i < ds_SinhVien.size(); i++)
		delete ds_SinhVien[i];
	ds_SinhVien.clear();
}
