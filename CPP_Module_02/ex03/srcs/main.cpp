/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:12:55 by brook             #+#    #+#             */
/*   Updated: 2023/02/13 22:12:55 by brook            ###   ########.fr       */
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

/*
Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
Output: Inside
Explanation:
              B(10,30)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(20,0) */

	std::cout << "Point inside Triangle: " << isInsideTriangle(0, 0, 10, 30, 20, 0, 10, 15);
	std::cout << std::endl;
/*
Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
Output: Outside
Explanation:
              B(10,30)
                / \
               /   \
              /     \
             /       \      P
            /         \
     A(0,0) ----------- C(20,0)*/
	std::cout << "Point inside Triangle: " << isInsideTriangle(0, 0, 10, 30, 20, 0, 30, 15);
	std::cout << std::endl;

}