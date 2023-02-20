/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:50:28 by brook             #+#    #+#             */
/*   Updated: 2023/02/20 10:37:54 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* Constructor function */
HumanB::HumanB(std::string name) : _weapon(NULL) {
	_name = name;
}

/* Destructor function */
HumanB::~HumanB() {
}

/* Attack function of the HumanB class */
void	HumanB::attack() {
	if (_weapon != NULL)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their fist" << std::endl;
}

/* Set Weapon function of HumanB class*/
void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
