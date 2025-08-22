/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:48:24 by pbret             #+#    #+#             */
/*   Updated: 2025/08/22 15:06:28 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account( /* int initial_deposit */ )
{
	// initial_deposit = 0;
}

Account::~Account( void )
{

}
// [YYYYMMDD_HHMMSS]
void	Account::_displayTimestamp( void )
{
	std::time_t wildTime = std::time(NULL);

	std::cout	<< std::setfill('0') 
				<< "[" 
				<< 1900 + std::localtime(&wildTime)->tm_year
				<< std::setw(2) << 1 + std::localtime(&wildTime)->tm_mon
				<< std::setw(2) << std::localtime(&wildTime)->tm_mday
				<< "_"
				<< std::setw(2) << std::localtime(&wildTime)->tm_hour
				<< std::setw(2) << std::localtime(&wildTime)->tm_min
				<< std::setw(2) << std::localtime(&wildTime)->tm_sec
				 << "]";
}
