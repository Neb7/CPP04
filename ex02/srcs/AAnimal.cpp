/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:56:49 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/08 15:36:12 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/**
 * @brief	Default constructor for the AAnimal class.
 */
AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << this->_type << " constructed" << std::endl;
}

/**
 * @brief	Copy constructor for the AAnimal class.
 * 
 * @param	origin The AAnimal object to copy from.
 */
AAnimal::AAnimal(AAnimal const &origin)
{
	*this = origin;
	std::cout << this->_type << " copied" << std::endl;
}

/**
 * @brief	Assignment operator for the AAnimal class.
 * 
 * @param	other The AAnimal object to assign from.
 * @return	A reference to the current object.
 */
AAnimal	&AAnimal::operator=(AAnimal const &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << this->_type << " Copy assignment operator called" << std::endl;
	return (*this);
}

/**
 * @brief	Destructor for the AAnimal class.
 */
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destroyed" << std::endl;
}

/**
 * @brief	Makes a generic animal sound.
 * 
 * This method is pure virtual and must be overridden by derived classes.
 */
void		AAnimal::makeSound() const
{
	std::cout << "*make an unrecognizable noise*" << std::endl;
}

/**
 * @brief	Gets the type of the animal.
 * 
 * @return	The type of the animal as a string.
 */
std::string	AAnimal::getType() const
{
	return (this->_type);
}
