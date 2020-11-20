#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

class Student
{
private:
	string name;
	int age;
	int mssv;
	int SoMonDK;
	int SoMonDKThiLai;
	int SoMonDKHocLai;
public:
	//
	void setName(string name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	void setMSSV(int mssv) { this->mssv = mssv; }
	void setMonDK(int value) { this->SoMonDK = value; }
	void setMonDKThiLai(int value) { this->SoMonDKThiLai = value; }
	void setMonDKHocLai(int value) { this->SoMonDKHocLai = value; }
	string getName() { return name; }
	int getAge() { return age; }
	int getMSSV() { return mssv; }
	int getMonDK() { return SoMonDK; }
	int getMonDKThiLai() { return SoMonDKThiLai; }
	int getMonDKHocLai() { return SoMonDKHocLai; }
	//
	Student();
	Student(string name, int age, int mssv, int SoMonDK, int SoMonDKThiLai, int SoMonDKHocLai);
	virtual ~Student();
	//
	void Nhap();
	virtual void Xuat();
	//
	virtual int TienHocPhi();
	virtual int CheckValid();
};

class CNTN :public Student
{
public:
	CNTN();
	CNTN(string name, int age, int mssv, int SoMonDK, int SoMonDKThiLai, int SoMonDKHocLai);
	~CNTN();
	//
	int TienHocPhi();
	void Xuat();
	int CheckValid();
};

class CTTT :public Student
{
public:
	CTTT();
	CTTT(string name, int age, int mssv, int SoMonDK, int SoMonDKThiLai, int SoMonDKHocLai);
	~CTTT();
	//
	int TienHocPhi();
	void Xuat();
	int CheckValid();
};

class School
{
private:
	vector<Student*>ds_SinhVien;
public:
	void Nhap();
	void Xuat();
	int TienHocPhi();
	~School();
};