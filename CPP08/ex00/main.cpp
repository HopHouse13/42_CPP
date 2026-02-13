/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:42:27 by pbret             #+#    #+#             */
/*   Updated: 2026/02/13 17:17:58 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./easyfind.hpp"

int	main()
{
	std::list<int>	tab;
	
	tab.push_front(1);
	tab.push_front(2);
	tab.push_back(3);

	std::list<int>::const_iterator	it = tab.begin();
	for (int i = 0; i != 3; i++)
	{
		std::cout << *it << std::endl;
		it++;
	}
	
	try
	{
		easyfind(tab, 2);
		easyfind(tab, 3);
		easyfind(tab, 4);
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

/////////////////////////////////////////

	std::vector<int>	tab1;
	
	tab1.push_back(1);
	tab1.push_back(2);
	tab1.push_back(3);
	tab1.push_back(4);
	
	std::vector<int>::iterator it1 = tab1.begin();

	while (it1 != tab1.end())
	{
		std::cout << *it1 << std::endl;
		it1++;
	}
	try
	{
		easyfind(tab1, 0);
		easyfind(tab1, 4); // Cette instruction n'a jamais été traitée, car une exception a été levée lors de l'instruction précédente.
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}