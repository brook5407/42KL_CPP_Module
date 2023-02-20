/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:43:13 by chchin            #+#    #+#             */
/*   Updated: 2023/02/20 11:06:57 by chchin           ###   ########.fr       */
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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

/* Info messages function */
void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money." <<std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

/* Warning messages function */
void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

/* Error messages function */
void	Harl::error(void) {
	std::cout << "This is unacceptable!" << std::endl;
	std::cout << "I want to speak to the manager now." << std::endl;
}

/* Calles respective function using pointers */
void	Harl::complain(std::string level) {
	int			index = 4;
	std::string level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (level == level_list[i]){
			index = i;
			break ;
		}
	}
	switch (index) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*levels[0])();
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			(this->*levels[1])();
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			(this->*levels[2])();
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*levels[3])();
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
