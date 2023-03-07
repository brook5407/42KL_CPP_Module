/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:12:55 by brook             #+#    #+#             */
/*   Updated: 2023/03/07 13:19:45 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	Fixed c(3);

	std::cout << c + c << std::endl;
	std::cout << c - c << std::endl;
	std::cout << c * c << std::endl;
	std::cout << c / c << std::endl;

	Fixed d(2);
	if (c > d)
		std::cout << c << " is larger than " << d << std::endl;
	else
		std::cout << c << " is not larger than " << d << std::endl;

	if (c < d)
		std::cout << d << " is not smaller than " << c << std::endl;
	else
		std::cout << d << " is smaller than " << c << std::endl;

	if (c != d)
		std::cout << c << " is not equal to " << d << std::endl;
	else
		std::cout << "smtg wrong" << std::endl;

	d = d + 1;
	if (c == d)
		std::cout << d << " is equal to " << c << std::endl;
	else
		std::cout << "smtg wrong" << std::endl;
}
