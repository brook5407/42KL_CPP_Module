/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:32:12 by brook             #+#    #+#             */
/*   Updated: 2023/03/21 09:32:12 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default") , _gradeToSign(150), _gradeToExec(150){
	this->_signed = false;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign < 1  || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150  || gradeToExec > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

Form::Form(const Form &rhs) : _name(rhs._name), _gradeToSign(rhs._gradeToSign), _gradeToExec(rhs._gradeToExec) {
	this->_signed = rhs._signed;
	*this = rhs;
}

Form &Form::operator=(const Form &rhs) {
	if (this != &rhs)
		this->_signed = rhs.getSigned();
	return (*this);
}

Form::~Form() {}

std::string Form::getName() const {
	return (this->_name);
}

int Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int Form::getGradeToExec() const {
	return (this->_gradeToExec);
}

bool Form::getSigned() const {
	return (this->_signed);
}

void Form::beSign(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return (BOLDRED"Form grade out of range: Grade too high"RESET);
}

const char *Form::GradeTooLowException::what() const throw() {
	return (BOLDRED"Form grade out of range: Grade too low"RESET);
}

std::ostream& operator<<(std::ostream& os, const Form& rhs) {
	os << BOLDGREEN;
	os << "Form name: " << rhs.getName() << std::endl;
	os << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	os << "Grade to execute: " << rhs.getGradeToExec() << std::endl;
	os << "Signed: " << rhs.getSigned() << std::endl;
	return (os);
}
