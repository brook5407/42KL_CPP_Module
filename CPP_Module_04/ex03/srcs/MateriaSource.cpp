/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:48:34 by brook             #+#    #+#             */
/*   Updated: 2023/03/14 18:48:34 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < MAX_INV; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
	(*this) = materiaSource;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
	const AMateria	*tmp;

	for (int i = 0; i < MAX_INV; i++){
		tmp = materiaSource.getAMateria(i);
		if (tmp != NULL)
			this->_inventory[i] = tmp->clone();
		else
			this->_inventory[i] = NULL;
	}
	return(*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MAX_INV; i++)
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
}

AMateria *MateriaSource::getAMateria(int idx) const {
	if (idx >= MAX_INV || idx < 0 || this->_inventory[idx] == NULL)
		return (NULL);
	return(this->_inventory[idx]);
}

void MateriaSource::learnMateria(AMateria *aMateria) {
	for (int i = 0; i < MAX_INV; i++){
		if (this->_inventory[i] == NULL){
			this->_inventory[i] = aMateria;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < MAX_INV; i++){
		if (this->_inventory[i] == NULL)
			break;
		if (this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	return (0);
}
