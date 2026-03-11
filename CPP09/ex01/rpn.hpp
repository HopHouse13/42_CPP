/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:06:50 by pbret             #+#    #+#             */
/*   Updated: 2026/03/11 18:17:47 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>

# define SUCCESS 0
# define FAILLURE 1

class Rpn
{
	public:
		Rpn();
		Rpn(std::string const raw);
		~Rpn();
		Rpn(Rpn const & copy);
		Rpn & operator=(Rpn const & rhs);

		int		Calculation();

	private:
		void	_handleOperation(char operatorSign);

		std::string	const	_raw;
		std::stack<double>	_values;
};


#endif