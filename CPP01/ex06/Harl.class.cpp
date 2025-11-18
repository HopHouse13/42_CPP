/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:52:13 by pbret             #+#    #+#             */
/*   Updated: 2025/11/18 19:22:10 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"

void	Harl::debug(void)
{
	std::cout	<< "DEBUG" << std::endl;
}

void	Harl::info(void)
{
	std::cout	<< "INFO" << std::endl;
	
}

void	Harl::warning(void)
{
		std::cout	<< "WARNING" << std::endl;
}

void	Harl::error(void)
{
		std::cout	<< "ERROR" << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*ft[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			idx = -1;
	
	for(int i = 0; i < 4; i++)
	{
		if (level == lvl[i])
			idx = i;
	}
	
	switch (idx)
	{
		case 0:
			(this->debug());
		case 1:
			(this->info());
		case 2:
			(this->warning());
		case 3:
			(this->error());
			break;
		default:
			std::cout << "level is invalid" << std::endl;
	}
	
}
