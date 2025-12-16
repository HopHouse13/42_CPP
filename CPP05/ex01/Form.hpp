/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:31:31 by pab               #+#    #+#             */
/*   Updated: 2025/12/16 20:56:57 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

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

class Bureaucrat; // delcaration anticipee (le compilateur sait qu'une class Bureaucrat existe lors de la phase de lecture)

class Form
{
	public:
		Form(void);
		Form(const std::string name, const unsigned int sigGrade, const unsigned int execGrade);
		Form(const Form& rhs);
		const Form&	operator=(const Form& rhs);
		~Form(void);

		const std::string&	getNameForm(void) const;
		const bool&			getIsSignedForm(void) const;
		const unsigned int&	getSigGradeForm(void) const;
		const unsigned int&	getExecGradeForm(void) const;

		void				beSigned(const Bureaucrat& guy);

		class GradeTooHighException : public std::exception // pourquoi ne pas les mettre en private?
		{
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};

	private:
		const std::string	_name;
		bool				_isSigned;
		unsigned int		_sigGrade;
		unsigned int		_execGrade;
		
		
};

std::ostream&	operator<<(std::ostream& outStream, const Form& rhs);

#endif