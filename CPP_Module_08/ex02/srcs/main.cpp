/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:27:47 by brook             #+#    #+#             */
/*   Updated: 2023/03/30 17:27:47 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void) {
	MutantStack<int>	mstack;

	mstack.push(5); // add 5 to stack
	mstack.push(17); // add 17 to stack

	std::cout << mstack.top() << std::endl; // return top of stack (17)

	mstack.pop(); // remove top of stack

	std::cout << mstack.size() << std::endl; // return size of stack (1)

	mstack.push(3); // add 3 to stack
	mstack.push(5); // add 5 to stack
	mstack.push(737); // add 737 to stack
	mstack.push(0); // add 0 to stack

	MutantStack<int>::iterator it = mstack.begin(); // return iterator to top of stack (0)
	MutantStack<int>::iterator ite = mstack.end(); // return iterator to bottom of stack (5)

	++it; // point to next element in stack (737)
	--it; // point to previous element in stack (0)
	while (it != ite)
	{
		std::cout << *it << std::endl; // print stack from top to bottom (0, 737, 5, 3, 5)
		++it; // point to next element in stack
	}
	std::stack<int> s(mstack); // create copy of stack
	return 0;
}
