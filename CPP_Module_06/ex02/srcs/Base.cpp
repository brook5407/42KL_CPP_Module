/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:36:09 by brook             #+#    #+#             */
/*   Updated: 2023/03/27 11:36:09 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void) {
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		p->print();
	else if (dynamic_cast<B*>(p))
		p->print();
	else if (dynamic_cast<C*>(p))
		p->print();
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		a.print();
	} catch (std::exception &e) {}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		b.print();
	} catch (std::exception &e) {}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		c.print();
	} catch (std::exception &e) {}
}