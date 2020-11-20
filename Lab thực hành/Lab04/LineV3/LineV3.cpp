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

float Point::CalcDistanceTo(const Point * other) const
{
	float dx = this->_x - other->_x;
	float dy = this->_y - other->_y;
	return (sqrt(dx*dx+dy*dy));
}

float Point::CalcDistance(const Point * a, const Point * b)
{
	return a->CalcDistanceTo(b);

}

Line::Line()
{
	_start = new Point(0, 0);
	_end = new Point(0, 0);
	length = 0;
	InstanceCount++;
}

Line::Line(Point* start, Point* end)
{
	_start = start;
	_end = end;
	length = _start->CalcDistanceTo(_end);
	InstanceCount++;
}

Line::~Line()
{
	delete _start;
	delete _end;
	InstanceCount--;
}

Line::Line(const Line& line)
{
	_start = line._start;
	_end = line._end;
	this->length = line.length;
	InstanceCount++;
}
