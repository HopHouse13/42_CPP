/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:09 by pbret             #+#    #+#             */
/*   Updated: 2025/12/02 14:04:06 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>
#include <iostream>

class Contact
{
	private :
				std::string	_field[5];
				std::string	_value[5];
				bool		areAlphas(std::string str) const;
				bool		areAlNum(std::string str) const;
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

#endif