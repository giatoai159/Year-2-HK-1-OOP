#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;

class Pet
{
private:
	string name;
	int age;
	int weight;
public:
	//
	Pet();
	Pet(string name, int age, int weight);
	Pet(const Pet &p);
	~Pet();
	//
	string getName() { return name; }
	int getAge() { return age; }
	int getWeight() { return weight; }
	void setName(string name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	void setWeight(int weight) { this->weight = weight; }
	//
};

class Dog : public Pet
{
private:
	int length;
	int height;
public:
	Dog();
	Dog(string name, int age, int weight, int length, int height);
	~Dog();
	//
	int getLength() { return length; }
	int getHeight() { return height; }
	void setLength(int length) { this->length = length; }
	void setHeight(int height) { this->height = height; }
	double calcFoodCost() { return (getWeight() * 0.05); }
	//
	void Nhap();
	void Xuat();
};

class Cat : public Pet
{
private:
	string catType;
public:
	Cat();
	Cat(string name, int age, int weight, string catType);
	~Cat();
	//
	string getCatType() { return catType; }
	void setCatType(string catType) { this->catType = catType; }
	double calcFoodCost() { return ((getWeight()-1) * 0.04); }
	//
	void Nhap();
	void Xuat();
};

class Hamster : public Pet
{
private:
	int furColor;
public:
	Hamster();
	Hamster(string name, int age, int weight, int furColor);
	~Hamster();
	//
	int getFurColor() { return furColor; }
	void setFurColor(int furColor) { this->furColor = furColor; }
	double calcFoodCost() {
		if (furColor == 0 || furColor == 2)
			return ((getWeight() + getAge()) * 0.02);
		else return (getWeight() * 0.025);
	}
	//
	void Nhap();
	void Xuat();
};

class Home
{
private:
	vector<Dog>list_Dog;
	vector<Cat>list_Cat;
	vector<Hamster>list_Hamster;
public:
	//
	void NhapDog();
	void XuatDog();
	void NhapCat();
	void XuatCat();
	void NhapHamster();
	void XuatHamster();
	double totalFoodCost();
	void NhapDS();
	void XuatDS();
	~Home();
};