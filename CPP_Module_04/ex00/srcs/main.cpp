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
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete (i);
	delete (j);
	delete (meta);
	std::cout << std::endl;

	std::cout << "----------Copy Class Test----------" << std::endl;
	const Animal* cat1 = new Cat;
	const Animal* cat2 = cat1;
	cat2->makeSound();
	Animal* dog = new Dog;
	Animal* fakeCat = new Cat;
	*fakeCat = *dog;
	std::cout << fakeCat->getType() << std::endl;
	fakeCat->makeSound();

	std::cout << "----------Wrong Class Test----------" << std::endl;
	const WrongAnimal* w_animal = new WrongAnimal();
	const WrongAnimal* w_cat = new WrongCat();
	std::cout << w_cat->getType() << " " << std::endl;
	w_animal->makeSound(); //will output the cat sound! j->makeSound();
	w_cat->makeSound();
	delete (w_cat);
	delete (w_animal);
	std::cout << std::endl;

	std::cout << "----------Leaks Check----------" << std::endl;
	system("leaks -q animal");
	return 0;
}