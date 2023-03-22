/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:22:49 by brook             #+#    #+#             */
/*   Updated: 2023/03/22 11:22:49 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &rhs) {
	(*this) = rhs;
}

Intern &Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return (*this);
}

Intern::~Intern() {}

const char *Intern::InvalidFormNameException::what() const throw() {
	return ("Error: Invalid form name provided");
}

Form *makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form *makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form *makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeForm(const std::string formName, const std::string target) {
	typedef Form *(*funcPtr)(std::string target);
	std::string formNameArray[3]
		= {"Presidential Pardon Form", "Robotomy Request Form", "Shrubbery Creation Form"};
	funcPtr funcArray[3]
		= {&makePresidentialPardonForm, &makeRobotomyRequestForm, &makeShrubberyCreationForm};
	for (int i = 0; i < 3; i++) {
		if (formNameArray[i] == formName) {
			std::cout << BOLDMAGENTA << "Intern creates " << formName << RESET << std::endl;
			return (funcArray[i])(target);
		}
	}
	throw Intern::InvalidFormNameException();
	return NULL;
}