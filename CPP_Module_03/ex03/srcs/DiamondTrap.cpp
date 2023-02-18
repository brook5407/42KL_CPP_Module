/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:20:32 by brook             #+#    #+#             */
/*   Updated: 2023/02/18 23:20:32 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {
	std::cout << "[DiamondTrap] " << name << " : String constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_ep = 50;
	_ad = 30;
	std::cout << "Set hitPoints : " << _hp << std::endl;
	std::cout << "Set energyPoints : " << _ep << std::endl;
	std::cout << "Set attackDamage : " << _ad << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) {
	std::cout << "[DiamondTrap] " << _name << " : Copy constructor called" << std::endl;
	(*this) = diamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
	_name = diamondTrap._name;
	_hp = diamondTrap._hp;
	_ep = diamondTrap._ep;
	_ad = diamondTrap._ad;
	std::cout << "[DiamondTrap] " << _name << " : Copy constructor called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "[DiamondTrap] " << _name << " : Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "[DiamondTrap] " << _name << " : My ClapTrap name is " << ClapTrap::_name << std::endl;
}