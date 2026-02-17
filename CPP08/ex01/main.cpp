/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:22:43 by pbret             #+#    #+#             */
/*   Updated: 2026/02/17 20:06:33 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

int	main()
{
	Span	test(3);

	test.addNumber(1);
	test.addNumber(2);
	test.addNumber(3);

	try
	{
		for (int i = 0; i < 4; i++)	
			std::cout << test.getList().at(i) << std::endl; // at -> Accède à un élément avec vérification des limites (exception si hors range).
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