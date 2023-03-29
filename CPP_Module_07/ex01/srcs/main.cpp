/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:47:21 by brook             #+#    #+#             */
/*   Updated: 2023/03/27 16:47:21 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printInt(int const &i) {
	std::cout << i << std::endl;
}

void sumInt(int const &i) {
	static int sum = 0;
	sum += i;
	std::cout << sum << std::endl;
}

void printString(std::string const &s) {
	std::cout << s << std::endl;
}

void sumString(std::string const &s) {
	static std::string sum = "";
	sum += s;
	sum += " ";
	std::cout << sum << std::endl;
}

int main(void) {
	int arrayInt[] = {1, 2, 3, 4, 5};
//	iter(arrayInt, 5, printInt);
	iter(arrayInt, 5, sumInt);
	std::string arrayString[] = {"I", "Love", "42", "Kuala Lumpur", "!" };
//	iter(arrayString, 5, printString);
	iter(arrayString, 5, sumString);
	return 0;
}