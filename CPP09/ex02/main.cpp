/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:00:17 by pbret             #+#    #+#             */
/*   Updated: 2026/04/01 15:52:19 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMeCommon.hpp"

int	main(int ac, char **av)
{
	if (ac <= 2)
	{
		if (ac < 2)
			std::cerr << "Error: no input provided. Please enter a sequence of elements." << std::endl;
		else
			std::cerr << "Error: at least two elements are required to sort." << std::endl;
		return (1);
	}

	if (parsing(av) == false)
	{
		std::cerr << "Error: invalid input. All elements must be positive integers." << std::endl;
		return (1);
	}

	std::deque<unsigned long long>	suitJ = initErnstJacobsthal(1026); //1026 valeu max pour pas avoir des inf

	//for (double i = 0; i < suitJ.size(); i++)
	//	std::cout << std::fixed << std::setprecision(0) << suitJ[i] << std::endl;
		
	int	nbElement = ac - 1;
	int	depthMax = depthCount(nbElement);
	
	SortDeque	SortDeque(av, nbElement, depthMax, suitJ);
	SortDeque.handleSortDeque();
  
	//SortVector	SortVector;
	//SortVector.handleSortVector(av, ac);

	return (0);
}

// roadmap:

// - parsing -> only digits positifs
// - init. _main
// - cb de niveau de recursion : compter cb de valeur + cb de niveau de profondeur en doublant le bn de valeurs dans les paires a chaque niveau de recursion
// - affichage du main avant le sort