/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:31:31 by pab               #+#    #+#             */
/*   Updated: 2025/12/19 16:28:57 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

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

class AForm
{
	public:
		AForm(void);
		AForm(const std::string name, const unsigned int sigGrade, const unsigned int execGrade);
		AForm(const AForm& rhs);
		const AForm&	operator=(const AForm& rhs);
		virtual ~AForm(void);

		const std::string&	getNameForm(void) const;
		const bool&			getIsSignedForm(void) const;
		const unsigned int&	getSigGradeForm(void) const;
		const unsigned int&	getExecGradeForm(void) const;

		void				beSigned(const Bureaucrat& guy);
		void				execute(const Bureaucrat& executor) const;
		void virtual		action(void) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		class Unsigned : public std::exception
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

std::ostream&	operator<<(std::ostream& outStream, const AForm& rhs);

#endif

// Dans AForm:
// execute -> verifier si le bureaucrat peut exec 
// si l'une des deux condtions est invalide -> throw (message)
// message supp -> exception nosign

// Dans chaque Class heritee:
// exec -> pour executer l'action

// Dans Bureaucrat:
// try {executeForm(Form const& form) -> bureaucrat qui execute "execute" + Message reussite}
// si throw d'execute(AForm) -> Message de fail