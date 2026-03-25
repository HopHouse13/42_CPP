/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeCommon.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:37:26 by pbret             #+#    #+#             */
/*   Updated: 2026/03/25 14:39:54 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMeCommon.hpp"

// check si digits positifs
// check int_max
bool	parsing(char ** av)
{
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return(false);
		}
		if (std::atof(av[i]) > std::numeric_limits<int>::max()) // conversion en double pour check le int_max
			return (false);
	}
	return (true);
}

int	depthCount(int nbElem)
{
	if (nbElem % 2 != 0) // passe ne nb d'elements pair si il etait impair
		nbElem--;

	int	lvl = 0;
	
	while (nbElem >= 2)
	{
		nbElem /= 2;
		lvl++;
	}
	return (lvl);
}

//void	initErnstJacobsthal()
//{
	
//}

