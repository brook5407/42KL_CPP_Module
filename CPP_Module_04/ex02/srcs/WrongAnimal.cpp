/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:34:50 by brook             #+#    #+#             */
/*   Updated: 2023/03/12 22:34:50 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* Default Constructor function */
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "[WrongAnimal] Default constructor called" << std::endl;
}

/* Copy Constructor function */
WrongAnimal::WrongAnimal(const WrongAnimal &animal) {
	std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
	(*this) = animal;
}

/* Copy assignment operator overload function */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
	std::cout << "[WrongAnimal] Copy assignment operator overload constructor called" << std::endl;
	this->type = animal.type;
	return(*this);
}

/* Destructor function */
WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

/* Getter function for the type of animal class */
std::string WrongAnimal::getType() const {
	return(this->type);
}

/* MakeSound function */
void WrongAnimal::makeSound() const {
	std::cout << "[WrongAnimal] Default type unable to make sound" << std::endl;
}
