/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:39:45 by brook             #+#    #+#             */
/*   Updated: 2023/03/14 10:39:45 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	this->_name = "Default";
	for (int i = 0; i < MAX_INV; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name) {
	this->_name = name;
	for (int i = 0; i < MAX_INV; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &character) {
	(*this) = character;
}

Character &Character::operator=(const Character &character) {
	this->_name = character.name;
	for (int i = 0; i < MAX_INV; i++)
		this->_inventory[i] = character._inventory[i];
}

Character::~Character() {
	for (int i = 0; i < MAX_INV; i++)
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
}