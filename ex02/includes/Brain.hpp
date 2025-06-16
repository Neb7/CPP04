/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:11:30 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/04 16:57:44 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

/**
 * @brief	The Brain class represents a brain that can store ideas.
 */
class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(Brain const &origin);
		Brain	&operator=(Brain const &other);
		~Brain();

		void		setIdea(int index, std::string idea);
		std::string	getIdea(int index) const;
};

#endif
