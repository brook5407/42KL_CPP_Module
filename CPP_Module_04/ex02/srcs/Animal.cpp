/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:36:21 by brook             #+#    #+#             */
/*   Updated: 2023/03/12 20:36:21 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* Default Constructor function */
Animal::Animal() : type("Animal") {
	std::cout << "[Animal] Default constructor called" << std::endl;
}

/* Copy Constructor function */
Animal::Animal(const Animal &animal) {
	std::cout << "[Animal] Copy constructor called" << std::endl;
	(*this) = animal;
}

/* Copy assignment operator overload function */
Animal &Animal::operator=(const Animal &animal) {
	std::cout << "[Animal] Copy assignment operator overload constructor called" << std::endl;
	this->type = animal.type;
	return(*this);
}

/* Destructor function */
Animal::~Animal() {
	std::cout << "[Animal] Destructor called" << std::endl;
}

/* Getter function for the type of animal class */
std::string Animal::getType() const {
	return(this->type);
}

///* MakeSound function */
//void Animal::makeSound() const {
//	std::cout << "[Animal] Default type unable to make sound" << std::endl;
//}
