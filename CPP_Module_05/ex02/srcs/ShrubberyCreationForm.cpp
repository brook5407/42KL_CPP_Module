/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:29:07 by brook             #+#    #+#             */
/*   Updated: 2023/03/21 14:29:07 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("Shrubbery Creation Form", 145, 137) {
	this->_target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("Shrubbery Creation Form", 145, 137) {
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : Form(rhs){
	(*this) = rhs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const{
	return (this->_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->getSigned())
		throw Form::GradeNotSignException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw Form::GradeTooLowException();
	std::ofstream outfile(this->_target + "_shrubbery");
	outfile << "                                              .\n";
	outfile << "                                   .         ;\n";
	outfile << "      .              .              ;%     ;;\n";
	outfile << "        ,           ,                :;%  %;\n";
	outfile << "         :         ;                   :;%;'     .,\n";
	outfile << ",.        %;     %;            ;        %;'    ,;\n";
	outfile << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	outfile << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
	outfile << "    ;%;      %;        ;%;        % ;%;  ,%;'\n";
	outfile << "     `%;.     ;%;     %;'         `;%%;.%;'\n";
	outfile << "      `:;%.    ;%%. %@;        %; ;@%;%'\n";
	outfile << "         `:%;.  :;bd%;          %;@%;'\n";
	outfile << "           `@%:.  :;%.         ;@@%;'\n";
	outfile << "             `@%.  `;@%.      ;@@%;\n";
	outfile << "               `@%%. `@%%    ;@@%;\n";
	outfile << "                 ;@%. :@%%  %@@%;\n";
	outfile << "                   %@bd%%%bd%%:;\n";
	outfile << "                     #@%%%%%:;;\n";
	outfile << "                     %@@%%%::;\n";
	outfile << "                     %@@@%(o);  . '\n";
	outfile << "                     %@@@o%;:(.,'\n";
	outfile << "                 `.. %@@@o%::;\n";
	outfile << "                    `)@@@o%::;\n";
	outfile << "                     %@@(o)::;\n";
	outfile << "                    .%@@@@%::;\n";
	outfile << "                    ;%@@@@%::;.\n";
	outfile << "                   ;%@@@@%%:;;;.\n";
	outfile << "               ...;%@@@@@%%:;;;;,..\n";
	outfile.close();
	std::cout << BOLDMAGENTA << this->_target << "_shrubbery file has been created."RESET << std::endl;
}