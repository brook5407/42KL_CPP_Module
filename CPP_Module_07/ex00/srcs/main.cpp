/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:59:22 by brook             #+#    #+#             */
/*   Updated: 2023/03/27 15:59:22 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() {
	std::cout << "--------------------- Integer Type Test ---------------------" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;

	::swap(a, b);
	std::cout << "after swap: ";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << "--------------------- String Type Test ---------------------" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;

	::swap(c, d);
	std::cout << "after swap: ";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "--------------------- float Type Test ---------------------" << std::endl;
	float e = 4.2f;
	float f = 2.4f;
	std::cout << "e = " << e << ", f = " << f << std::endl;

	::swap(e, f);
	std::cout << "after swap: ";
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	return 0;
}
