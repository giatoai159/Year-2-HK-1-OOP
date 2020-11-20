#include"RectangleV2.h"
using namespace std;

Point::Point()
{
	this->_x = 0;
	this->_y = 0;
}

Point::Point(const float x,const float y)
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
}

Rectangle::Rectangle(Point* topLeft,Point* bottomRight)
{
	_topLeft = topLeft;
	_bottomRight = bottomRight;
}

Rectangle::~Rectangle()
{
	delete _topLeft;
	delete _bottomRight;
}

float Rectangle::Perimeter()
{
	Point temp(_topLeft->X(), _bottomRight->Y());
	float dai = temp.calcDistanceto(_bottomRight);
	float rong = sqrt(pow(_topLeft->calcDistanceto(_bottomRight), 2) - pow(dai, 2));
	float perimeter = dai * 2 + rong * 2;
	return perimeter;
}

float Rectangle::Area()
{
	Point temp(_topLeft->X(), _bottomRight->Y());
	float dai = temp.calcDistanceto(_bottomRight);
	float rong = sqrt(pow(_topLeft->calcDistanceto(_bottomRight), 2) - pow(dai, 2));
	float area = dai * rong;
	return area;
}
