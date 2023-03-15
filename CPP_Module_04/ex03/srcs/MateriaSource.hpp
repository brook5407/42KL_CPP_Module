/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:45:01 by brook             #+#    #+#             */
/*   Updated: 2023/03/14 18:45:01 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Character.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *_inventory[MAX_INV];

public:
		MateriaSource();
		MateriaSource(const MateriaSource &materiaSource);
		MateriaSource &operator=(const MateriaSource &materiaSource);
		~MateriaSource();
		AMateria *getAMateria(int idx) const;
		virtual void learnMateria(AMateria *aMateria);
		virtual AMateria* createMateria(std::string const &type);
};

#endif
