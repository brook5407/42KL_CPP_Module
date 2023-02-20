/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:52:25 by brook             #+#    #+#             */
/*   Updated: 2023/02/20 11:45:25 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
	Weapon club1 = Weapon("first club");
	HumanA bob("Bob", club1);
	bob.attack();
	club1.setType("some other type of club");
	bob.attack();

	Weapon club2 = Weapon("second club");
	HumanB jim("Jim");
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("some other type of club");
	jim.attack();
	return (0);
}
