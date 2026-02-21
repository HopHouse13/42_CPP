/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:34:32 by pbret             #+#    #+#             */
/*   Updated: 2026/02/21 14:31:33 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MutantStack.hpp"

int	main()
{
	/// CONTAINER INITIALIZATION ///

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	MutantStack< int > 						DefStack;
	MutantStack< int, std::deque<int> >		DStack;
	MutantStack< int, std::list<int> >		LStack;
	MutantStack< int, std::vector<int> >	VStack;

	/// VALUE ASSIGNMENT ///

	for (int i = 0; i < 5; i++)
	{	
		DefStack.push(std::rand() % 9);
		DStack.push(std::rand() % 9);
		LStack.push(std::rand() % 9);
		VStack.push(std::rand() % 9);
	}

	/// ITERATOR INITIALIZATION ///

	MutantStack<int>::iterator						itDS = DefStack.begin();
	MutantStack<int, std::deque<int> >::iterator	itDS1 = DStack.begin();
	MutantStack<int, std::list<int> >::iterator		itLS = LStack.begin();
	MutantStack<int, std::vector<int> >::iterator	itVS = VStack.begin();

	/// DISPLAY CONTAINERS ///
	
	std::cout 	<< std::endl << "ORIGINAL CONTAINERS" << std::endl
				<< std::left << std::setw(10) << "DefStack"
				<< std::left << std::setw(10) << "DStack"
				<< std::left << std::setw(10) << "LStack"
				<< std::left << std::setw(10) << "VStack" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout	<< std::left << std::setw(10) << *(itDS++) // tmp = itDS; ++itDS; affiche tmp;
					<< std::left << std::setw(10) << *(itDS1++)
					<< std::left << std::setw(10) << *(itLS++)
					<< std::left << std::setw(10) << *(itVS++)
					<< std::endl;
	}

	/// REMOVE TWO ELEMENTS ///

	for (int i = 0; i < 2; i++)
	{
		DefStack.pop();
		DStack.pop();
		LStack.pop();
		VStack.pop();
	}

	/// DISPLAY CONTAINERS ///

	itDS = DefStack.begin();
	itDS1 = DStack.begin();
	itLS = LStack.begin();
	itVS = VStack.begin();

	std::cout 	<< std::endl << "CONTAINERS AFTER REMOVING 2 VALUES" << std::endl
				<< std::left << std::setw(10) << "DefStack"
				<< std::left << std::setw(10) << "DStack"
				<< std::left << std::setw(10) << "LStack"
				<< std::left << std::setw(10) << "VStack" << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout	<< std::left << std::setw(10) << *(itDS++)
					<< std::left << std::setw(10) << *(itDS1++)
					<< std::left << std::setw(10) << *(itLS++)
					<< std::left << std::setw(10) << *(itVS++)
					<< std::endl;
	}

	/// VALUE INCREMENT ///

	itDS = DefStack.begin();
	itDS1 = DStack.begin();
	itLS = LStack.begin();
	itVS = VStack.begin();

	for (int i = 0; i < 3; i++)
	{
		*(itDS++) += 1;
		*(itDS1++) += 1;
		*(itLS++) += 1;
		*(itVS++) += 1;
	}

	/// DISPLAY CONTAINERS ///

	itDS = DefStack.begin();
	itDS1 = DStack.begin();
	itLS = LStack.begin();
	itVS = VStack.begin();

	std::cout 	<< std::endl << "CONTAINERS WITH INCREMENTED VALUES" << std::endl
				<< std::left << std::setw(10) << "DefStack"
				<< std::left << std::setw(10) << "DStack"
				<< std::left << std::setw(10) << "LStack"
				<< std::left << std::setw(10) << "VStack" << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout	<< std::left << std::setw(10) << *(itDS++)
					<< std::left << std::setw(10) << *(itDS1++)
					<< std::left << std::setw(10) << *(itLS++)
					<< std::left << std::setw(10) << *(itVS++)
					<< std::endl;
	}
	std::cout << std::endl;
	
	/// COPY INITIALIZATION ///

	MutantStack< int > 	copy(DefStack);

	/// ASSIGNMENT ///

	MutantStack< int > 	assig;
	
	assig = copy;
	
	/// DISPLAY CONTAINERS ///

	MutantStack<int>::iterator	itCopy = copy.begin();
	MutantStack<int>::iterator	itAssig = assig.begin();

	std::cout 	<< std::endl << "CONTAINERS: COPY & ASSIGNMENT" << std::endl
				<< std::left << std::setw(10) << "copy"
				<< std::left << std::setw(10) << "assig" << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout	<< std::left << std::setw(10) << *(itCopy++)
					<< std::left << std::setw(10) << *(itAssig++)
					<< std::endl;
	}
	std::cout << std::endl;

	return (0);
}