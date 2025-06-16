/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:29:32 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 13:55:53 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/**
 * @brief	Default constructor for Ice class.
 */
Ice::Ice() : AMateria("ice")
{}

/**
 * @brief	Copy constructor for Ice class.
 * 
 * @param	origin The Ice object to copy from.
 */
Ice::Ice(Ice const &origin) : AMateria(origin)
{}

/**
 * @brief	Assignment operator for Ice class.
 * 
 * @param	other The Ice object to assign from.
 * @return	Reference to the current Ice object.
 */
Ice			&Ice::operator=(Ice const &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

/**
 * @brief	Destructor for Ice class.
 */
Ice::~Ice()
{}

/**
 * @brief	Creates a clone of the Ice object.
 * 
 * @return	A pointer to the newly created Ice object.
 */
AMateria	*Ice::clone() const
{
	return (new Ice());
}

/**
 * @brief	Uses the Ice materia on a target character.
 * 
 * @param	target The character to use the Ice materia on.
 */
void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *"
			  << std::endl;
}
