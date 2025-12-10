/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:41:22 by pbret             #+#    #+#             */
/*   Updated: 2025/12/10 19:05:22 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& rhs);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat(void);

		const std::string&	getName(void) const;
		const unsigned int&	getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

	private:
		const std::string	_name;
		unsigned int		_grade;

		void	GradeTooHighException(void);
		void	GradeTooLowException(void);
};

#endif