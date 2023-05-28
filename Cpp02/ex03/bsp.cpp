#include "Point.hpp"

Fixed	calc_bsp_formula(Point const point1,  Point const point2, Point const point3)
{
	Fixed fixed;
	fixed = (point2.get_y() - point3.get_y()) * (point1.get_x() - point3.get_x()) -
		 (point1.get_y() - point3.get_y()) * (point2.get_x() - point3.get_x());
	return (fixed);
}
bool bsp (Point const a, Point const b, Point const c, Point const point)
{
	Fixed res_a_b;
	Fixed res_a_c;
	Fixed res_b_a;
	Fixed res_b_c;

	res_a_b = calc_bsp_formula(a, b, point);
	res_a_c = calc_bsp_formula(a, c, point);
	if (!((res_a_b > 0 && res_a_c < 0) || (res_a_b < 0 && res_a_c > 0)))
		return (false);

	res_b_a = calc_bsp_formula (b, a, point);
	res_b_c = calc_bsp_formula (b, c, point);
	if (!((res_b_a > 0 && res_b_c < 0) || (res_b_a < 0 && res_b_c > 0)))
		return (false);
	return (true);
}