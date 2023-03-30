/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:21:54 by brook             #+#    #+#             */
/*   Updated: 2023/03/30 17:21:54 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &rhs) : std::stack<T>(rhs) {}
	virtual ~MutantStack() {}
	MutantStack &operator=(const MutantStack &rhs) {
		std::stack<T>::operator=(rhs);
		return *this;
	}
	typedef typename std::deque<T>::iterator iterator;
	iterator begin() { return std::begin(std::stack<T>::c); }
	iterator end() { return std::end(std::stack<T>::c); }
	typedef typename std::deque<T>::const_iterator const_iterator;
	const_iterator begin() const { return std::begin(std::stack<T>::c); }
	const_iterator end() const { return std::end(std::stack<T>::c); }
};

#endif
