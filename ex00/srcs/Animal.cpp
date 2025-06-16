/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:56:49 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/04 17:37:43 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/**
 * @brief	Default constructor for the Animal class.
 */
Animal::Animal() : _type("Animal")
{
	std::cout << this->_type << " constructed" << std::endl;
}

/**
 * @brief	Copy constructor for the Animal class.
 * 
 * @param	origin The Animal object to copy from.
 */
Animal::Animal(Animal const &origin)
{
	*this = origin;
	std::cout << this->_type << " copied" << std::endl;
}

/**
 * @brief	Assignment operator for the Animal class.
 * 
 * @param	other The Animal object to assign from.
 * @return	A reference to the current object.
 */
Animal	&Animal::operator=(Animal const &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << this->_type << " Copy assignment operator called" << std::endl;
	return (*this);
}

/**
 * @brief	Destructor for the Animal class.
 */
Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

/**
 * @brief	Makes a generic animal sound.
 * 
 * This function outputs a generic animal sound to the console.
 */
void		Animal::makeSound() const
{
	std::cout << "*make an unrecognizable noise*" << std::endl;
}

/**
 * @brief	Gets the type of the animal.
 * 
 * @return	The type of the animal as a string.
 */
std::string	Animal::getType() const
{
	return (this->_type);
}
