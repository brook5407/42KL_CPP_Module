/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:12:55 by brook             #+#    #+#             */
/*   Updated: 2023/03/07 16:03:32 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
	Point a(0,0);
	Point b(5,5);
	Point c(10, 0);
	Point point1(2.5, 2.5);
	Point point2(2.6, 2.5);

	std::cout << "Input: A = (0, 0), B = (5, 5), C = (10, 0), P1(2.5, 2.5), P2(2.6, 2.5)" << std::endl;
	std::cout << "Explanation:" << std::endl;
	std::cout << "              B(5,5)" << std::endl;
	std::cout << "                / \\" << std::endl;
	std::cout << "               /   \\" << std::endl;
	std::cout << "           p1 /     \\" << std::endl;
	std::cout << "             /   P2  \\" << std::endl;
	std::cout << "            /         \\" << std::endl;
	std::cout << "    A(0,0) ------------ C(10,0)" << std::endl;

	std::cout << "Point1 inside Triangle:\n" << (bsp(a, b, c, point1) ? "TRUE" : "FALSE");
	std::cout << std::endl;
	std::cout << "Point2 inside Triangle:\n" << (bsp(a, b, c, point2) ? "TRUE" : "FALSE" );
	std::cout << std::endl;
}
