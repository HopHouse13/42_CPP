/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:09 by pbret             #+#    #+#             */
/*   Updated: 2025/08/12 18:42:54 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Contact
{
	private :
		std::string	_firstName;
		std::string	_lastName;
		std::string _nickName;
		std::string	_phoneNumber;
		std::string	_darknestSecret;

	public :

		Contact(void);
		~Contact(void);
};