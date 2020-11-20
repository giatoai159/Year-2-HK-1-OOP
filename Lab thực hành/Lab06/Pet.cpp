#include "Pet.h"

Pet::Pet()
{
	name = "";
	age = NULL;
	weight = NULL;
}

Pet::Pet(string name, int age, int weight)
{
	this->name = name;
	this->age = age;
	this->weight = weight;
}

Pet::Pet(const Pet& p)
{
	this->name = p.name;
	this->age = p.age;
	this->weight = p.weight;
}

Pet::~Pet()
{
}

Dog::Dog()
{
	setName("");
	setAge(NULL);
	setWeight(NULL);
	length = NULL;
	height = NULL;
}

Dog::Dog(string name, int age, int weight, int length, int height)
{
	setName(name);
	setAge(age);
	setWeight(weight);
	this->length = length;
	this->height = height;
}

Dog::~Dog()
{
}

void Dog::Nhap()
{
	string name;
	int age, weight, length, height;
	cout << "***INPUT***" << endl;
	cout << "Nhap ten cho Dog: "; getline(cin>>ws,name);
	this->setName(name);
	cout << "Nhap tuoi cho Dog: "; cin >> age;
	this->setAge(age);
	cout << "Nhap can nang cho Dog: "; cin >> weight;
	this->setWeight(weight);
	cout << "Nhap chieu dai cho Dog: "; cin >> length;
	this->length = length;
	cout << "Nhap chieu cao cho Dog: "; cin >> height;
	this->height = height;
}

void Dog::Xuat()
{
	cout << "***DOG*** " << endl;
	cout << "Ten: " << this->getName() << endl;
	cout << "Tuoi: " << this->getAge() << endl;
	cout << "Can nang: " << this->getWeight() << endl;
	cout << "Chieu dai: " << this->length << endl;
	cout << "Chieu cao: " << this->height << endl;
}

Cat::Cat()
{
	setName("");
	setAge(NULL);
	setWeight(NULL);
	this->catType = "";
}

Cat::Cat(string name, int age, int weight, string catType)
{
	setName(name);
	setAge(age);
	setWeight(weight);
	this->catType = catType;
}

Cat::~Cat()
{
}

void Cat::Nhap()
{
	string name, catType;
	int age, weight;
	cout << "***INPUT***" << endl;
	cout << "Nhap ten cho Cat: "; getline(cin>>ws, name);
	this->setName(name);
	cout << "Nhap tuoi cho Cat: "; cin >> age;
	this->setAge(age);
	cout << "Nhap can nang cho Cat: "; cin >> weight;
	this->setWeight(weight);
	cout << "Nhap loai meo cho Cat: "; cin >> catType;
	this->catType = catType;
}

void Cat::Xuat()
{
	cout << "***CAT***" << endl;
	cout << "Ten: " << this->getName() << endl;
	cout << "Tuoi: " << this->getAge() << endl;
	cout << "Can nang: " << this->getWeight() << endl;
	cout << "Loai meo: " << this->catType << endl;
}

Hamster::Hamster()
{
	setName("");
	setAge(NULL);
	setWeight(NULL);
	this->furColor = NULL;
}

Hamster::Hamster(string name, int age, int weight, int furColor)
{
	setName(name);
	setAge(age);
	setWeight(weight);
	this->furColor = furColor;
}

Hamster::~Hamster()
{

}

void Hamster::Nhap()
{
	string name;
	int age, weight, furColor;
	cout << "***INPUT***" << endl;
	cout << "Nhap ten cho Hamster: "; getline(cin>>ws, name);
	this->setName(name);
	cout << "Nhap tuoi cho Hamster: "; cin >> age;
	this->setAge(age);
	cout << "Nhap can nang cho Hamster: "; cin >> weight;
	this->setWeight(weight);
	cout << "Nhap mau long cho Hamster: "; cin >> furColor;
	this->furColor= furColor;
}

void Hamster::Xuat()
{
	cout << "***HAMSTER*** " << endl;
	cout << "Ten: " << this->getName() << endl;
	cout << "Tuoi: " << this->getAge() << endl;
	cout << "Can nang: " << this->getWeight() << endl;
	cout << "Mau long: " << this->furColor << endl;
}

void Home::NhapDog()
{
	int n;
	cout << "Ban muon nhap bao nhieu Dog: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		Dog d;
		d.Nhap();
		list_Dog.push_back(d);
	}
}

void Home::XuatDog()
{
	for (unsigned int i = 0; i < list_Dog.size(); i++)
		list_Dog[i].Xuat();
}

void Home::NhapCat()
{
	int n;
	cout << "Ban muon nhap bao nhieu Cat: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		Cat c;
		c.Nhap();
		list_Cat.push_back(c);
	}
}

void Home::XuatCat()
{
	for (unsigned int i = 0; i < list_Cat.size(); i++)
		list_Cat[i].Xuat();
}

void Home::NhapHamster()
{
	int n;
	cout << "Ban muon nhap bao nhieu Hamster: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		Hamster h;
		h.Nhap();
		list_Hamster.push_back(h);
	}
}

void Home::XuatHamster()
{
	for (unsigned int i = 0; i < list_Hamster.size(); i++)
		list_Hamster[i].Xuat();
}

double Home::totalFoodCost()
{
	unsigned int i;
	double foodCost_Dog = 0, foodCost_Cat = 0, foodCost_Hamster = 0;
	for (i = 0; i < list_Dog.size(); i++)
		foodCost_Dog += list_Dog[i].calcFoodCost();
	for (i = 0; i < list_Cat.size(); i++)
		foodCost_Cat += list_Cat[i].calcFoodCost();
	for (i = 0; i < list_Hamster.size(); i++)
		foodCost_Hamster += list_Hamster[i].calcFoodCost();
	return (foodCost_Dog+foodCost_Cat+foodCost_Hamster);
}

void Home::NhapDS()
{
	NhapDog();
	NhapCat();
	NhapHamster();
}

void Home::XuatDS()
{
	XuatDog();
	XuatCat();
	XuatHamster();
}

Home::~Home()
{
	list_Dog.erase(list_Dog.begin(), list_Dog.end());
	list_Cat.erase(list_Cat.begin(), list_Cat.end());
	list_Hamster.erase(list_Hamster.begin(), list_Hamster.end());
}
