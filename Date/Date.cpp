#include "Date.h"

Date::Date()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	nam = now->tm_year + 1900;
	thang = now->tm_mon + 1;
	ngay = now->tm_mday;
}

void Date::print()
{
	cout << ngay << "/" << thang << "/" << nam;
}
