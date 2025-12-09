/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:03:33 by pbret             #+#    #+#             */
/*   Updated: 2025/12/09 15:57:15 by pbret            ###   ########.fr       */
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
		void				setIdea(const unsigned int idx, const std::string idea);
		const std::string	getIdea(const unsigned int idx) const;
		const Brain*		getAddressBrain(void) const;

	private:
		Brain	*_brain;

};

#endif