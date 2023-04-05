/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:26:43 by brook             #+#    #+#             */
/*   Updated: 2023/04/01 21:26:43 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

class RPN {
private:
	std::stack<int> _num;
public:
	RPN();
	RPN(const RPN &rhs);
	virtual ~RPN();
	RPN &operator=(const RPN &rhs);

	int calculate(char op, int a, int b) const;
	int evaluate(const std::string &expr);
};


#endif
