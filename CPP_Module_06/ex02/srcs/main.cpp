/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:54:30 by brook             #+#    #+#             */
/*   Updated: 2023/03/27 11:54:30 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void) {
	srand(time(NULL));
	Base *random = generate();
	std::cout << "Pointer Identify Result: ";
	identify(random);
	std::cout << "Reference Identify Result: ";
	identify(*random);
	delete random;
}
