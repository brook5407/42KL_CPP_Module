/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:17:52 by brook             #+#    #+#             */
/*   Updated: 2023/03/21 20:17:52 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	Form("Robotomy Request Form", 72, 45){
	this->_target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("Robotomy Request Form", 72, 45){
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : Form(rhs) {
	(*this) = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	this->_target = rhs._target;
	return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!this->getSigned())
		throw Form::GradeNotSignException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw Form::GradeTooLowException();
	srand(time(nullptr));
	int success_rate = rand() % 100 + 1;
	std::cout << BOLDMAGENTA << "Makes some drilling noises..." << std::endl;
	if (success_rate <= 50)
		std::cout << this->_target << " has been robotomized successfully!"RESET << std::endl;
	else
		std::cout << this->_target << " robotomy failed."RESET << std::endl;
}