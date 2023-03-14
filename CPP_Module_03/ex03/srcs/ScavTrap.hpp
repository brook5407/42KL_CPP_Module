/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:54:05 by brook             #+#    #+#             */
/*   Updated: 2023/02/16 12:54:05 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected:
		unsigned int	_init_hp;
		unsigned int	_init_ep;
		unsigned int	_init_ad;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scavTrap);
		const ScavTrap &operator=(const ScavTrap &scavTrap);
		~ScavTrap();
		void	guardGate();
};

#endif
