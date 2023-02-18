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
	std::cout << "Default constructor called" << std::endl;
	_num = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	_num = num * (1 << _fractionalBits);
};

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	_num = roundf(num * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	(*this) = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	_num = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_num);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_num = raw;
}

int Fixed::toInt() const {
	return (_num / (1 << _fractionalBits));
}

float Fixed::toFloat() const {
	return ((float)_num / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}