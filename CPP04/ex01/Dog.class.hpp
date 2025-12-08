/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:03:33 by pbret             #+#    #+#             */
/*   Updated: 2025/12/08 18:10:15 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

#include "Animal.class.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& rhs);
		Dog&		operator=(const Dog& rhs);
		~Dog(void);

		void		makeSound(void) const;

	private:
		Brain	*_brain;

};

#endif