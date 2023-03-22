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

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "---------- User Test ----------" << std::endl;
	std::string name;
	int grade;
	char symbol;
	while (1)
	{
		std::cout << BOLDBLUE"Enter name: "RESET;
		std::cin >> name;
		std::cout << BOLDBLUE"Enter grade: "RESET;
		std::cin >> grade;
		try{
			Bureaucrat user(name, grade);
			std::cout << user;
			try{
				std::cout << BOLDBLUE"Enter +/-: "RESET;
				std::cin >> symbol;
				if (symbol == '+')
					user.incrementGrade();
				if (symbol == '-')
					user.decrementGrade();
			}
			catch (std::exception & e)
			{
				std::cout << e.what() << std::endl;
				return (0);
			}
			std::cout << user;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
			return (0);
		}
	}
}