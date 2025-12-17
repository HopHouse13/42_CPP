/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:41:22 by pbret             #+#    #+#             */
/*   Updated: 2025/12/17 17:01:02 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

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

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, const unsigned int grade);
		Bureaucrat(const Bureaucrat& rhs);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat(void);

		const std::string&	getName(void) const;
		const unsigned int&	getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(AForm& Aform) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what(void) const throw(); // throw() assure au compilateur que la fonction ne renvoie pas une exception.
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what(void) const throw(); // du coup il faudrait le mettre a toutes les fonctions sans throw externe?
		}; // dans la class exception, what est virtual donc nous pouvons l'override

	private:
		const std::string	_name; // ATTENTION sujet demande un const mais dans l'operateur d'affection nous ne pouvons pas initialiser _name.
		unsigned int		_grade;
};

std::ostream&	operator<<(std::ostream& outStream, const Bureaucrat& rhs);

#endif