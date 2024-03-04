#ifndef POINT_HPP
#define POINT_HPP

class Point
{
private:
	float x;
	float y;
public:
	Point();
	Point(float const x, float const y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	float getX() const;
	float getY() const;
};

#endif
