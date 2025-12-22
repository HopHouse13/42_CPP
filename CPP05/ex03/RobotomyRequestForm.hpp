/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:31:31 by pab               #+#    #+#             */
/*   Updated: 2025/12/22 15:37:37 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

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


class  RobotomyRequestForm : public AForm
{
	public:
		 RobotomyRequestForm(void);
		 RobotomyRequestForm(std::string target);
		 RobotomyRequestForm(const RobotomyRequestForm& rhs);
		 RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);
		~ RobotomyRequestForm(void);

		void					action(void) const;
	
	private:
		std::string	_target;
};

#endif