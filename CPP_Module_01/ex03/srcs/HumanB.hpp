/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:43:41 by brook             #+#    #+#             */
/*   Updated: 2023/02/12 18:43:41 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
	std::string _name;
	Weapon _weapon;

public:
	HumanB();
	HumanB(std::string name);
	~HumanB();
	void	attack(void);
};


#endif
