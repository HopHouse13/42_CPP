/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:31:31 by pab               #+#    #+#             */
/*   Updated: 2025/12/17 17:35:43 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHUBBERYCREATIONFORM_HPP
# define SHUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"


class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);
		~ShrubberyCreationForm(void);

		void	execute(const Bureaucrat& executor);
	

	private:
		std::string	_target;
};

#endif