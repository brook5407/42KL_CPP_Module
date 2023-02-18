/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:51:57 by brook             #+#    #+#             */
/*   Updated: 2023/02/16 10:51:57 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_CLAPTRAP_HPP
#define CPP_CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
private:
	std::string		_name;
	unsigned int	_hp;
	unsigned int	_ep;
	unsigned int	_ad;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap &operator=(const ClapTrap &clapTrap);
	~ClapTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif //CPP_CLAPTRAP_HPP
