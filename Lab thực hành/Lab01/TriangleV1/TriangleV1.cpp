#include<iostream>
#include"TriangleV1.h"
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

Triangle::Triangle()
{
	_a = _b = _c = Point(0, 0);
}

Triangle::Triangle(Point a, Point b, Point c)
{
	_a = a;
	_b = b;
	_c = c;
}

Triangle::~Triangle()
{
}
