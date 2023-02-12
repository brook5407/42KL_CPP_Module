/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:32:31 by brook             #+#    #+#             */
/*   Updated: 2023/02/12 18:32:31 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::~Weapon() {}

void Weapon::setType(std::string type) {
	_type = type;
}

const std::string &Weapon::getType() const {
	return (_type);
}