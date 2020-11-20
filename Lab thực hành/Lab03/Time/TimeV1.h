#pragma once
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<sstream>
#include<string.h>
#include<time.h>

using namespace std;

class TimeV1
{
private:
	int _hour;
	int _minute;
	int _second;
public:
	const int getHour() { return _hour; }
	const int getMinute() { return _minute; }
	const int getSecond() { return _second; }
	void setHour(const int value) { _hour = value; }
	void setMinute(const int value) { _minute = value; }
	void setSecond(const int value) { _second = value; }
public:
	TimeV1();
	TimeV1(int hour, int minute, int second);
public:
	string toString();
};
