/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:28:36 by brook             #+#    #+#             */
/*   Updated: 2023/04/01 21:28:36 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &rhs) {
	*this = rhs;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs) {
	if (this != &rhs)
		_num = rhs._num;
	return *this;
}

int RPN::calculate(char op, int a, int b) const {
	if (op == '/' && b == 0)
		throw std::invalid_argument("Error: division by zero");
	if (op == '%' && b == 0)
		throw std::invalid_argument("Error: modulo by zero");
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			throw std::invalid_argument("Error: invalid operator");
	}
}

int RPN::evaluate(const std::string &expr) {
	std::istringstream iss(expr);
	char c;
	while (iss >> c) {
		if (isdigit(c)) {
			_num.push(c - '0');
		} else {
			if (_num.size() < 2)
				throw std::invalid_argument("Error: invalid expression");
			int a = _num.top();
			_num.pop();
			int b = _num.top();
			_num.pop();
			_num.push(calculate(c, b, a));
		}
	}
	if (_num.size() != 1)
		throw std::invalid_argument("Error: invalid expression");
	return _num.top();
}
