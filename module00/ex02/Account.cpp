/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:48:24 by pbret             #+#    #+#             */
/*   Updated: 2025/11/04 19:34:56 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

// Initialization of static members
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

// Destructor
Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

// [YYYYMMDD_HHMMSS]
// Displays a timestamp for each event
void	Account::_displayTimestamp(void)
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

// Handles a deposit and updates both instance and static attributes
void	Account::makeDeposit(int deposit)
{
	Account::_totalNbDeposits++;
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";deposit:" << deposit;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout	<< ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

// Handles a withdrawal and updates both instance and static attributes
// If the balance is lower than the withdrawal amount, the withdrawal is refused
bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";p_amount:" << _amount;
	if (this->_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		Account::_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		std::cout	<< ";withdrawal:" << withdrawal
					<< ";amount:" << this->_amount
					<< ";nb_withdrawals:" << this->_nbWithdrawals
					<< std::endl;
		return (true);
	}
}

// Displays overall information for all accounts
void	Account::displayAccountsInfos() 
{
	Account::_displayTimestamp();
	std::cout	<< " accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

// Displays detailed information for a specific account
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

// Unused functions
int	Account::checkAmount() const
{
	return (0);
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

