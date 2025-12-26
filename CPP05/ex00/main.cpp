/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:56:19 by pbret             #+#    #+#             */
/*   Updated: 2025/12/26 12:29:44 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << YELLOW << "/// Invalid cases ///" << RESET << std::endl;
	try
	{
		Bureaucrat	Adri("Adri", 0); // l'objet n'est pas construit car le constructeur throw donc l'objet n'est pas instancie.
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}

	try
	{
		Bureaucrat	Paul("Paul", 151);
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}

	try
	{
		Bureaucrat	Alix("Alix", 150); // l'objet est construit, grade 150 est valide
		Alix.decrementGrade(); // le grade decremente -> 151 -> invalide -> throw
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}

	try
	{
		Bureaucrat Max ("Max", 1);
		Max.incrementGrade();
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}

	std::cout << YELLOW << "/// Valid cases ///" << RESET << std::endl;
	try
	{
		Bureaucrat Flo("Flo", 42);
		std::cout << Flo;
		Flo.incrementGrade();
		std::cout << Flo;
		Flo.decrementGrade();
		std::cout << Flo;
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}
	return (0);
}
