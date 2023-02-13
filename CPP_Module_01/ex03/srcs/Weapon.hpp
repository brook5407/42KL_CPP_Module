/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:19:06 by brook             #+#    #+#             */
/*   Updated: 2023/02/13 11:10:33 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

private:
	std::string	_type;

public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	const std::string& getType() const;
	void	setType(std::string type);

};

#endif
