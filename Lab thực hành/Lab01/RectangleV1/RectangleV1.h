#pragma once

class Point
{
private:
	float _x;
	float _y;
public:
	float X() { return _x; }
	float Y() { return _y; }
	void setX(float value) { _x = value; }
	void setY(float value) { _y = value; }
public:
	Point();
	Point(float x, float y);
	~Point();
};

class Rectangle
{
private:
	Point _topLeft;
	Point _bottomRight;
public:
	Point topLeft() { return _topLeft; }
	Point bottomRight() { return _bottomRight; }
	void settopLeft(Point p) { _topLeft = p; }
	void setbottomRight(Point p) { _bottomRight = p; }
public:
	Rectangle();
	Rectangle(Point topLeft, Point bottomRight);
	~Rectangle();
};
