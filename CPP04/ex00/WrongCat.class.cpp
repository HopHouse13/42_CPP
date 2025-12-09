/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:27:58 by pbret             #+#    #+#             */
/*   Updated: 2025/12/09 17:43:13 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.class.hpp"

WrongCat::WrongCat(void) : WrongAnimal()/*, _type("WrongCat")*/
{
	this->_type = "WrongCat";
	std::cout << "Default constructor of WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs)
{
	std::cout << "Copy constructor of WrongCat called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	if (this != &rhs)
	{
		std::cout << "Assignement operator overload of WrongCat called" << std::endl;
		WrongAnimal::operator=(rhs);
	}
	return(*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor of WrongCat called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << GREEN << "MIAOUU" << RESET << std::endl;
}

