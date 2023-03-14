/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:56:14 by brook             #+#    #+#             */
/*   Updated: 2023/02/16 10:56:14 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hp(10), _ep(10), _ad(0) {
	std::cout << "[ClapTrap] Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0) {
	std::cout << "[ClapTrap] " << _name << " : String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	std::cout << "[ClapTrap] " << _name << " : Copy constructor called" << std::endl;
	(*this) = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
	std::cout << "[ClapTrap] " << _name << " : Copy constructor called" << std::endl;
	_name = clapTrap._name;
	_hp = clapTrap._hp;
	_ep = clapTrap._ep;
	_ad = clapTrap._ad;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "[ClapTrap] " << _name << " : Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (_hp == 0 && _ep == 0)
		std::cout << "[ClapTrap] " << _name << " unable to attack: No hit points or energy points remaining."<< std::endl;
	else if (_hp == 0)
		std::cout << "[ClapTrap] " << _name << " unable to attack: No hit points remaining."<< std::endl;
	else if (_ep == 0)
		std::cout << "[ClapTrap] " << _name << " unable to attack: No energy point remaining."<< std::endl;
	else
		std::cout << "[ClapTrap] " << _name << " attacks " << target << ", " << "causing " << _ad << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hp == 0 )
		std::cout << "[ClapTrap] " << _name << " unable to take damage: No hit points remaining."<< std::endl;
	else {
		if (_hp < amount)
			_hp = 0;
		else
			_hp -= amount;
		std::cout << "[ClapTrap] " << _name << " receives " << amount << " hit points of damage. Hit points remaining: " << _hp << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hp == 0 && _ep == 0)
		std::cout << "[ClapTrap] " << _name << " unable to repair: No hit points or energy points remaining."<< std::endl;
	else if (_hp == 0)
		std::cout << "[ClapTrap] " << _name << " unable to repair: No hit points remaining."<< std::endl;
	else if (_ep == 0)
		std::cout << "[ClapTrap] " << _name << " unable to repair: No energy point remaining."<< std::endl;
	else{
		_hp += amount;
		_ep -= 1;
		std::cout << "[ClapTrap] " << _name << " repairs itself and gains "<< amount << " hit points. Energy points remaining: " << _ep << std::endl;
	}
}

void ClapTrap::showStatus() {
	std::cout << "[Status] Name: " << _name << ", Hp: " << _hp << ", Ep: " << _ep << ", Ad: " << _ad << std::endl;
}