/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:51:35 by brook             #+#    #+#             */
/*   Updated: 2023/03/15 10:51:35 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void ft_tests()
{
	// Constructors
	std::cout << std::endl;
	std::cout << "CONSTRUCTORS:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character* me = new Character("me");
	std::cout << std::endl;

	// Create Materia
	std::cout << "CREATE MATERIA:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	AMateria	*tmp;
	AMateria	*tmp1;
	AMateria	*tmp2;
	AMateria	*tmp3;
	AMateria	*tmp4;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	if (tmp != NULL)
		std::cout << "tmp: " << tmp->getType() << std::endl;
	std::cout << "me equip <tmp>" << std::endl;
	std::cout << *me << std::endl;
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);
	if (tmp != NULL)
		std::cout << "tmp1: " << tmp1->getType() << std::endl;
	std::cout << "me equip <tmp1>" << std::endl;
	std::cout << *me << std::endl;
	tmp = src->createMateria("fire"); //NULL
	me->equip(tmp);
	if (tmp != NULL)
		std::cout << "tmp: " << tmp->getType() << std::endl;
	std::cout << std::endl;

	// Use on a new character
	std::cout << "USE ON A NEW CHARACTER:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	me->use(2, *bob); // Use an empty / non existing slot in inventory
	me->use(-4, *bob);
	me->use(18, *bob);
	std::cout << std::endl;

	// Deep copy character
	std::cout << "DEEP COPY CHARACTER:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	Character	*charles = new Character("Charles");
	tmp2 = src->createMateria("cure");
	charles->equip(tmp2);
	tmp3 = src->createMateria("ice");
	charles->equip(tmp3);
	tmp = src->createMateria("earth");
	charles->equip(tmp);
	std::cout << *charles << std::endl;
	Character	*charles_copy = new Character(*charles);
	std::cout << *charles_copy;
	std::cout << std::endl;

	// Deep copy vs its source character
	std::cout << "DEEP COPY VS SOURCE:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Unequip index 0 in charles's inventory" << std::endl;
	charles->unequip(0); // this shows that they have different materia pointers equipped
	std::cout << *charles << std::endl;
	std::cout << "Unequip index 1 in charles_copy's inventory" << std::endl;
	tmp4 = charles_copy->getAMateria(1);
	charles_copy->unequip(1); //this will produce a leak if we don't store the address somewhere else before
	std::cout << *charles_copy << std::endl;
	delete tmp4;
	std::cout << "Add 1 cure and 1 ice in charles copy" << std::endl;
	tmp = src->createMateria("cure");
	charles_copy->equip(tmp);
	tmp = src->createMateria("ice");
	charles_copy->equip(tmp);
	std::cout << *charles_copy;
	std::cout << std::endl;

	std::cout << "Charles use slot 0" << std::endl;
	charles->use(0, *bob);
	std::cout << "Charles use slot 1" << std::endl;
	charles->use(1, *bob);
	std::cout << "Charles use slot 2" << std::endl;
	charles->use(2, *bob);
	std::cout << "Charles use slot 3" << std::endl;
	charles->use(3, *bob);
	std::cout << std::endl;
	std::cout << "Charles_copy use slot 0" << std::endl;
	charles_copy->use(0, *bob);
	std::cout << "Charles_copy use slot 1" << std::endl;
	charles_copy->use(1, *bob);
	std::cout << "Charles_copy use slot 2" << std::endl;
	charles_copy->use(2, *bob);
	std::cout << "Charles_copy use slot 3" << std::endl;
	charles_copy->use(3, *bob);
	std::cout << std::endl;

	// Unequip tests:
	std::cout << "UNEQUIP:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << *me << std::endl;
	std::cout << "me unequip slot -1" << std::endl;
	me->unequip(-1); // unequip an empty / non existing slot in inventory
	std::cout << "me unequip slot 18" << std::endl;
	me->unequip(18);
	std::cout << "me unequip slot 3" << std::endl;
	me->unequip(3);
	std::cout << std::endl;
	std::cout << "me use slot 1" << std::endl;
	me->use(1, *charles);
	std::cout << "me unequip slot 1" << std::endl;
	me->unequip(1); // Unequip a valid slot in inventory (cure unequipped)
	std::cout << "me use slot 1" << std::endl;
	me->use(1, *charles); // try to use it
	std::cout << *me;
	std::cout << std::endl;

	// Destructors
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	delete bob;
	delete me;
	delete src;
	delete charles;
	delete charles_copy;
	delete tmp1;
	delete tmp2;
	std::cout << std::endl;
}

void ft_main_test()
{
	std::cout << std::endl << "----------Main Test----------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int main()
{
	ft_tests();
//	ft_main_test();
	std::cout << std::endl << "----------Leaks Check----------" << std::endl;
	system("leaks -q a.out");

	return 0;
}