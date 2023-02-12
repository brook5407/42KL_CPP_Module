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

int	main(void)
{
	Zombie	*foo = newZombie("Foo");
	foo->announce();
	Zombie	*bar = newZombie("Bar");
	bar->announce();

	randomChump("Baz");

	delete bar;
	delete foo;
	return (0);
}