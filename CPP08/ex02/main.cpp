/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:34:32 by pbret             #+#    #+#             */
/*   Updated: 2026/02/20 19:44:10 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MutantStack.hpp"

int	main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	MutantStack< int > 						DefStack;
	MutantStack< int, std::deque<int> >		DStack;
	MutantStack< int, std::list<int> >		LStack;
	MutantStack< int, std::vector<int> >	VStack;

	for (int i = 0; i < 5; i++)
	{	
		DefStack.push(std::rand() % 10);
		DStack.push(std::rand() % 10);
		LStack.push(std::rand() % 10);
		VStack.push(std::rand() % 10);
	}

	MutantStack<int>::iterator						itDS = DefStack.begin();
	MutantStack<int, std::deque<int> >::iterator	itDS1 = DStack.begin();
	MutantStack<int, std::list<int> >::iterator		itLS = LStack.begin();
	MutantStack<int, std::vector<int> >::iterator	itVS = VStack.begin();

	std::cout	<< std::left << std::setw(10)
				<< std::left << "DefStack" << std::setw(10)
				<< std::left << "DStack" << std::setw(10)
				<< std::left << "LStack" << std::setw(10)
				<< std::left << "VStack" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout	<< std::left << std::setw(10) << *(itDS++)
					<< std::left << std::setw(10) << *(itDS1++)
					<< std::left << std::setw(10) << *(itLS++)
					<< std::left << std::setw(10) << *(itVS++)
					<< std::endl;
	}

	return (0);
}