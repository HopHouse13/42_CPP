/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:29:51 by pbret             #+#    #+#             */
/*   Updated: 2025/12/02 18:03:44 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Max("Max");

	std::cout << Max << std::endl;
	Max.attack("a gentleman monster");
	Max.takeDamage(6);
	Max.beRepaired(2);

	ClapTrap	Flo(Max); // constructeur par copie

	std::cout << Flo << std::endl;
	Flo.attack("a dirty spider");
	Flo.beRepaired(42);
	Flo.takeDamage(10000);
	Flo.attack("a dirty spider");
	Flo.takeDamage(1);

	ScavTrap	Paul("Paul");

	std::cout << Paul << std::endl;
	Paul.attack("a dirty spider");
	Paul.takeDamage(58);
	Paul.beRepaired(500);

	ScavTrap	Harry;

	std::cout << Harry << std::endl;
	Harry = Paul; // operateur de surcharge d'affectation
	std::cout << Paul << std::endl;
	Harry.attack("a dirty spider");
	Harry.beRepaired(42);
	Harry.takeDamage(10000);
	Harry.attack("a dirty spider");
	Harry.takeDamage(1);

	return (0);
}