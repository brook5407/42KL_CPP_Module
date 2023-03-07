/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:04:29 by brook             #+#    #+#             */
/*   Updated: 2023/03/07 11:23:07 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

/* Default Constructor function */
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_fp = 0;
}

/* Int Constructor function */
Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	_fp = num * (1 << _fractionalBits);
};

/* Float Constructor function */
Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	_fp = roundf(num * (1 << _fractionalBits));
}

/* Copy constructor function */
Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	(*this) = fixed;
}

/* Copy assignment operator overload function */
Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	_fp = fixed.getRawBits();
	return (*this);
}

/* Destructor function */
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* Get the raw value of the fixed-point value of Fixed class */
int Fixed::getRawBits() const {
	return (_fp);
}

/* Set the raw value of the fixed-point number of Fixed class */
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
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

/* Insertion operator overload function */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
