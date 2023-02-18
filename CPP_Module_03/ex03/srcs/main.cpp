/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:47:02 by brook             #+#    #+#             */
/*   Updated: 2023/02/16 11:47:02 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap Boo("Boo");

	Boo.attack("enemy");
	Boo.guardGate();
	Boo.highFivesGuys();
	Boo.whoAmI();
	for (int i = 0; i < 5; i++) {
		Boo.takeDamage(30);
		Boo.beRepaired(1);
	}
	Boo.whoAmI();
	return (0);
}