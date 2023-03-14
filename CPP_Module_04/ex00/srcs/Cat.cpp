/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:06:31 by brook             #+#    #+#             */
/*   Updated: 2023/03/12 22:06:31 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* Default Constructor function */
Cat::Cat() {
	std::cout << "[Cat] Default constructor called" << std::endl;
	this->type = "Cat";
}

/* Copy Constructor function */
Cat::Cat(const Cat &cat) {
	std::cout << "[Cat] Copy constructor called" << std::endl;
	(*this) = cat;
}

/* Copy assignment operator overload function */
Cat &Cat::operator=(const Cat &cat) {
	std::cout << "[Cat] Copy assignment operator overload constructor called" << std::endl;
	this->type = cat.type;
	return (*this);
}

/* Destructor function */
Cat::~Cat() {
	std::cout << "[Cat] Destructor called" << std::endl;
}

/* MakeSound function */
void Cat::makeSound() const {
	std::cout << "[Cat] cats don’t bark!" << std::endl;
}