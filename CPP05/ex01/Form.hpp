/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:31:31 by pab               #+#    #+#             */
/*   Updated: 2025/12/15 21:36:38 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(void);
		Form(const std::string name, const unsigned int sigGrade, const unsigned int execGrade);
		Form(const Form& rhs);
		const Form&	operator=(const Form& rhs);
		~Form(void);

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
		
		const bool& getIsSigned(void); // aSUPP

	private:
		const std::string	_name;
		bool				_isSigned;
		unsigned int		_sigGrade;
		unsigned int		_execGrade;
		
		
};