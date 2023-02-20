/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:32:31 by brook             #+#    #+#             */
/*   Updated: 2023/02/20 10:39:27 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* Default Constructor function */
Weapon::Weapon() {}

/* Constructor function */
Weapon::Weapon(std::string type) {
	_type = type;
}

/* Destructor function */
Weapon::~Weapon() {
}

/* Set Type fuction of Weapon class*/
void Weapon::setType(std::string type) {
	_type = type;
}

/* Get Type fuction  of Weapon class*/
const std::string &Weapon::getType() const {
	return (_type);
}
