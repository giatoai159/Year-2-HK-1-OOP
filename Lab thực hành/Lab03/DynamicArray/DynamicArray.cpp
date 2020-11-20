#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
	_len = 0;
	_max = 128;
}

DynamicArray::~DynamicArray()
{
	delete _a;
	_len = 0;
}

void DynamicArray::pushBack(int value)
{
	int* temparr = new int[_len + 1];
	temparr[_len] = value;
	_a = temparr;
	_len++;
}

string DynamicArray::toString()
{
	stringstream writer;
	for (int i = 0; i <= _len-1; i++)
		writer << _a[i] << " ";
	return writer.str();
}
