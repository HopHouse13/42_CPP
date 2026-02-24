/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:54:41 by pbret             #+#    #+#             */
/*   Updated: 2026/02/24 19:28:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <utility>
# include <cstdlib>

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
		int								_initData();

};


#endif