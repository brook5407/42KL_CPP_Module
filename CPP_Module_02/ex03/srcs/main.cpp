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

#include "Point.hpp"

int main( void ) {
	Point a(0,0);
	Point b(10,30);
	Point c(20,0);
	Point point1(10,15);
	Point point2(30,15);

	std::cout << "Input: A = (0, 0), B = (10, 30), C = (20, 0), P1(10, 15), P2(30,15)" << std::endl;
	std::cout << "Explanation:" << std::endl;
	std::cout << "              B(10,30)" << std::endl;
	std::cout << "                / \\" << std::endl;
	std::cout << "               /   \\" << std::endl;
	std::cout << "              /     \\" << std::endl;
	std::cout << "             /   P1  \\      P2" << std::endl;
	std::cout << "            /         \\" << std::endl;
	std::cout << "    A(0,0) ------------ C(20,0)" << std::endl;

	std::cout << "Point1 inside Triangle:\n" << bsp(a, b, c, point1);
	std::cout << std::endl;
	std::cout << "Point2 inside Triangle:\n" << bsp(a, b, c, point2);
	std::cout << std::endl;

}