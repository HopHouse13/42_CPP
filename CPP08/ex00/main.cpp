/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:42:27 by pbret             #+#    #+#             */
/*   Updated: 2026/02/10 15:21:07 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./easyfind.hpp"

int	main()
{
	std::list<int>	tab;
	
	tab.push_front(42);
	tab.push_front(10);
	tab.push_back(19);
	
	std::list<int>::iterator it = tab.begin();
	std::cout << *it << std::endl;
	it++;
	std::cout << *it << std::endl;
	it++;
	std::cout << *it << std::endl;

	it = tab.end();
	//std::cout << *it << std::endl; // il affiche tjs 3 alors que cela indique la fin de la liste
/////////////////////////////////////////
	std::cout << std::endl;
	std::vector<int>	tab1;
	
	tab1.push_back(1);
	tab1.push_back(2);
	tab1.push_back(3);
	
	std::vector<int>::iterator it1 = tab1.begin();
	std::cout << *it1 << std::endl;
	it1++;
	std::cout << *it1 << std::endl;
	it1++;
	std::cout << *it1 << std::endl;

	it1 = tab1.begin();
	while (it1 != tab1.end())
	{
		*it1 += 1;
		it1++;
	}
	for (std::vector<int>::const_iterator it2 = tab1.begin(); it2 != tab1.end(); it2++)
		std::cout << *it2 << std::endl;

	//it1 = tab1.end(); // represente la fin de la liste (il n a pas de valeur) c'est comme '\0' dnas une string
	//std::cout << *it << std::endl; // marrant la valeur de retour de end est tjs 3

	return (0);
}