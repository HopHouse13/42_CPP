/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:29:51 by pbret             #+#    #+#             */
/*   Updated: 2025/12/03 17:29:54 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << WHITE << "||| FLO AND MAX'S STORY |||" << RESET << std::endl << std::endl;

	ClapTrap	Max("Max");

	std::cout << Max << std::endl;
	Max.attack("a gentleman monster");
	Max.takeDamage(6);
	Max.beRepaired(2);

	ClapTrap	Flo(Max);  // constructeur par copie

	std::cout << Flo << std::endl;
	Flo.attack("a dirty spider");
	Flo.beRepaired(42);
	Flo.takeDamage(10000);
	Flo.attack("a dirty spider");
	Flo.takeDamage(1);

	ClapTrap	man; // constructeur par defaut

	man = Flo; // operateur de surcharge d'affectation
	std::cout << Flo << std::endl;

	return (0);
}