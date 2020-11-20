#include<iostream>
#include"CircleV1.h"
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

Circle::Circle()
{
	_center = Point(0, 0);
	_radius = 0;
}

Circle::Circle(Point center, float radius)
{
	_center = center;
	_radius = radius;
}

Circle::~Circle()
{
}
