/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:53:01 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/04 17:38:52 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/**
 * @brief	Default constructor for the AMateria class.
 */
AMateria::AMateria()
{}

/**
 * @brief	Constructor for the AMateria class with a type parameter.
 *
 * @param	type The type of the materia.
 */
AMateria::AMateria(std::string const &type) : _type(type)
{}

/**
 * @brief	Copy constructor for the AMateria class.
 *
 * @param	origin The AMateria object to copy from.
 */
AMateria::AMateria(AMateria const &origin)
{
	*this = origin;
}

/**
 * @brief	Assignment operator for the AMateria class.
 *
 * @param	other The AMateria object to assign from.
 * @return	Reference to the assigned AMateria object.
 */
AMateria	&AMateria::operator=(AMateria const &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

/**
 * @brief	Destructor for the AMateria class.
 */
AMateria::~AMateria()
{}

/**
 * @brief	Returns the type of the AMateria.
 * 
 * @return	A constant reference to a std::string representing the type of the
 * 			AMateria.
 */
std::string const	&AMateria::getType() const
{
	return (this->_type);
}
