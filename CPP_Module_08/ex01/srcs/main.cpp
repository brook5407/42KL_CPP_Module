/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:31:19 by brook             #+#    #+#             */
/*   Updated: 2023/03/29 21:31:19 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int main(void) {
	unsigned int n;
	std::cout << BOLDBLUE"Enter the number of elements: "RESET;
	std::cin >> n;
	srand(time(NULL));
	Span span = Span(n);
	for (unsigned int i = 0; i < n; i++) {
		const int value = rand();
		span.addNumber(value);
	}
//	std::cout << sp << std::endl;
	try {
		std::cout << BOLDGREEN"Shortest span: " << span.shortestSpan() << RESET << std::endl;
		std::cout << BOLDGREEN"Longest span: " << span.longestSpan() << RESET << std::endl;
	} catch (std::invalid_argument & e) {
		std::cout << BOLDRED << e.what() << RESET << std::endl;
	}

//	std::cout << "----------------Default Test----------------" << std::endl;
//	Span sp = Span(5);
//	sp.addNumber(6);
//	sp.addNumber(3);
//	sp.addNumber(17);
//	sp.addNumber(9);
//	sp.addNumber(11);
//
//	try {
//		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
//		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
//	} catch (std::exception & e) {
//		std::cout << "Error!" << std::endl;
//	}

	return 0;
}

