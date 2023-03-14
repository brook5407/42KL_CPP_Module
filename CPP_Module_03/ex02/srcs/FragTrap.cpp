/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:16:07 by brook             #+#    #+#             */
/*   Updated: 2023/02/16 15:16:07 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	_name = "Default";
	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "[FragTrap] Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) {
	_name = name;
	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "[FragTrap] " << _name << " : String constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) {
	std::cout << "[FragTrap] " << _name << " : Copy constructor called" << std::endl;
	(*this) = fragTrap;
}

const FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
	std::cout << "[FragTrap] " << _name << " : Copy constructor called" << std::endl;
	_name = fragTrap._name;
	_hp = fragTrap._hp;
	_ep = fragTrap._ep;
	_ad = fragTrap._ad;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "[FragTrap] " << _name << " : Destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	if (_hp == 0 && _ep == 0)
		std::cout << "[FragTrap] " << _name << " unable to repair: No hit points or energy points remaining."<< std::endl;
	else if (_hp == 0)
		std::cout << "[FragTrap] " << _name << " unable to repair: No hit points remaining."<< std::endl;
	else if (_ep == 0)
		std::cout << "[FragTrap] " << _name << " unable to repair: No energy point remaining."<< std::endl;
	else{
		_ep -= 1;
		std::cout << "[FragTrap] " << _name << " requesting highfives!" << std::endl;
	}
}