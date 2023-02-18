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
	_name = "anonymous";
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "[ScavTrap] " << _name << " : Default constructor called" << std::endl;
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

void ScavTrap::attack(const std::string &target) {
	if (_hp == 0 && _ep == 0)
		std::cout << "[ScavTrap] " << _name << " unable to attack: No hit points or energy points remaining."<< std::endl;
	else if (_hp == 0)
		std::cout << "[ScavTrap] " << _name << " unable to attack: No hit points remaining."<< std::endl;
	else if (_ep == 0)
		std::cout << "[ScavTrap] " << _name << " unable to attack: No energy point remaining."<< std::endl;
	else
		std::cout << "[ScavTrap] " << _name << " attacks " << target << ", " << "causing " << _ad << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (_hp == 0 )
		std::cout << "[ScavTrap] " << _name << " unable to take damage: No hit points remaining."<< std::endl;
	else {
		if (_hp < amount)
			_hp = 0;
		else
			_hp -= amount;
		std::cout << "[ScavTrap] " << _name << " receives " << amount << " hit points of damage. Hit points remaining: " << _hp << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (_hp == 0 && _ep == 0)
		std::cout << "[ScavTrap] " << _name << " unable to repair: No hit points or energy points remaining."<< std::endl;
	else if (_hp == 0)
		std::cout << "[ScavTrap] " << _name << " unable to repair: No hit points remaining."<< std::endl;
	else if (_ep == 0)
		std::cout << "[ScavTrap] " << _name << " unable to repair: No energy point remaining."<< std::endl;
	else{
		_hp += amount;
		_ep -= 1;
		std::cout << "[ScavTrap] " << _name << " repairs itself and gains "<< amount << " hit points. Energy points remaining: " << _ep << std::endl;
	}
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