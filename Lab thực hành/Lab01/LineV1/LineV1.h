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

class Line
{
private:
	Point _start;
	Point _end;
public:
	Point getStart() { return _start; }
	Point getEnd() { return _end; }
	void setStart(float x, float y);
	void setEnd(float, float);
public:
	Line();
	Line(Point start, Point end);
	~Line();
};