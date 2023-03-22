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
#include "Intern.hpp"

int main(void)
{
	while (1) {
		try {
			Intern intern;
			std::string formName;
			std::string target;

			std::cout << "Enter Form Name: ";
			std::getline(std::cin, formName);
			std::cout << "Enter Target Name: ";
			std::getline(std::cin, target);
			Form *form = intern.makeForm(formName, target);
			std::cout << *form << std::endl;
			delete form;
		}
		catch (const std::exception &e) {
			std::cerr << BOLDRED << e.what() << RESET << std::endl;
		}
	}
}