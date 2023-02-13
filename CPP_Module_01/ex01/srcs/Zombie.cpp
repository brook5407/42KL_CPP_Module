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

/* Constructor function */
Zombie::Zombie() {
	_name = "Zombie";
}

/* Destructor function */
Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " has been destroyed." << std::endl;
}

/* A function that announce its own name */
void	Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* Set the name into Zombie class */
void	Zombie::set_name(std::string name) {
	_name = name;
}