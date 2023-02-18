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

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Boo("Boo");

	Boo.attack("enemy");
	for (int i = 0; i < 5; i++) {
		Boo.takeDamage(3);
		Boo.beRepaired(1);
	}
	return (0);
}