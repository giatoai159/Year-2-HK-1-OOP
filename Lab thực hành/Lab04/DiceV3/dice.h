#pragma once
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

class Dice
{
private:
	int _rollCount;
public:
	Dice();
	int getRC() { return _rollCount; }
	int Roll();
};
