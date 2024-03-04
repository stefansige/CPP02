#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const x, float const y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Point::~Point() {}

float Point::getX() const
{
	return x;
}

float Point::getY() const
{
	return y;
}
