/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:34:52 by brook             #+#    #+#             */
/*   Updated: 2023/02/10 17:34:52 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	cmd;
	while (1){
		std::cin.clear();
		std::cout << "Input command(ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, cmd);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << "\033[1;31m\tError\033[0m" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		if (cmd.compare("ADD") == 0)
			phoneBook.add();
		else if (cmd.compare("SEARCH") == 0)
			phoneBook.search();
		else if (cmd.compare("EXIT") == 0)
			phoneBook.exit();
		else
			std::cout << "\033[1;31m\tCommand not found\033[0m" << std::endl;
	}
}
