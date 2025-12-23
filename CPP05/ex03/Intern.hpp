/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:41:22 by pbret             #+#    #+#             */
/*   Updated: 2025/12/23 17:17:51 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

class AForm; // declaration anticipee

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& rhs);
		Intern& operator=(const Intern& rhs);
		~Intern(void);

		AForm*	makeForm(std::string nameForm, std::string targetForm); // new vu que c'est un pointeur

		class wrongNameForm : public std::exception
		{
			public:
				const char*	what(void) const throw();
		};
};

#endif