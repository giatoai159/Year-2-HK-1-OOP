#include<iostream>
#include"LineV1.h"
using namespace std;

Point::Point()
{
	this->_x = 0;
	this->_y = 0;
}

Point::Point(float x, float y)
{
	this->_x = x;
	this->_y = y;
}

Point::~Point()
{
}

void Line::setStart(float x, float y)
{
	this->_start = Point(x, y);
}

void Line::setEnd(float x, float y)
{
	this->_end = Point(x, y);
}

Line::Line()
{
	this->_start = Point(0, 0);
	this->_end = Point(0, 0);
}

Line::Line(Point start, Point end)
{
	this->_start = start;
	this->_end = end;
}

Line::~Line()
{
}