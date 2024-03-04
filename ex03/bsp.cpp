#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed alpha = Fixed((b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX()));
	Fixed beta = Fixed((c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX()));
	Fixed gamma = Fixed((a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX()));

	if ((alpha >= 0 && beta >= 0 && gamma >= 0) || (alpha <= 0 && beta <= 0 && gamma <= 0))
		return true;
	return false;
}
