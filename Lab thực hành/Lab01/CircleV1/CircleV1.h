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

class Circle
{
private:
	Point _center;
	float _radius;
public:
	Point getCenter() { return _center; }
	float getRadius() { return _radius; }
	void setCenter(Point center) { _center = center; }
	void setRadius(float value) { _radius = value; }
public:
	Circle();
	Circle(Point center, float radius);
	~Circle();
};