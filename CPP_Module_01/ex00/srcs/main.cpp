/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:41:32 by brook             #+#    #+#             */
/*   Updated: 2023/02/13 11:08:25 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*foo = newZombie("Foo");
	foo->announce();
	Zombie	*bar = newZombie("Bar");
	bar->announce();

	randomChump("Baz");

	delete bar;
	delete foo;
	system("leaks -q Zombie");
	return (0);
}
