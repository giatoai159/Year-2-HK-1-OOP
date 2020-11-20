#include "LineV3.h"

Point::Point()
{
	_x = 0;
	_y = 0;
}

Point::Point(const float x, const float y)
{
	_x = x;
	_y = y;
}

Line::Line()
{
	_start = new Point(0, 0);
	_end = new Point(0, 0);
}

Line::Line(Point* start, Point* end)
{
	_start = start;
	_end = end;
}

Line::~Line()
{
	delete _start;
	delete _end;
}

Line::Line(const Line& line)
{
	_start = line._start;
	_end = line._end;
}
