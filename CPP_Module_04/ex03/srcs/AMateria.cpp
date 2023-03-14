/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:55:28 by brook             #+#    #+#             */
/*   Updated: 2023/03/13 22:55:28 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	this->_type = "AMateria";
}

AMateria::AMateria(std::string const &type) {
	this->_type = type;
}

AMateria::AMateria(const AMateria &aMateria) {
	(*this) = aMateria;
}

AMateria &AMateria::operator=(const AMateria &aMateria) {
	this->_type = aMateria._type;
	return (*this);
}

AMateria::~AMateria() {
}

const std::string &AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter &target) {}