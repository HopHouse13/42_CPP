/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:22:43 by pbret             #+#    #+#             */
/*   Updated: 2026/02/21 16:37:41 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

int	main()
{
	Span	container1(100000);

	try
	{	
		container1.addNumber(-1);
		container1.addNumber(0);
		container1.addNumber(42);

		Span	container2(container1);
		Span	container3;
		container3 = container2;

		for (int i = 0; i < 3; i++)	
			std::cout << container3.getList().at(i) << std::endl; // at -> Accède à un élément avec vérification des limites (exception si hors range).

		std::cout << std::endl << "shortest span value: " << container3.shortestSpan() << std::endl;
		std::cout << "longest span value: " << container3.longestSpan() << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int>	containerTmp;

		std::srand(static_cast<int>(time(NULL)));
		for (int i = 0; i < 99997; i++)
			containerTmp.push_back(std::rand() % 1000000);

		std::vector<int>::const_iterator start = containerTmp.begin();
		std::vector<int>::const_iterator end = containerTmp.end();

		container1.generateList(start, end);

		//for (std::vector<int>::const_iterator it = container1.getList().begin(); it != container1.getList().end(); it++)
		//	std::cout << *it << " ";
		
		std::cout << std::endl << "shortest span value: " << container1.shortestSpan() << std::endl;
		std::cout << "longest span value: " << container1.longestSpan() << std::endl << std::endl;
		
		container1.addNumber(0); // on tente de creer un 100 001 eme element -> erreur car le nombre d'element dans le conteneur depasse _n (nombre max)
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}