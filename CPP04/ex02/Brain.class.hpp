/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:33:39 by pbret             #+#    #+#             */
/*   Updated: 2025/12/08 19:42:07 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_CPP
# define BRAIN_CLASS_CPP

#include <string>
#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& rhs);
		Brain&	operator=(const Brain& rhs);
		~Brain();

		void				setIdea(const unsigned int idx, const std::string idea);
		const std::string	getIdea(const unsigned int idx) const;
	
	private:
		std::string	_ideas[100];

};

#endif