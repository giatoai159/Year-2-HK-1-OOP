#pragma once
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

class Point
{
private:
	float _x;
	float _y;
public:
	const float X() { return _x; }
	const float Y() { return _y; }
	void setX(const float value) { _x = value; }
	void setY(const float value) { _y = value; }
public:
	Point();
	Point(const float x,const float y);
public:
	const float calcDistanceto(Point* other);
};

class Rectangle
{
private:
	Point* _topLeft;
	Point* _bottomRight;
public:
	Point* topLeft() { return _topLeft; }
	Point* bottomRight() { return _bottomRight; }
	void settopLeft(Point* p) { _topLeft = p; }
	void setbottomRight(Point* p) { _bottomRight = p; }
public:
	Rectangle();
	Rectangle(Point* topLeft,Point* bottomRight);
	~Rectangle();
public:
	float Perimeter();
	float Area();
};
