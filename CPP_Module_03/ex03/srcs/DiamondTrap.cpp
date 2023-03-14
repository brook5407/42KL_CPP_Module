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

DiamondTrap::DiamondTrap() {
	this->ClapTrap::_name = "Default_clap_name";
	this->_name = "Default";
	this->_hp = FragTrap::_init_hp;
	this->_ep = ScavTrap::_init_ep;
	this->_ad = FragTrap::_init_ad;
	std::cout << "[DiamondTrap] Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
	this->ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hp = FragTrap::_init_hp;
	this->_ep = ScavTrap::_init_ep;
	this->_ad = FragTrap::_init_ad;
	std::cout << "[DiamondTrap] " << this->_name << " : String constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) {
	std::cout << "[DiamondTrap] " << this->_name << " : Copy constructor called" << std::endl;
	(*this) = diamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
	this->_name = diamondTrap._name;
	this->_hp = diamondTrap._hp;
	this->_ep = diamondTrap._ep;
	this->_ad = diamondTrap._ad;
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
