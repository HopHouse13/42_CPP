/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:42:27 by pbret             #+#    #+#             */
/*   Updated: 2026/02/06 20:13:45 by pbret            ###   ########.fr       */
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
	std::cout << *it << std::endl;

	std::vector<int>	tab1;
	
	tab1.push_back(42);
	tab1.push_back(10);
	tab1.push_back(19);
	
	std::vector<int>::iterator it1 = tab1.begin();
	std::cout << *it1 << std::endl;
	it1++;
	std::cout << *it1 << std::endl;
	it1++;
	std::cout << *it1 << std::endl;

	it1 = tab1.end();
	std::cout << *it << std::endl; // marrant la valeur de retour de end est tjs 3

	return (0);
}