/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:51:49 by pbret             #+#    #+#             */
/*   Updated: 2025/12/05 18:58:50 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main()
{
	std::cout << "///Animal///" << std::endl << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();

	delete(meta);
	delete(j);
	delete(i);

	std::cout << std::endl << "///WrongAnimal///" << std::endl << std::endl;
	const WrongAnimal* animal = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();

	std::cout << animal->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl; // pas sur de la pertinence 
	animal->makeSound();
	cat->makeSound();

	delete(animal);
	delete(cat);

	return 0;
}