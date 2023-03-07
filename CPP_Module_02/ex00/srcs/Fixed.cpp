/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:04:29 by brook             #+#    #+#             */
/*   Updated: 2023/03/07 11:15:07 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

/* Default Constructor function */
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_fp = 0;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (_fp);
}

/* Set the raw value of the fixed-point number of Fixed class */
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fp = raw;
}
