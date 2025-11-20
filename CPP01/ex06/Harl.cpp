/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:52:13 by pbret             #+#    #+#             */
/*   Updated: 2025/11/19 17:25:09 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout	<< "msg DEBUG" << std::endl;
}

void	Harl::info(void)
{
	std::cout	<< "msg INFO" << std::endl;
	
}

void	Harl::warning(void)
{
		std::cout	<< "msg WARNING" << std::endl;
}

void	Harl::error(void)
{
		std::cout	<< "msg ERROR" << std::endl;
}

void	Harl::complain(std::string level)
{
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
