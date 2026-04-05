/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:00:17 by pbret             #+#    #+#             */
/*   Updated: 2026/04/05 19:21:16 by pab              ###   ########.fr       */
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
	const std::clock_t	startTimeDeque = std::clock(); // renvoit un temps ecoulé en ticks
	SortDeque.handleSortDeque();
	const std::clock_t	endTimeDeque = std::clock();

	//SortVector	SortVector;
	const std::clock_t	startTimeVector = std::clock();
	//SortVector.handleSortVector(av, ac);
	const std::clock_t	endTimeVector = std::clock();

	std::cout	<< "Time to process a range of " << nbElement << " elements with std::deque : "
				<< std::fixed << std::setprecision(2) << 1000.0 * (endTimeDeque - startTimeDeque) / CLOCKS_PER_SEC << "ms" << std::endl // CLOCKS_PER_SEC reprensente ne ticks une seconde selon le systeme
				<< "Time to process a range of " << nbElement << " elements with std::vector : "
				<< std::fixed << std::setprecision(2) << 1000.0 * (endTimeVector - startTimeVector) / CLOCKS_PER_SEC << "ms" << std::endl;
	
	return (0);
}
