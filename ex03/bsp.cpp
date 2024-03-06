#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed const a1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed const a2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
	Fixed const a3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());
	return (a1 >= 0 && a2 >= 0 && a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0) || (a1 == 0 && a2 == 0 && a3 == 0);
}
