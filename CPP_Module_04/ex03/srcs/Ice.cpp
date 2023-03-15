/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:36:25 by brook             #+#    #+#             */
/*   Updated: 2023/03/13 23:36:25 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
	this->_type = "ice";
}

Ice::Ice(const Ice &ice) {
	(*this) = ice;
}

Ice &Ice::operator=(const Ice &ice) {
	this->_type = ice._type;
	return(*this);
}

Ice::~Ice() {}

AMateria *Ice::clone() const {
	AMateria *newIce;

	newIce = new Ice;
	return (newIce);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}