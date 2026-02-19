/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:22:43 by pbret             #+#    #+#             */
/*   Updated: 2026/02/19 20:17:16 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

int	main()
{
	Span	contener1(100000);

	try
	{	


		contener1.addNumber(-1);
		contener1.addNumber(0);
		contener1.addNumber(42);

		Span	contener2(contener1);
		Span	contener3;
		contener3 = contener2;

		std::cout << "value short:" << contener3.shortestSpan() << std::endl;
		std::cout << "value long:" << contener3.longestSpan() << std::endl;
		for (int i = 0; i < 3; i++)	
			std::cout << contener3.getList().at(i) << std::endl; // at -> Accède à un élément avec vérification des limites (exception si hors range).
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int>	contenerTmp;

		std::srand(static_cast<int>(time(NULL)));
		for (int i = 0; i < 99997; i++)
			contenerTmp.push_back(std::rand() % 1000000);

		std::vector<int>::const_iterator start = contenerTmp.begin();
		std::vector<int>::const_iterator end = contenerTmp.end();

		contener1.generateList(start, end);

		std::cout << "value short:" << contener1.shortestSpan() << std::endl;
		std::cout << "value long:" << contener1.longestSpan() << std::endl;
		
		//for (std::vector<int>::const_iterator it = contener1.getList().begin(); it != contener1.getList().end(); it++)
		//	std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}