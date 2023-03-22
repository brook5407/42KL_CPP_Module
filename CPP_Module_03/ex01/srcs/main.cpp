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

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Boo("Boo");
	Boo.showStatus();
	Boo.attack("enemy");
	Boo.guardGate();
	Boo.showStatus();
	return (0);
}