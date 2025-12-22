/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:31:31 by pab               #+#    #+#             */
/*   Updated: 2025/12/22 16:14:01 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <ctime>

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"


class  PresidentialPardonForm : public AForm
{
	public:
		 PresidentialPardonForm(void);
		 PresidentialPardonForm(std::string target);
		 PresidentialPardonForm(const PresidentialPardonForm& rhs);
		 PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);
		~ PresidentialPardonForm(void);

		void					action(void) const;
	
	private:
		std::string	_target;
};

#endif