/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:07:00 by brook             #+#    #+#             */
/*   Updated: 2023/03/27 17:07:00 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750


int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; // exception will be called as the index is out of bounds (negative)
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; // exception will be called as the index is out of bounds (MAX_VAL is the size of the array)
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
//		std::cout << numbers[i] << std::endl;
	}
	delete [] mirror;//

	std::cout << "\n-------------Additional Test-------------" << std::endl;
	Array<char> alpha1(26);
	for (int i = 0 ; i < alpha1.Length() ; i++)
		alpha1[i] = 'A' + i;

	alpha1.print();

	Array<char> alpha2(26);
	for (int i = 0 ; i < alpha2.Length() ; i++)
		alpha2[i] = 'a' + i;

	alpha2.print();
	Array<char>*alpha3 = combine(alpha1, alpha2);
	alpha3->print();
//	system("leaks array");
	return 0;
}