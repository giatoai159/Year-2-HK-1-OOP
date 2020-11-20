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
	Point(const float x, const float y);
	float CalcDistanceTo(const Point* other) const;
	float CalcDistance(const Point*a, const Point *b);
};

class Line
{
private:
	Point* _start;
	Point* _end;
	float length;
public:

	static int InstanceCount;
	// Getter, Setter
	Point* getStart() { return _start; }
	Point* getEnd() { return _end; }
	float getLength() { return length; }
	void setStart(Point* start) { _start = start; }
	void setEnd(Point* end) { _end = end; }
	// Cac phuong thuc tao huy
	Line();
	Line(Point* start, Point* end);
	~Line();
	Line(const Line& line);
};