/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:47:06 by brook             #+#    #+#             */
/*   Updated: 2023/03/21 20:47:06 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form("Presidential Pardon Form", 25, 5){
	this->_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)  :
	Form("Presidential Pardon Form", 25, 5){
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : Form(rhs) {
	(*this) = rhs;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!this->getSigned())
		throw Form::GradeNotSignException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw Form::GradeTooLowException();
	else
		std::cout << BOLDMAGENTA << this->_target << " has been pardoned by Zafod Beeblebrox"RESET << std::endl;
}