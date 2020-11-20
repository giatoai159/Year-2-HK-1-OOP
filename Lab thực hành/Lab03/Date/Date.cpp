#include "Date.h"

DateV1::DateV1()
{
	time_t now;
	time(&now);
	struct tm *local = localtime(&now);
	_date = local->tm_mday;
	_month = local->tm_mon + 1;
	_year = local->tm_year + 1900;
}

DateV1::DateV1(int date, int month, int year)
{
	if (isValidDate(date, month, year))
	{
		_date = date;
		_month = month;
		_year = year;
	}
}

int DateV1::isValidDate(int date, int month, int year)
{
	if (month < 1 || month>12)
		return 0;
	if (date < 1 || date>31)
		return 0;
	if (month == 2)
	{
		if (isLeapYear(year))
			return (date <= 29);
		else
			return (date <= 28);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (date <= 30);
	return 1;
}

int DateV1::isLeapYear(int year)
{
	return (((year%4==0)&&(year%100!=0))||(year%400==0));
}

string DateV1::toString()
{
	stringstream writer;
	writer << _date << "/" << _month << "/" << _year;
	return writer.str();
}
