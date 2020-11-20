#pragma once
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

class Random
{
public:
	Random();
	int Next();
	int Next(int max);
};