/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:48:24 by brook             #+#    #+#             */
/*   Updated: 2023/02/09 21:48:24 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

void	Contact::set_contact(std::string field[5]){
	this->_firstname = field[0];
	this->_lastname = field[1];
	this->_nickname = field[2];
	this->_phonenumber = field[3];
	this->_darkestsecret = field[4];
}

void	Contact::print_contact(){
	std::cout << "First Name:\t" << this->_firstname << std::endl;
	std::cout << "Last Name:\t" << this->_lastname << std::endl;
	std::cout << "Nickname:\t" << this->_nickname << std::endl;
	std::cout << "Phone Number:\t" << this->_phonenumber << std::endl;
	std::cout << "Darkest Secret:\t" << this->_darkestsecret << std::endl;
}

void	Contact::print_list(){
	std::cout << "|";
	if (this->_firstname.length() > 10)
		std::cout << this->_firstname.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << std::right << this->_firstname;
	std::cout << "|";
	if (this->_lastname.length() > 10)
		std::cout << this->_lastname.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << std::right << this->_lastname;
	std::cout << "|";
	if (this->_nickname.length() > 10)
		std::cout << this->_nickname.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << std::right << this->_nickname;
	std::cout << "|" << std::endl;
}
