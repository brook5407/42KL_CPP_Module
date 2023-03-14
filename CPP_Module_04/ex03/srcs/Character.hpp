/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:30:47 by brook             #+#    #+#             */
/*   Updated: 2023/03/14 10:30:47 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#define MAX_INV 4

class AMateria;

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria _inventory[MAX_INV];

	public:
		Character();
		Character(const std::string &name);
		Character(const Character &character);
		Character &operator=(const Character &character);
		virtual ~Character();
		virtual std::string const &getName();
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
