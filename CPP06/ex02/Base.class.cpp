/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:55:50 by pbret             #+#    #+#             */
/*   Updated: 2026/01/26 18:39:34 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Base.class.hpp"
#include "./empty.class.hpp"

Base::~Base()
{
	std::cout << "Destrucor Base called" << std::endl;
}

Base*	generate()
{
	int	idx = 0;

	idx = (std::rand() % 3);
	switch (idx)
	{
	case 0:
		std::cout << "class A generated" << std::endl;
		return (new A());

	case 1:
		std::cout << "class B generated" << std::endl;
		return (new B());

	case 2:
		std::cout << "class C generated" << std::endl;
		return (new C());

	default:
		std::cout << "error during generation" << std::endl;
		return (NULL);
	}
	return (new Base());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "the type of the pointer is A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "the type of the pointer is B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "the type of the pointer is C" << std::endl;
	else
		std::cout << "error: during identification" << std::endl;
}
void	identify(Base& r)
{
	try
	{
		A& a = dynamic_cast<A&>(r);
		(void)a;
		std::cout << "the type of the reference is A" << std::endl;
		return;
	}
	catch(std::exception& e)
	{}

	try
	{
		B& b = dynamic_cast<B&>(r);
		(void)b;
		std::cout << "the type of the reference is B" << std::endl;
		return;
	}
	catch(std::exception& e)
	{}

	try
	{
		C& c = dynamic_cast<C&>(r);
		(void)c;
		std::cout << "the type of the reference is C" << std::endl;
		return;
	}
	catch(std::exception& e)
	{}
	
	std::cout << "error: during identification" << std::endl;	
}