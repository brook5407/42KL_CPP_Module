/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:04:14 by brook             #+#    #+#             */
/*   Updated: 2023/03/12 22:04:14 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_CAT_HPP
#define CPP_CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &cat);
		Cat &operator=(const Cat &cat);
		virtual ~Cat();
		void makeSound() const;
		const Brain& getBrain() const;
		void setBrainIdea(std::string newIdea);
	private:
		Brain *brain;
};

#endif
