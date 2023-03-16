/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:15:08 by brook             #+#    #+#             */
/*   Updated: 2023/02/16 15:15:08 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected:
		unsigned int	_init_hp;
		unsigned int	_init_ep;
		unsigned int	_init_ad;
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &fragTrap);
		const FragTrap &operator=(const FragTrap &fragTrap);
		~FragTrap();
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};


#endif
