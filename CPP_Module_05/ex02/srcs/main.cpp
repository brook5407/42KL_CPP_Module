/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:43:04 by brook             #+#    #+#             */
/*   Updated: 2023/03/20 22:43:04 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	while (1) {
		try {
			std::string name;
			int grade;
			Form *form[3] = {new PresidentialPardonForm, new RobotomyRequestForm, new ShrubberyCreationForm};

			std::cout << "----------------Create Bureaucrat----------------" << std::endl;
			std::cout << BOLDBLUE"Enter name: "RESET;
			std::cin >> name;
			std::cout << BOLDBLUE"Enter grade: "RESET;
			std::cin >> grade;
			Bureaucrat *bureaucrat = new Bureaucrat(name, grade);
			std::cout << *bureaucrat << std::endl;

			std::cout << "----------------Sign Form Section----------------" << std::endl;
			int i;
			std::cout << BOLDBLUE"Enter 0 for Presidential Pardon Form" << std::endl;
			std::cout << "Enter 1 for Robotomy Request Form" << std::endl;
			std::cout << "Enter 2 for Shrubbery Creation Form" << std::endl;
			std::cout << "Enter: "RESET;
			std::cin >> i;
			if (i >= 0 && i < 3)
			bureaucrat->signForm(*form[i]);
			std::cout << *form[i] << std::endl;
			std::cout << "----------------Execute Form Section----------------" << std::endl;
			if (i >= 0 && i < 3)
				bureaucrat->executeForm(*form[i]);
			delete bureaucrat;
			for (int j = 0; j < 3; j++) {
				delete form[j];
			}
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
