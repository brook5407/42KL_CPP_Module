/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:41:32 by brook             #+#    #+#             */
/*   Updated: 2023/02/12 13:41:32 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 5;
	Zombie *zombies = zombieHorde(N, "Horde");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
	system("leaks -q Zombie");
	return (0);
}