/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:56:19 by pbret             #+#    #+#             */
/*   Updated: 2025/12/16 21:43:26 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
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
		std::cout << Alix;
		Alix.decrementGrade(); // le grade decremente -> 151 -> invalide -> throw
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}
	
	Bureaucrat* Max = new Bureaucrat("Max", 1); // try un scope propre. Une variable est declaree a l'interieur est supp a la fin du try
	try
	{
		std::cout << *Max;
		Max->incrementGrade();
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}
	std::cout << *Max;
	delete (Max);

	Bureaucrat Flo("Flo", 42);
	try
	{
		std::cout << Flo;
		
		Form	F1("F1", 41, 1);
		std::cout << F1;
		Flo.signForm(F1);
		std::cout << F1;
		Flo.incrementGrade();
		std::cout << Flo;
		Flo.signForm(F1);
		std::cout << F1;
	}
	catch (std::exception& excep) // pourquoi ca catch les throw de Form et de Bureaucrat??
	{
		std::cerr << excep.what();
	}
	return (0);
}
