/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:46 by pbret             #+#    #+#             */
/*   Updated: 2025/08/15 13:00:19 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.class.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>  // exit

#define BLINK	"\033[5m"
#define BOLD	"\033[1m"
#define ITA		"\033[1;3m"
#define RESET	"\033[0m"
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGEN	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"
#define GOLD	"\033[93m"

class PhoneBook
{
	private :
				Contact	_contact[8];
				int		_nbC;
	public :
				PhoneBook(void);
				~PhoneBook(void);

				void		programRules(void) const;
				void		addCmd(void);
				void 		searchCmd(void) const;
				void		displayRepertory(void) const;
				bool		exitCmd(void) const;
				static void	exitMess(void);
				std::string	cmd;
};