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

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	std::string name;
	int grade;
	int symbol;
	std::string form_name;
	int g_sign;
	int g_exec;

	while (1)
	{
		std::cout << "---------- Bureaucrat Info----------" << std::endl;
		std::cout << BOLDBLUE"Enter name: "RESET;
		std::cin >> name;
		std::cout << BOLDBLUE"Enter grade: "RESET;
		std::cin >> grade;
		std::cout << "---------- Form Info ----------" << std::endl;
		std::cout << BOLDBLUE"Enter name: "RESET;
		std::cin >> form_name;
		std::cout << BOLDBLUE"Enter grade for sign: "RESET;
		std::cin >> g_sign;
		std::cout << BOLDBLUE"Enter grade for execute: "RESET;
		std::cin >> g_exec;
		try{
			Bureaucrat user(name, grade);
			std::cout << user << std::endl;
			Form form(form_name, g_sign, g_exec);
			std::cout << form;
			try {
				std::cout << BOLDBLUE"Enter 1 to sign: "RESET;
				std::cin >> symbol;
				if (symbol == 1)
					user.signForm(form);
			}
			catch (std::exception & e)
			{
				std::cout << e.what() << std::endl;
				continue;
			}
			std::cout << form;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
	}
}