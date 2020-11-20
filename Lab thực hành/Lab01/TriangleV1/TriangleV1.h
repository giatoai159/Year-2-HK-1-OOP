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

class Triangle
{
private:
	Point _a;
	Point _b;
	Point _c;
public:
	Point A() { return _a; }
	Point B() { return _b; }
	Point C() { return _c; }
	void setA(Point a) { _a = a; }
	void setB(Point b) { _b = b; }
	void setC(Point c) { _c = c; }
public:
	Triangle();
	Triangle(Point a, Point b, Point c);
	~Triangle();
};