/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:36:59 by brook             #+#    #+#             */
/*   Updated: 2023/02/12 13:36:59 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Creates a new zombie, setting its name and announces itself */
void	randomChump(std::string name) {
	Zombie	zombie(name);
	zombie.announce();
}
