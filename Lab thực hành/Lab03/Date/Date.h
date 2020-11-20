#pragma once
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<sstream>
#include<string.h>
#include<time.h>

using namespace std;

class DateV1
{
private:
	int _date;
	int _month;
	int _year;
public:
	const int getDate() { return _date; }
	const int getMonth() { return _month; }
	const int getYear() { return _year; }
	void setDate(int value) { _date = value; }
	void setMonth(int value) { _month = value; }
	void setYear(int value) { _year = value; }
public:
	DateV1();
	DateV1(int date, int month, int year);
public:
	static int isValidDate(int date, int month, int year);
	static int isLeapYear(int year);
public:
	string toString();

};