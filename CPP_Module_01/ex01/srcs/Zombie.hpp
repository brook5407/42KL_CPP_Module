/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:11:20 by brook             #+#    #+#             */
/*   Updated: 2023/02/12 13:11:20 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie {
public:
	Zombie(void);
	~Zombie(void);

	void	announce(void);
	void	set_name(std::string name);

private:
	std::string	_name;
};

Zombie*    zombieHorde( int N, std::string name );

#endif
