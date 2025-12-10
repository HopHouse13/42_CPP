/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:51:49 by pbret             #+#    #+#             */
/*   Updated: 2025/12/10 12:34:36 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main()
{
	std::cout << std::endl << GREEN << "/// TEST SUBJET ///" << RESET << std::endl << std::endl;

	const AAnimal* j = new Dog();
	const AAnimal* k = new Cat();
	delete j;//should not create a leak
	delete k;

	std::cout << std::endl << GREEN << "/// INIT TABLE ///" << RESET << std::endl << std::endl;

	static int	nbAnimals = 4;
	AAnimal*	tab[nbAnimals];
	int			i = -1;

	while (++i < nbAnimals)
	{
		if (i%2 == 0)
			tab[i] = new Cat();
			
		else
			tab[i] = new Dog();
			
		std::cout << CYAN << "Animal " << tab[i]->getType() << " at index " << i << " allocated" << RESET << std::endl;
	}

	while(i-- != 0)
		std::cout << tab[i]->getType() << std::endl;
	
	while(++i < nbAnimals)
	{
		delete (tab[i]);
		std::cout << YELLOW << "Animal at index " << i << " has been deleted" << RESET << std::endl;
	}

	std::cout << std::endl << GREEN << "/// DEEP COPY BY ASSIGNMENT OPERATOR ///" << RESET << std::endl << std::endl;

	Cat*	c1 = new Cat();
	Cat*	c2 = new Cat();
	
	i = -1;
	while(++i < 100)
	{
		c1->setIdea(i, "Humans are our slaves!😼");
		c2->setIdea(i, "GIVE ME SOME CAT FOOD!🙀");
	}
	
	i = -1;
	while(++i < 5)
		std::cout	<< "c1 idea N" << i << " : " << c1->getIdea(i) << "\t\tc2 idea N" << i << " : " << c2->getIdea(i) << std::endl;
	
	*c1 = *c2; // operateur de surcharge d'affectation

	i = -1;
	while(++i < 5)
		std::cout	<< "c1 idea N" << i << " : " << c1->getIdea(i) << "\t\tc2 idea N" << i << " : " << c2->getIdea(i) << std::endl;

	std::cout << "c1 address brain: " << c1->getAddressBrain() << std::endl;
	std::cout << "c2 address brain: " << c2->getAddressBrain() << std::endl;

	delete(c1);
	delete(c2);

	std::cout << std::endl << GREEN << "/// DEEP COPY BY COPY CONSTRUCTOR ///" << RESET << std::endl << std::endl;

	Dog	d1;
	Dog	d2(d1); // constructeur par copie

	std::cout << "d1 address brain: " << d1.getAddressBrain() << std::endl;
	std::cout << "d2 address brain: " << d2.getAddressBrain() << std::endl;

	d1.setIdea(0, "no idea 🐶");
	d2.setIdea(0, "... 🐶");

	std::cout	<< "d1 idea N" << 0 << " : " << d1.getIdea(0) 
				<< "\t\td2 idea N" << 0 << " : " << d2.getIdea(0) << std::endl;

	//std::cout << std::endl << GREEN << "/// ABSTRACT CLASS ///" << RESET << std::endl << std::endl;

	//AAnimal		A1;
	//AAnimal*	A2 = new AAnimal();

	return (0);
}