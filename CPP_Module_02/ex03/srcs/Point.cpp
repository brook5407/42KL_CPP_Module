/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:43:43 by brook             #+#    #+#             */
/*   Updated: 2023/03/07 13:09:05 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Default Constructor function */
Point::Point() : _x(0), _y(0) {
}

/* Coordinate Constructor function */
Point::Point(const float x, const float y) : _x(x), _y(y){
}

/* Coordinate Constructor function */
Point::Point(const Point &point) {
	(*this) = point;
}

/* Copy assignment operator overload function */
Point &Point::operator=(const Point &point) {
	_x = point._x;
	_y = point._y;
	return (*this);
}

/* Destructor function */
Point::~Point() {
}

/* Get the X-axis value of Point class */
float Point::getX() const {
	return (_x.toFloat());
}

/* Get the Y-axis value of Point class */
float Point::getY() const {
	return (_y.toFloat());
}
