/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:57:48 by chchin            #+#    #+#             */
/*   Updated: 2023/02/20 11:38:01 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;
	if (argc == 2)
		harl.complain(argv[1]);
	else
		std::cerr << "\033[1;31mUsage: " << argv[0] << " <level> (DEBUG, INFO, WARNING, ERROR)\033[0m" << std::endl;
	return (0);
}
