/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:29:51 by pbret             #+#    #+#             */
/*   Updated: 2025/12/03 17:29:38 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << WHITE << "||| PAUL, HARRY AND BOB'S STORY |||" << RESET << std::endl << std::endl;

	ScavTrap	Paul("Paul"); // constructeur avec un name

	std::cout << Paul << std::endl;
	Paul.attack("a dirty spider");
	Paul.takeDamage(58);
	Paul.beRepaired(500);
	Paul.guardGate();

	ScavTrap	Harry; // constructeur par defaut

	std::cout << Harry << std::endl;
	Harry = Paul; // operateur de surcharge d'affectation
	std::cout << Paul << std::endl;
	Harry.attack("a dirty spider");
	Harry.beRepaired(42);
	Harry.takeDamage(10000);
	Harry.attack("a dirty spider");
	Harry.takeDamage(1);

	ScavTrap	Bob(Paul); // constructeur avec un name

	std::cout << Bob << std::endl;

	return (0);
}