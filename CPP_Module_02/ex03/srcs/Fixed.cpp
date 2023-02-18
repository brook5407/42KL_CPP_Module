/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:04:29 by brook             #+#    #+#             */
/*   Updated: 2023/02/13 22:04:29 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() {
	_fp = 0;
}

Fixed::Fixed(const int num) {
	_fp = num * (1 << _fractionalBits);
};

Fixed::Fixed(const float num) {
	_fp = roundf(num * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed) {
	(*this) = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	_fp = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
}

int Fixed::getRawBits() const {
	return (_fp);
}

void Fixed::setRawBits(int const raw) {
	_fp = raw;
}

int Fixed::toInt() const {
	return (_fp / (1 << _fractionalBits));
}

float Fixed::toFloat() const {
	return ((float)_fp / (1 << _fractionalBits));
}

bool Fixed::operator<(const Fixed &fixed) const {
		return (_fp < fixed._fp);
}

bool Fixed::operator>(const Fixed &fixed) const {
	return (_fp > fixed._fp);
}

bool Fixed::operator<=(const Fixed &fixed) const {
	return (_fp <= fixed._fp);
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return (_fp >= fixed._fp);
}

bool Fixed::operator==(const Fixed &fixed) const {
	return (_fp == fixed._fp);
}

bool Fixed::operator!=(const Fixed &fixed) const {
	return (_fp != fixed._fp);
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	return (toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	return (toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	return (toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	return (toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++() {
	_fp++;
	return (*this);
}

Fixed Fixed::operator--() {
	_fp--;
	return (*this);
}

const Fixed Fixed::operator++(int) {
	const Fixed tmp(*this);
	_fp++;
	return (tmp);
}

const Fixed Fixed::operator--(int) {
	const Fixed tmp(*this);
	_fp--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	return (f1 <= f2 ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	return (f1 >= f2 ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
	return (f1 <= f2 ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
	return (f1 >= f2 ? f1 : f2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}



/* A utility function to calculate area of triangle formed by (x1, y1),
   (x2, y2) and (x3, y3) */
static Fixed area(const Fixed& x1, const Fixed& y1,
				  const Fixed& x2, const Fixed& y2,
				  const Fixed& x3, const Fixed& y3) {
	return (ABS(x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/Fixed(2)) ;
}

/* A function to check whether point P(x, y) lies inside the triangle formed
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInsideTriangle(const Fixed& x1, const Fixed& y1,
					  const Fixed& x2, const Fixed& y2,
					  const Fixed& x3, const Fixed& y3,
					  const Fixed& px, const Fixed& py) {
	/* Calculate area of triangle ABC */
	Fixed area0 = area(x1, y1, x2, y2, x3, y3);
	/* Calculate area of triangle PBC */
	Fixed area1 = area (px, py, x2, y2, x3, y3);
	/* Calculate area of triangle PAC */
	Fixed area2 = area (x1, y1, px, py, x3, y3);
	/* Calculate area of triangle PAB */
	Fixed area3 = area (x1, y1, x2, y2, px, py);
	/* Check if sum of A1, A2 and A3 is same as A */
	std::cout << area0 << std::endl;
	std::cout << area1 << std::endl;
	std::cout << area2 << std::endl;
	std::cout << area3 << std::endl;

	return (area0 == area1 + area2 + area3);
}
