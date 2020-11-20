#include "TimeV1.h"

TimeV1::TimeV1()
{
	time_t now;
	time(&now);
	struct tm *local = localtime(&now);
	_hour = local->tm_hour;
	_minute = local->tm_min;
	_second = local->tm_sec;
}

TimeV1::TimeV1(int hour, int minute, int second)
{
	_hour = hour;
	_minute = minute;
	_second = second;
}

string TimeV1::toString()
{
	stringstream writer;
	if (_hour < 12)
		writer << _hour << ":" << _minute << ":" << _second << "AM";
	else
		writer << _hour - 12 << ":" << _minute << ":" << _second << "PM";
	return writer.str();
}
