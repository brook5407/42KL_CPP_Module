/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:56:00 by brook             #+#    #+#             */
/*   Updated: 2023/03/12 21:56:00 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* Default Constructor function */
Dog::Dog() {
	std::cout << "[Dog] Default constructor called" << std::endl;
	this->brain = new Brain;
	this->type = "Dog";
}

/* Copy Constructor function */
Dog::Dog(const Dog &dog) {
	std::cout << "[Dog] Copy constructor called" << std::endl;
	this->brain = new Brain;
	(*this) = dog;
}

/* Copy assignment operator overload function */
Dog &Dog::operator=(const Dog &dog) {
	std::cout << "[Dog] Copy assignment operator overload constructor called" << std::endl;
	this->type = dog.type;
	*this->brain = *(dog.brain);
	return (*this);
}

/* Destructor function */
Dog::~Dog() {
	delete(this->brain);
	std::cout << "[Dog] Destructor called" << std::endl;
}

/* MakeSound function */
void Dog::makeSound() const {
	std::cout << "[Dog] Woof!" << std::endl;
}

const Brain &Dog::getBrain() const {
	return(*this->brain);
}

void Dog::setBrainIdea(std::string newIdea) {
	this->brain->setIdea(newIdea);
}