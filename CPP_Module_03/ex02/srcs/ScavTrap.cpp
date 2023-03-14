/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:16:22 by brook             #+#    #+#             */
/*   Updated: 2023/02/16 13:16:22 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	_name = "Default";
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "[ScavTrap] Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	_name = name;
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "[ScavTrap] " << _name << " : String constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
	std::cout << "[ScavTrap] " << _name << " : Copy constructor called" << std::endl;
	(*this) = scavTrap;
}

const ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
	std::cout << "[ScavTrap] " << _name << " : Copy constructor called" << std::endl;
	_name = scavTrap._name;
	_hp = scavTrap._hp;
	_ep = scavTrap._ep;
	_ad = scavTrap._ad;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "[ScavTrap] " << _name << " : Destructor called" << std::endl;
}

void ScavTrap::guardGate() {
	if (_hp == 0 && _ep == 0)
		std::cout << "[ScavTrap] " << _name << " Gate keeper mode failed: No hit points or energy points remaining."<< std::endl;
	else if (_hp == 0)
		std::cout << "[ScavTrap] " << _name << " Gate keeper mode failed: No hit points remaining."<< std::endl;
	else if (_ep == 0)
		std::cout << "[ScavTrap] " << _name << " Gate keeper mode failed: No energy point remaining."<< std::endl;
	else{
		_ep -= 1;
		std::cout << "[ScavTrap] " << _name << " is now in Gate keeper mode. Energy points remaining: " << _ep << std::endl;
	}
}