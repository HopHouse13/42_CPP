/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:29:51 by pbret             #+#    #+#             */
/*   Updated: 2025/12/01 22:01:54 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("Max");
	ClapTrap	c("Flo");
	
	std::cout << a << std::endl;
	a.takeDamage(6);
	a.beRepaired(2);
	a.attack("Paul");
	a.takeDamage(5);
	ClapTrap	b(a);
	std::cout << a << std::endl;
	b.attack("Paul");
	b.beRepaired(41);
	b.takeDamage(10000);
	b.attack("Paul");
	b.takeDamage(1);
	return (0);
}