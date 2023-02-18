/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:43:43 by brook             #+#    #+#             */
/*   Updated: 2023/02/15 09:43:43 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y){
}

Point::Point(const Point &point) {
	(*this) = point;
}

Point &Point::operator=(const Point &point) {
	_x = point._x;
	_y = point._y;
	return (*this);
}

Point::~Point() {
}

float Point::getX() const {
	return (_x.toFloat());
}

float Point::getY() const {
	return (_y.toFloat());
}