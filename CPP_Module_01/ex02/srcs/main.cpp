/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:41:32 by brook             #+#    #+#             */
/*   Updated: 2023/02/20 11:31:26 by chchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string brain("HI THIS IS BRAIN");
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Memory address of string:\t" << &brain << std::endl;
	std::cout << "Memory address of stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Memory address of stringREF:\t" << &stringREF << std::endl;

	std::cout << "Value of string:\t" << brain << std::endl;
	std::cout << "Value of stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "Value of stringREF:\t" << stringREF << std::endl;

	brain = "HI THIS IS NOT BRAIN";

	std::cout << "Memory address of string:\t" << &brain << std::endl;
	std::cout << "Memory address of stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Memory address of stringREF:\t" << &stringREF << std::endl;

	std::cout << "Value of string:\t" << brain << std::endl;
	std::cout << "Value of stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "Value of stringREF:\t" << stringREF << std::endl;

	return (0);
}
