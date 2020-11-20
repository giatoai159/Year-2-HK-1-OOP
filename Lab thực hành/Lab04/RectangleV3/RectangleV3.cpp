#include"RectangleV3.h"
using namespace std;

Point::Point()
{
	this->_x = 0;
	this->_y = 0;
}

Point::Point(const float x, const float y)
{
	this->_x = x;
	this->_y = y;
}

const float Point::calcDistanceto(Point* other)
{
	return sqrt(pow(this->_x - other->_x, 2) + pow(this->_y - other->_y, 2));
}

Rectangle::Rectangle()
{
	_topLeft = new Point(1, 1);
	_bottomRight = new Point(10, 10);
	InstanceCount++;
}

Rectangle::Rectangle(Point * topLeft, Point * bottomRight)
{
	_topLeft = topLeft;
	_bottomRight = bottomRight;
	InstanceCount++;
}

Rectangle::~Rectangle()
{
	delete _topLeft;
	delete _bottomRight;
	InstanceCount--;
}

Rectangle::Rectangle(const Rectangle& other)
{
	this->_topLeft = other._topLeft;
	this->_bottomRight = other._bottomRight;
	InstanceCount++;
}
