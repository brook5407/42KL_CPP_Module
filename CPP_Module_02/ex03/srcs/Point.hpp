/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:35:27 by brook             #+#    #+#             */
/*   Updated: 2023/02/15 09:35:27 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

private:
	Fixed _x;
	Fixed _y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &point);
	Point &operator=(const Point &point);
	~Point();
	float getX() const;
	float getY() const;

};

bool bsp (Point const a, Point const b, Point const c, Point const point);
#endif
