#include "Point.hpp"
#include <iostream>

int main()
{
	Point	a(0, 0);
	Point	b(20, 0);
	Point	c(10, 10);
	Point	point(1, 1.1f);

	if (bsp(a, b, c, point))
		std::cout << "\033[32mInside\033[0m" << std::endl;
	else
		std::cout << "\033[31mOutside\033[0m" << std::endl;
}
