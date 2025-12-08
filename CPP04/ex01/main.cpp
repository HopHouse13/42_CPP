/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:51:49 by pbret             #+#    #+#             */
/*   Updated: 2025/12/08 20:02:53 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* k = new Cat();
	delete j;//should not create a leak
	delete k;

	Animal*	tab[4];
	
	int	i = -1;
	while (++i < 4)
	{
		if (i%2 == 0)
			tab[i] = new Cat();
		else
			tab[i] = new Dog();
		std::cout << CYAN << "Animal " << tab[i]->getType() << " at index " << i << " allocated" << RESET << std::endl;
	}

	//while(i-- != 0)
	//{
	//	if (i%2 == 0)
	//		while (tab[i].)
	//			tab[i].->_brain.setIdea()
	//}
	
	while(i-- != 0)
	{
		delete (tab[i]);
		std::cout << YELLOW << "Animal at index " << i << " has been deleted" << RESET << std::endl;
	}
	return (0);
}