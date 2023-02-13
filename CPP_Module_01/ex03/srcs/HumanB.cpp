/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:50:28 by brook             #+#    #+#             */
/*   Updated: 2023/02/12 18:50:28 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL) {
	_name = name;
}

HumanB::~HumanB() {}

void	HumanB::attack() {
	if (_weapon != NULL)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their fist" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}