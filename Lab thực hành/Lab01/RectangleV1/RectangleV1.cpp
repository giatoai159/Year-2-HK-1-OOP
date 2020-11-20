#include<iostream>
#include"RectangleV1.h"
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

Rectangle::Rectangle()
{
	_topLeft = Point(0, 0);
	_bottomRight = Point(0, 0);
}

Rectangle::Rectangle(Point topLeft, Point bottomRight)
{
	if (topLeft.X() < bottomRight.X() && topLeft.Y() > bottomRight.Y())
	{
		_topLeft = topLeft;
		_bottomRight = bottomRight;
	}
	else 
	{
		cout << "Invalid Data. Setting points to (0, 0)." << endl;
		_topLeft = Point(0, 0);
		_bottomRight = Point(0, 0);
	}
}

Rectangle::~Rectangle()
{
}
