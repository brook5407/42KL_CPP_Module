/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:02:02 by brook             #+#    #+#             */
/*   Updated: 2023/03/22 09:02:02 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Form;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern {
	public:
		Intern();
		Intern(const Intern &rhs);
		Intern &operator=(const Intern &rhs);
		~Intern();
		Form *makeForm(const std::string formName, const std::string target);

		class InvalidFormNameException : public std::exception{
			public:
				const char * what() const throw();
		};
};

#endif
