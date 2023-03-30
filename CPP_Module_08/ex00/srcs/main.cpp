/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:50:25 by brook             #+#    #+#             */
/*   Updated: 2023/03/29 20:50:25 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <numeric>
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
	int max;
	std::cout << BOLDBLUE"Enter max: "RESET;
	std::cin >> max;

	std::list<int> lst(max); // create list with max elements
	std::iota(lst.begin(), lst.end(), 1); // fill with 1, 2, ..., max

	std::cout << BOLDBLUE"Enter number to find: "RESET;
	int find;
	std::cin >> find;
	try{
		easyfind(lst, find); // find number in list
		std::cout << BOLDGREEN"Found " << find << " in container."RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << BOLDRED"Not Found"RESET << std::endl;
	}
	return 0;
}