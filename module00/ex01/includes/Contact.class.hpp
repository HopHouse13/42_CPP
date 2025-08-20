/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:09 by pbret             #+#    #+#             */
/*   Updated: 2025/08/20 17:31:26 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Contact
{
	private :
				std::string	_field[5];
				std::string	_value[5];
				bool		areAlphas(std::string str) const;
				bool		areDigitsPlus(std::string str) const;
				bool		isFull(std::string str) const;

	public :
				Contact(void);
				~Contact(void);

				bool		addContact(void);
				std::string	getField(int idx) const;
				std::string	getValue(int idx) const;
				std::string	getFormattedValue(std::string str) const;
};