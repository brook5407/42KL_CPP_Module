/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:10:00 by brook             #+#    #+#             */
/*   Updated: 2023/03/12 22:10:00 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "----------Main Project Test----------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete (i);
	delete (j);
	std::cout << std::endl;

	std::cout << "----------Additional Test ----------" << std::endl;
	const Animal	*animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 4; i++)
		delete animals[i];
	std::cout << std::endl;

	std::cout << "---------- Cat Copy Test ----------" << std::endl;
	Cat cat1;
	Cat cat2;

	cat1.setBrainIdea("I am a cat");
	cat2 = cat1;
	cat2.setBrainIdea("MEOW MEOW");
	Cat cat3(cat2);
	cat3.setBrainIdea("I love fish");
	std::cout << std::endl;
	std::cout << "Cat1 idea: " << std::endl;
	std::cout << cat1.getBrain() << std::endl;
	std::cout << "Cat2 idea: " << std::endl;
	std::cout << cat2.getBrain() << std::endl;
	std::cout << "Cat3 idea: " << std::endl;
	std::cout << cat3.getBrain() << std::endl;

	std::cout << "---------- Dog Copy Test ----------" << std::endl;
	Dog dog1;
	Dog dog2;

	dog1.setBrainIdea("I am a Dog");
	dog2 = dog1;
	dog2.setBrainIdea("Woof Woof");
	Dog dog3(dog2);
	dog3.setBrainIdea("I love bone");
	std::cout << std::endl;
	std::cout << "Dog1 idea: " << std::endl;
	std::cout << dog1.getBrain() << std::endl;
	std::cout << "Dog2 idea: " << std::endl;
	std::cout << dog2.getBrain() << std::endl;
	std::cout << "Dog2 idea: " << std::endl;
	std::cout << dog3.getBrain() << std::endl;

	std::cout << "----------Leaks Check----------" << std::endl;
	system("leaks -q animal");
	return 0;
}