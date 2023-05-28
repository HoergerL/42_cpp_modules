#include "Point.hpp"

int main()
{
	Point a(Fixed(1), Fixed(2));
	Point b(Fixed(1), Fixed(0));
	Point c(Fixed(3), Fixed(1));
	Point point(Fixed(2.0f), Fixed(1));
	std::cout << bsp(a, b, c, point) << std::endl;

	Point point2(Fixed(3.0f), Fixed(1));
	std::cout << bsp(a, b, c, point2) << std::endl;
}