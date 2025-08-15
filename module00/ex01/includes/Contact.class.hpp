/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:09 by pbret             #+#    #+#             */
/*   Updated: 2025/08/15 12:38:07 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Contact
{
	private :
				std::string	_field[5];
				std::string	_value[5];

	public :
				Contact(void);
				~Contact(void);

				void		addContact(void);
				std::string	getField(int idx) const;
				std::string	getValue(int idx) const;
		
};