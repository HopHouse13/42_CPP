/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:16:21 by pbret             #+#    #+#             */
/*   Updated: 2025/11/18 16:48:50 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

int	main()
{
	// Heap: annonce hors scoop de la fonction d'initialisation
	Zombie	*z;

	z = newZombie("z1Solo");
	z->announce();
	delete z; // lors de la suppression de l'instance, le destructeur de la class est appele

	// Stack: annonce dans le scoop d'une fonction
	randomChump("z2Solo");
	return (0);
}
