/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:22:43 by pbret             #+#    #+#             */
/*   Updated: 2026/02/18 18:49:37 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

int	main()
{
	Span	test(3);

	test.addNumber(10);
	test.addNumber(4);
	test.addNumber(1999);

	Span test1 = test;
	try
	{
		std::cout << "value short:" << test1.shortestSpan() << std::endl;
		for (int i = 0; i < 3; i++)	
			std::cout << test1.getList().at(i) << std::endl; // at -> Accède à un élément avec vérification des limites (exception si hors range).
	} // j'ai fais une getter sauf que c'est plus simple d'utiliser un iterator
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/////////////////

	try
	{
		for (std::vector<int>::const_iterator it = test.getList().begin(); it != test.getList().end(); it++)
			std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	
	return (0);
}