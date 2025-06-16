/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:31:12 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/04 16:48:55 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/**
 * @brief	Default constructor for the Brain class.
 */
Brain::Brain()
{
	std::cout << "Brain constructed" << std::endl;
}

/**
 * @brief	Copy constructor for the Brain class.
 * 
 * @param	origin The Brain object to copy from.
 */
Brain::Brain(Brain const &origin)
{
	*this = origin;
	std::cout << "Brain copied" << std::endl;
}

/**
 * @brief	Assignment operator for the Brain class.
 * 
 * @param	other The Brain object to assign from.
 * @return	A reference to the current object.
 */
Brain	&Brain::operator=(Brain const &other)
{
	int	i;

	if (this != &other)
	{
		for (i = 0; i < 100; ++i)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	std::cout << "Brain Copy assignment operator called" << std::endl;
	return (*this);
}

/**
 * @brief	Destructor for the Brain class.
 */
Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}

/**
 * @brief	Sets an idea at a specific index in the brain.
 * 
 * @param	index The index where the idea will be set.
 * @param	idea The idea to set.
 */
void		Brain::setIdea(int index, std::string idea)
{
	if (index >= 0 && index < 100)
	{
		this->_ideas[index] = idea;
	}
}

/**
 * @brief	Gets an idea from a specific index in the brain.
 * 
 * @param	index The index from which to get the idea.
 * @return	The idea at the specified index, or an empty string if
 * 			the index is out of bounds.
 */
std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return (this->_ideas[index]);
	}
	else
	{
		return ("");
	}
}
