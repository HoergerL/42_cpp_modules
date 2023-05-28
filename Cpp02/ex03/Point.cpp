#include "Point.hpp"

Point::Point()
{
}

Point::Point(Point const &point) : _x(point.get_x()), _y( point.get_y())
{

}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y)
{

}

Point::~Point()
{

}

Point	&Point::operator=(Point &point)
{
	(void)point;
	return (point);
	return (*this);
}

Fixed const	Point::get_x() const
{
	return (this->_x);
}

Fixed const	Point::get_y() const
{
	return (this->_y);
}