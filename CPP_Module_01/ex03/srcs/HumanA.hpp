/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:35:06 by brook             #+#    #+#             */
/*   Updated: 2023/02/12 18:35:06 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
	std::string	_name;
	Weapon& _weapon;
public:
	HumanA(Weapon weapon);
	HumanA(Weapon weapon, std::string name);
	~HumanA();
	void	attack(void);
};


#endif
