/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:16:37 by brook             #+#    #+#             */
/*   Updated: 2023/04/03 20:16:37 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>
#include <cmath>

class PmergeMe {
private:
	std::deque<int> _deque;
	std::list<int> _list;
public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe &rhs);
	virtual ~PmergeMe();
	PmergeMe &operator=(const PmergeMe &rhs);

	void dequeSort();
	void listSort();
	void printDeque();
	void printList();
};


#endif
