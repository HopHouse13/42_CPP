/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:16:21 by pbret             #+#    #+#             */
/*   Updated: 2025/11/11 18:57:20 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	// Stack
	Zombie	z1("z1");
	z1.announce();

	//// Heap
	//Zombie	*z2;
	//z2 = new Zombie("z2");
	//z2->announce();
	
	// Heap hors scoop
	Zombie	*z3;
	z3 = newZombie("z3");
	z3->announce();
	return (0);
}

