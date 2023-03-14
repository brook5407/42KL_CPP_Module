/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:40:03 by brook             #+#    #+#             */
/*   Updated: 2023/03/12 22:40:03 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* Default Constructor function */
WrongCat::WrongCat() {
	std::cout << "[WrongCat] Default constructor called" << std::endl;
	this->type = "WrongCat";
}

/* Copy Constructor function */
WrongCat::WrongCat(const WrongCat &cat) {
	std::cout << "[WrongCat] Copy constructor called" << std::endl;
	(*this) = cat;
}

/* Copy assignment operator overload function */
WrongCat &WrongCat::operator=(const WrongCat &cat) {
	std::cout << "[WrongCat] Copy assignment operator overload constructor called" << std::endl;
	this->type = cat.type;
	return (*this);
}

/* Destructor function */
WrongCat::~WrongCat() {
	std::cout << "[WrongCat] Destructor called" << std::endl;
}

/* MakeSound function */
void WrongCat::makeSound() const {
	std::cout << "[WrongCat] cats don’t bark!" << std::endl;
}