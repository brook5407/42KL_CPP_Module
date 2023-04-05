/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:31:20 by brook             #+#    #+#             */
/*   Updated: 2023/04/03 20:31:20 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

//write a function to check whether the argument is a number
bool isNumber(char *str) {
	int i = 0;
	while (str[i]) {
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: ./pmergeMe number1 number2 [...]" << std::endl;
		return 1;
	}
	int i = 1;
	while (i < argc) {
		if (!isNumber(argv[i])) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
		i++;
	}
	PmergeMe pmergeMe(argc - 1, argv + 1);
	std::cout << BOLDBLUE"Before sort:" << std::endl;
	pmergeMe.printDeque();
	std::cout << BOLDMAGENTA"After sort:" << std::endl;
	clock_t start1 = clock();
	pmergeMe.dequeSort();
	clock_t end1 = clock();
	double time1 = static_cast<double>(end1 - start1) * 1000 / CLOCKS_PER_SEC;
	pmergeMe.printDeque();
	std::cout << BOLDGREEN"Time to process a range of " << argc - 1 << " elements with std::deque : " << time1 << " us." << std::endl;

	clock_t start2 = clock();
	pmergeMe.listSort();
	clock_t end2 = clock();
	double time2 = static_cast<double>(end2 - start2) * 1000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << time2 << " us."RESET << std::endl;
	return 0;
}