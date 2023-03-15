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
	const AMateria	*tmp;
	this->_name = character._name;
	for (int i = 0; i < MAX_INV; i++){
		tmp = character.getAMateria(i);
		if (tmp != NULL)
			this->_inventory[i] = tmp->clone();
		else
			this->_inventory[i] = NULL;
	}
	return(*this);
}

Character::~Character() {
	for (int i = 0; i < MAX_INV; i++)
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
}

AMateria *Character::getAMateria(int idx) const {
	if (idx >= MAX_INV || idx < 0 || this->_inventory[idx] == NULL)
		return (NULL);
	return(this->_inventory[idx]);
}

const std::string &Character::getName() const{
	return(this->_name);
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < MAX_INV; i++){
		if (this->_inventory[i] == NULL){
			this->_inventory[i] = m;
				return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= MAX_INV || idx < 0 || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= MAX_INV || idx < 0 || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
}

std::ostream& operator<<(std::ostream& os, const Character& target) {
	os << "[Character] Name:" << target.getName() << std::endl;
	os << "[Character] Inventory:" << std::endl;
	for (int i = 0; i < MAX_INV; i++){
		os << i << ". ";
		if (target._inventory[i] != NULL)
			os << target._inventory[i]->getType();
		os << std::endl;
	}
	return (os);
}
