/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:50:32 by brook             #+#    #+#             */
/*   Updated: 2023/03/07 15:55:56 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool check_in_linear(Point const a, Point const b, Point const point)
{
	float	m;
	float	c;
	float	dx;
	float	dy;

	dx = b.getX() - a.getX();
	dy = b.getY() - a.getY();
	m = dy / dx;
	c = a.getY() - a.getX() * m;
	if (point.getY() == (m * point.getX() + c))
		return (true);
	return (false);
}

/* A utility function to calculate area of triangle formed by (x1, y1),
   (x2, y2) and (x3, y3) */
static float area(Point const a, Point const b, Point const c) {
	return (abs(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()))) / 2.0;
}

/* A function to check whether point P(x, y) lies inside the triangle formed
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool bsp (Point const a, Point const b, Point const c, Point const point) {
	if (check_in_linear(a, b, point) == true)
		return (false);
	if (check_in_linear(b, c, point) == true)
		return (false);
	if (check_in_linear(a, c, point) == true)
		return (false);
	/* Calculate area of triangle ABC */
	float A = area(a, b, c);
	/* Calculate area of triangle PBC */
	float A1 = area(point, b, c);
	/* Calculate area of triangle PAC */
	float A2 = area(a, point, c);
	/* Calculate area of triangle PAB */
	float A3 = area(a, b, point);
	/* Check if sum of A1, A2 and A3 is same as A */
	return (A == A1 + A2 + A3);
}
