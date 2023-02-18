/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:57:26 by brook             #+#    #+#             */
/*   Updated: 2023/02/13 21:57:26 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					_fp;
	static const int	_fractionalBits;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(const Fixed &fixed) const;
	bool	operator<(const Fixed &fixed) const;
	bool	operator>=(const Fixed &fixed) const;
	bool	operator<=(const Fixed &fixed) const;
	bool	operator==(const Fixed &fixed) const;
	bool	operator!=(const Fixed &fixed) const;
	Fixed	operator+(const Fixed &fixed) const;
	Fixed	operator-(const Fixed &fixed) const;
	Fixed	operator*(const Fixed &fixed) const;
	Fixed	operator/(const Fixed &fixed) const;

	Fixed	operator++(void);
	Fixed	operator--(void);
	const Fixed	operator++(int);
	const Fixed	operator--(int);

	static Fixed &min(Fixed &f1, Fixed &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static const Fixed &min(const Fixed &f1, const Fixed &f2);
	static const Fixed &max(const Fixed &f1, const Fixed &f2);
};

std::ostream &operator<<(std::ostream &output, const Fixed &f);

bool isInsideTriangle(const Fixed& x1, const Fixed& y1,
					  const Fixed& x2, const Fixed& y2,
					  const Fixed& x3, const Fixed& y3,
					  const Fixed& px, const Fixed& py);

#endif
