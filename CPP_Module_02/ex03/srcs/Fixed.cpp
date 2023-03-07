/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:04:29 by brook             #+#    #+#             */
/*   Updated: 2023/03/07 13:07:44 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

/* Default Constructor function */
Fixed::Fixed() {
	_fp = 0;
}

/* Int Constructor function */
Fixed::Fixed(const int num) {
	_fp = num * (1 << _fractionalBits);
};

/* Float Constructor function */
Fixed::Fixed(const float num) {
	_fp = roundf(num * (1 << _fractionalBits));
}

/* Coordinate Constructor function */
Fixed::Fixed(const Fixed &fixed) {
	(*this) = fixed;
}

/* Copy assignment operator overload function */
Fixed &Fixed::operator=(const Fixed &fixed) {
	_fp = fixed.getRawBits();
	return (*this);
}

/* Destructor function */
Fixed::~Fixed() {
}

/* Get the raw value of the fixed-point value of Fixed class */
int Fixed::getRawBits() const {
	return (_fp);
}

/* Set the raw value of the fixed-point number of Fixed class */
void Fixed::setRawBits(int const raw) {
	_fp = raw;
}

/* Converts the fixed-point value to a floating-point value of Fixed class */
int Fixed::toInt() const {
	return (_fp / (1 << _fractionalBits));
}

/* Converts the fixed-point value to an integer value of Fixed class */
float Fixed::toFloat() const {
	return ((float)_fp / (1 << _fractionalBits));
}

/* Comparison operators overload (<) function */
bool Fixed::operator<(const Fixed &fixed) const {
		return (_fp < fixed._fp);
}

/* Comparison operators overload (>) function */
bool Fixed::operator>(const Fixed &fixed) const {
	return (_fp > fixed._fp);
}

/* Comparison operators overload (<=) function */
bool Fixed::operator<=(const Fixed &fixed) const {
	return (_fp <= fixed._fp);
}

/* Comparison operators overload (>=) function */
bool Fixed::operator>=(const Fixed &fixed) const {
	return (_fp >= fixed._fp);
}

/* Comparison operators overload (==) function */
bool Fixed::operator==(const Fixed &fixed) const {
	return (_fp == fixed._fp);
}

/* Comparison operators overload (!=) function */
bool Fixed::operator!=(const Fixed &fixed) const {
	return (_fp != fixed._fp);
}

/* Arithmetic operators overload (+) function */
Fixed Fixed::operator+(const Fixed &fixed) const {
	return (toFloat() + fixed.toFloat());
}

/* Arithmetic operators overload (-) function */
Fixed Fixed::operator-(const Fixed &fixed) const {
	return (toFloat() - fixed.toFloat());
}

/* Arithmetic operators overload (*) function */
Fixed Fixed::operator*(const Fixed &fixed) const {
	return (toFloat() * fixed.toFloat());
}

/* Arithmetic operators overload (/) function */
Fixed Fixed::operator/(const Fixed &fixed) const {
	return (toFloat() / fixed.toFloat());
}

/* Pre-increment operators overload function */
Fixed Fixed::operator++() {
	_fp++;
	return (*this);
}

/* Pre-decrement operators overload function */
Fixed Fixed::operator--() {
	_fp--;
	return (*this);
}

/* Post-increment operators overload function */
const Fixed Fixed::operator++(int) {
	const Fixed tmp(*this);
	_fp++;
	return (tmp);
}

/* Post-decrement operators overload function */
const Fixed Fixed::operator--(int) {
	const Fixed tmp(*this);
	_fp--;
	return (tmp);
}

/* Min function of Fixed class */
Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	return (f1 <= f2 ? f1 : f2);
}

/* Max function of Fixed class */
Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	return (f1 >= f2 ? f1 : f2);
}

/* Min function of Fixed class */
const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
	return (f1 <= f2 ? f1 : f2);
}

/* Max function of Fixed class */
const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
	return (f1 >= f2 ? f1 : f2);
}

/* Insertion operator overload function */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
