/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:10:44 by brook             #+#    #+#             */
/*   Updated: 2023/03/29 21:10:44 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

class Span {
private:
	unsigned int _n;
	std::vector<int> _vec;
public:
	Span();
	Span(unsigned int n);
	Span(Span const & rhs);
	~Span();
	Span & operator=(Span const & rhs);
	void addNumber(int n);
	int shortestSpan();
	int longestSpan();
//	friend std::ostream & operator<<(std::ostream & o, Span const & rhs);
};


#endif
