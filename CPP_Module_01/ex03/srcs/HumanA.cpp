/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:40:18 by brook             #+#    #+#             */
/*   Updated: 2023/02/20 10:33:34 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* Constructor function */
HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon) {
	_name = name;
}

/* Destructor function */
HumanA::~HumanA() {
}

/* Attack function of the HumanA class */
void	HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
