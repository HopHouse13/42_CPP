/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:54:41 by pbret             #+#    #+#             */
/*   Updated: 2026/02/26 19:04:15 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <utility>
# include <cstdlib>
# include <iterator>

# define FAILURE  1
# define SUCCESS  0

class btcExchange
{
	public:
		btcExchange();
		~btcExchange();
		btcExchange(btcExchange const & copy);
		btcExchange const &	operator=(btcExchange const & rhs);

		int	btcCalculate(std::string input); // voir si c'est possible de la mettre en const

	private:
		std::map<std::string, double>	_data;

		int		_initData();
		void	_displayData();
		int		_handleExchange(std::string input);
		int		_parsingLine(std::string line);
		int		_checkDate(std::string date);
		int		_checkValue(std::string value);
};
// ne pas oublier de rajouter les const

#endif