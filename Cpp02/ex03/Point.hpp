#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point(const Point &point);
	Point(const Fixed x, const Fixed y);
	~Point();
	Point	&operator=(Point &point);
	Fixed const	get_x() const;
	Fixed const	get_y() const;
	
};


bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif