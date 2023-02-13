/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:33:50 by brook             #+#    #+#             */
/*   Updated: 2023/02/12 13:33:50 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Creates a new zombie using new and returns its pointer */
Zombie	*newZombie(std::string name) {
	Zombie	*zombie = new Zombie(name);
	return (zombie);
}