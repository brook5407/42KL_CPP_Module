/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:35:50 by brook             #+#    #+#             */
/*   Updated: 2023/03/13 23:35:50 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria{
	public:
		Ice();
		Ice(const Ice &ice);
		Ice &operator=(const Ice &ice);
		virtual ~Ice();
		AMateria*	clone() const;
		void	use(ICharacter &target);
};


#endif
