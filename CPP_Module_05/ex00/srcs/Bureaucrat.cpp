/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:31:42 by brook             #+#    #+#             */
/*   Updated: 2023/03/20 15:31:42 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default") {
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) {
	(*this) = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return (BOLDRED"Grade out of range: Grade too high"RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return (BOLDRED"Grade out of range: Grade too low"RESET);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
	os << BOLDGREEN << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << RESET << std::endl;
	return (os);
}
