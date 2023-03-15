/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:36:33 by brook             #+#    #+#             */
/*   Updated: 2023/03/13 23:36:33 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	this->_type = "cure";
}

Cure::Cure(const Cure &cure) {
	(*this) = cure;
}

Cure &Cure::operator=(const Cure &cure) {
	this->_type = cure._type;
	return (*this);
}

Cure::~Cure() {}

AMateria *Cure::clone() const {
	AMateria *newCure;

	newCure = new Cure;
	return (newCure);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}