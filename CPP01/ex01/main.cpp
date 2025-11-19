/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:16:21 by pbret             #+#    #+#             */
/*   Updated: 2025/11/19 14:35:07 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*zHorde;
	int		nbZombie = 99999;

	if (nbZombie > 0 && nbZombie < 100000)
	{
		zHorde = zombieHorde(nbZombie, "zHorde"); // ft qui alloue le tableau de zombie
		
		for (int i = 0; i < nbZombie; i++)
			zHorde[i].announce(); // on parcourt le tab de zombie pour les annoncer

		delete [] zHorde; // "free" le tab
	}
	else
		std::cout << "invalid value" << std::endl;
	return (0);
}
