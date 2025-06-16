/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:14:26 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 13:54:04 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/**
 * @brief	Default constructor for Cure class.
 */
Cure::Cure() : AMateria("cure")
{}

/**
 * @brief	Copy constructor for Cure class.
 * 
 * @param	origin The Cure object to copy from.
 */
Cure::Cure(Cure const &origin) : AMateria(origin)
{}

/**
 * @brief	Assignment operator for Cure class.
 * 
 * @param	other The Cure object to assign from.
 * @return	Reference to the current Cure object.
 */
Cure		&Cure::operator=(Cure const &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

/**
 * @brief	Destructor for Cure class.
 */
Cure::~Cure()
{}

/**
 * @brief	Creates a clone of the Cure object.
 * 
 * @return	A pointer to the newly created Cure object.
 */
AMateria	*Cure ::clone() const
{
	return (new Cure());
}

/**
 * @brief	Uses the Cure materia on a target character.
 * 
 * @param	target The character to use the Cure on.
 */
void		Cure::use(ICharacter &target)
{
	std::cout << "* heals "<< target.getName() << " *"
			  << std::endl;
}
