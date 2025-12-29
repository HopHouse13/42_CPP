/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:56:19 by pbret             #+#    #+#             */
/*   Updated: 2025/12/29 14:43:48 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << YELLOW << "/// Invalid cases ///" << RESET << std::endl;
	try
	{
		Form	f1("f1", 0, 1); // tentative de creation de f1 avec une value invalid (0 en grade de signature)
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}

	try
	{
		Form	f2("f2", 151, 1);
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}

	try
	{
		Form	f3("f3", 1, 0);  // tentative de creation de f3 avec une value invalid (0 en grade d'execution)
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}

	try
	{
		Form	f4("f4", 1, 151);
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}

	try
	{
		Bureaucrat dude("dude", 150);
		Form	f5("f5", 1, 1);
		dude.signForm(f5);
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}

	std::cout << YELLOW << "/// Valid cases ///" << RESET << std::endl;
	try
	{
		Bureaucrat	Flo("Flo", 42);
		Form		f6("f6", 42, 1);
		std::cout << Flo << f6 ;
		Flo.signForm(f6);
		std::cout << f6;
		
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}
	return (0);
}
