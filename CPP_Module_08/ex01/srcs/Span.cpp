/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:13:41 by brook             #+#    #+#             */
/*   Updated: 2023/03/29 21:13:41 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {
}

Span::Span(unsigned int n) {
	this->_n = n;
}

Span::Span(const Span &rhs) {
	*this = rhs;
}

Span::~Span() {
}

Span &Span::operator=(const Span &rhs) {
	this->_n = rhs._n;
	this->_vec = rhs._vec;
	return *this;
}

//std::ostream &operator<<(std::ostream &o, const Span &rhs) {
//	o << "Span: " << rhs._n << std::endl;
//	o << "Vector: " << std::endl;
//	for (unsigned int i = 0; i < rhs._vec.size(); i++) {
//		if (i != 0)
//			o << ", ";
//		o << rhs._vec[i];
//	}
//	o << std::endl;
//	return o;
//}

void Span::addNumber(int n) {
	if (this->_vec.size() < this->_n)
		this->_vec.push_back(n);
	else
		throw std::exception();
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->_vec.size() + std::distance(begin, end) <= this->_n)
		this->_vec.insert(this->_vec.end(), begin, end);
	else
		throw std::exception();
}

int Span::shortestSpan() {
	if (this->_vec.size() < 2)
		throw std::invalid_argument("At least two numbers are required");
	std::vector<int> vec = this->_vec;
	std::sort(vec.begin(), vec.end(), std::greater<int>());
	int min = vec[0] - vec[1];
	for (unsigned int i = 1; i < vec.size() - 1; i++) {
		if (vec[i] - vec[i + 1] < min)
			min = vec[i] - vec[i + 1];
	}
	return min;
}

int Span::longestSpan() {
	if (this->_vec.size() < 2)
		throw std::invalid_argument("At least two numbers are required");
	int min_val = *std::min_element(this->_vec.begin(), this->_vec.end());
	int max_val = *std::max_element(this->_vec.begin(), this->_vec.end());
	return max_val - min_val;
}
