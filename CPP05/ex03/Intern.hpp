/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:41:22 by pbret             #+#    #+#             */
/*   Updated: 2025/12/22 19:52:43 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>

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
		Intern(const std::string name, const unsigned int grade);
		Intern(const Intern& rhs);
		Intern& operator=(const Intern& rhs);
		~Intern(void);

		AForm	*makeForm(std::string nameForm, std::string targetForm); // new vu que c'est un pointeur
		//class GradeTooHighException : public std::exception
		//{
		//	public:
		//		const char	*what(void) const throw();
		//};

		//class GradeTooLowException : public std::exception
		//{
		//	public:
		//		const char	*what(void) const throw();
		//};
};

std::ostream&	operator<<(std::ostream& outStream, const Intern& rhs);

#endif