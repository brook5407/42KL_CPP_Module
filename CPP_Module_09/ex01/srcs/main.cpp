/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:45:08 by brook             #+#    #+#             */
/*   Updated: 2023/04/03 15:45:08 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./eval_expr \"expression\"" << std::endl;
		return 1;
	}
	try {
		RPN rpn;
		std::cout << rpn.evaluate(argv[1]) << std::endl;
	} catch (std::exception &e) {
		std::cout << BOLDRED << e.what() << RESET << std::endl;
	} catch (...) {
	std::cout << BOLDRED << "Error: invalid expression" << RESET << std::endl;
	}
	return 0;
}
