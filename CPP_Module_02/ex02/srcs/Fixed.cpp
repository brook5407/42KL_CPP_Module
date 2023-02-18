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
