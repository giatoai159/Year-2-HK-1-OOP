#pragma once
#include<iostream>
#include<string.h>
#include<sstream>
#include<math.h>
#include<stdlib.h>

using namespace std;

class DynamicArray
{
private:
	int * _a;
	int _len;
	int _max;
public:
	int getLength() { return _len; }
	DynamicArray();
	~DynamicArray();
	void pushBack(int value);
public:
	string toString();
};
