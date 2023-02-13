/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:52:43 by brook             #+#    #+#             */
/*   Updated: 2023/02/12 15:52:43 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name ){
	Zombie	*zombies;

	if (N < 0)
		return (NULL);
	zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombies[i].set_name(name);
	return (zombies);
}
