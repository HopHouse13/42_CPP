/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:03:33 by pbret             #+#    #+#             */
/*   Updated: 2025/12/05 18:27:34 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include "string"
#include "iostream"

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

class Animal
{
	public:
		Animal(void);
		Animal(const Animal& rhs);
		Animal&				operator=(const Animal& rhs);
		virtual	~Animal(void);

		virtual void		makeSound(void) const;
		const std::string&	getType(void) const;
	
	protected:
		std::string			_type;
};

#endif