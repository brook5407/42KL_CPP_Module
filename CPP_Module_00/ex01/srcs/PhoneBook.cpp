/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:48:19 by brook             #+#    #+#             */
/*   Updated: 2023/02/09 21:48:19 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->_volume = 0;
}

PhoneBook::~PhoneBook() {}

static std::string	get_input(std::string field){
	std::string	input;

	while (1){
		std::cout << "\t" << field;
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail()){
			std::cout << "\033[1;31m\n\tError: Input Failure\033[0m" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		if (!input.empty() && input.find_first_not_of(" \t") != std::string::npos)
			return (input);
		else
			std::cout << "\033[1;31m\tError: Invalid input\033[0m" << std::endl;
	}
}

void	PhoneBook::add() {
	std::string	field[5];
	field[0] = get_input("First Name: ");
	field[1] = get_input("Last Name: ");
	field[2] = get_input("Nickname: ");
	field[3] = get_input("Phone Number: ");
	field[4] = get_input("Darkest Secret: ");
	_contacts[_volume % 8].set_contact(field);
	(_volume)++;
	std::cout << "Added Successful~" << std::endl;
}

void	PhoneBook::search() {
	int 		record;
	std::string	index;

	record = _volume;
	if (record == 0)
	{
		std::cout << "No contacts to display" << std::endl;
		return ;
	}
	if (record > 8)
		record = 8;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < record; i++){
		std::cout << "|" << std::setw(10) << std::right << i ;
		_contacts[i].print_list();
	}
	std::cout << "---------------------------------------------" << std::endl;
	while (1) {
		std::cout << "Enter an index to display additional information: ";
		std::getline(std::cin, index);
		if (std::cin.eof() || std::cin.fail()) {
			std::cout << "\033[1;31m\n\tError: Input Failure\033[0m" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		if (!index.empty() && index.find_first_not_of(" \t") != std::string::npos
			&& index.length() == 1 && isdigit(index[0]) && index[0] - '0' <= record){
			std::cout << " -------------------------------------------\n";
			_contacts[index[0] - '0'].print_contact();
			std::cout << " -------------------------------------------\n";
		}
		else if (index.empty())
			break ;
		else if (isdigit(index[0]) && index[0] -'0' > record)
			std::cout << "\033[1;31m\tError: Index not found\033[0m" << std::endl;
		else
			std::cout << "\033[1;31m\tError: Invalid input\033[0m" << std::endl;
	}
}

void	PhoneBook::exit() {
	std::cout << "\033[0;32m\tEXIT SUCCESSFUL\033[0m" << std::endl;
	std::exit(EXIT_SUCCESS);
}