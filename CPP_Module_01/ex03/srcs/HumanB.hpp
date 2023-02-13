/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:43:41 by brook             #+#    #+#             */
/*   Updated: 2023/02/13 11:10:12 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

private:
	std::string _name;
	Weapon *_weapon;

public:
	HumanB(std::string name);
	~HumanB();
	void	attack(void);
	void	setWeapon(Weapon& weapon);

};


#endif
