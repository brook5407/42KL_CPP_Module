/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:43:13 by chchin            #+#    #+#             */
/*   Updated: 2023/02/20 11:05:26 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* Constructor function */
/*initializes array of function pointers named levels with pointers
	to the debug, info, warning, and error functions of the Harl class. */
Harl::Harl() {
	levels[0] = &Harl::debug;
	levels[1] = &Harl::info;
	levels[2] = &Harl::warning;
	levels[3] = &Harl::error;
}

/* Destructor function*/
Harl::~Harl() {}

/* Debug messages function */
void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

/* Info messages function */
void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

/* Warning messages function */
void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

/* Error messages function */
void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/* Calles respective function using pointers */
void	Harl::complain(std::string level) {
	std::string level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; ++i) {
		if (level == level_list[i]) {
			(this->*levels[i])();
			break;
	}
  }
}

