// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void ); // displays details of all accounts

	Account( int initial_deposit ); // constructor
	~Account( void ); // destructor

	void	makeDeposit( int deposit ); // make a deposit
	bool	makeWithdrawal( int withdrawal ); // make a withdrawal
	int		checkAmount( void ) const;
	void	displayStatus( void ) const; // displays details of this specific account

	static void	_displayTimestamp( void ); // displays a timestamp

private:

	static int	_nbAccounts; // total number of accounts
	static int	_totalAmount; // total amount across all accounts
	static int	_totalNbDeposits; // total number of deposits
	static int	_totalNbWithdrawals; // total number of withdrawals

	int				_accountIndex; // account index
	int				_amount; // account balance
	int				_nbDeposits; // number of deposits for this account
	int				_nbWithdrawals; // number of withdrawals for this account

	Account( void ); // default constructor (private)

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
