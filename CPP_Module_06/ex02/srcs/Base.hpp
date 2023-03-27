/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:35:48 by brook             #+#    #+#             */
/*   Updated: 2023/03/27 11:35:48 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base {
public:
	virtual ~Base() {};
	virtual void print() { std::cout << "Base" << std::endl; }
};

class A : public Base {
public:
	void print() { std::cout << "A" << std::endl; };
};

class B : public Base {
public:
	void print() { std::cout << "B" << std::endl; };
};

class C : public Base {
public:
	void print() { std::cout << "C" << std::endl; };
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
