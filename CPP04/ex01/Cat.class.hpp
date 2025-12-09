/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:03:33 by pbret             #+#    #+#             */
/*   Updated: 2025/12/09 15:48:50 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include "Animal.class.hpp"


class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& rhs);
		Cat&	operator=(const Cat& rhs);
		~Cat(void);

		void				makeSound(void) const;
		void				setIdea(const unsigned int idx, const std::string idea);
		const std::string	getIdea(const unsigned int idx) const;
		const Brain*		getAddressBrain(void) const;

	private:
		Brain				*_brain;
};

#endif