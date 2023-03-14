/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:56:00 by brook             #+#    #+#             */
/*   Updated: 2023/03/12 23:56:00 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[Brain] Default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain) {
	std::cout << "[Brain] Copy constructor called" << std::endl;
	(*this) = brain;
}

Brain &Brain::operator=(const Brain &brain) {
	std::cout << "[Brain] Copy assignment operator overload constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << "[Brain] Destructor called" << std::endl;
}

void Brain::setIdea(std::string newIdea) {
	for (int i = 0; i < 100; i++) {
		if (this->ideas[i].empty()) {
			this->ideas[i] = newIdea;
			break;
		}
	}
}

std::ostream &operator<<(std::ostream &output, const Brain &brain) {
	output << "[Brain] " << std::endl;
	for (int i = 0; i < 100; i++) {
		if (!brain.ideas[i].empty()) {
			output << i + 1 << ".\t" << brain.ideas[i] << std::endl;
		}
	}
	return output;
}