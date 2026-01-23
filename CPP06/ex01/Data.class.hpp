/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:51:54 by pbret             #+#    #+#             */
/*   Updated: 2026/01/23 18:25:57 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_CLASS_HPP
# define DATA_CALSS_HPP

#include <iostream>

class Data
{
	public:
		Data();
		Data(const Data& rhs);
		Data&		operator=(const Data& rhs);
		~Data();
	
		const int	getValue() const;
		const int	getChar() const;

	private:
		int		_value;
		char	_character;
};

#endif