/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:40:18 by brook             #+#    #+#             */
/*   Updated: 2023/02/12 18:40:18 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon) {
	_name = name;
}

HumanA::~HumanA() {}

void	HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
