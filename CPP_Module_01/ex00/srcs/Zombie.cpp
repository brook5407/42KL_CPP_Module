/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:20:22 by brook             #+#    #+#             */
/*   Updated: 2023/02/12 13:20:22 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Constructor function with no parameter */
Zombie::Zombie() {
	_name = "Zombie";
}

/* Constructor function with name parameter */
Zombie::Zombie(std::string name) {
	_name = name;
}

/* Destructor function */
Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " has been destroyed." << std::endl;
}

/* A function that announce its own name */
void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

