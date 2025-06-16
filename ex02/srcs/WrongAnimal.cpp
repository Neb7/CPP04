/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:02:26 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/07 17:02:28 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/**
 * @brief	Default constructor for the WrongAnimal class.
 */
WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << this->_type << " constructed" << std::endl;
}

/**
 * @brief	Copy constructor for the WrongAnimal class.
 * 
 * @param	origin The WrongAnimal object to copy from.
 */
WrongAnimal::WrongAnimal(WrongAnimal const &origin)
{
	*this = origin;
	std::cout << this->_type << " copied" << std::endl;
}

/**
 * @brief	Assignment operator for the WrongAnimal class.
 * 
 * @param	other The WrongAnimal object to assign from.
 * @return	A reference to the current object.
 */
WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << this->_type << " Copy assignment operator called" << std::endl;
	return (*this);
}

/**
 * @brief	Destructor for the WrongAnimal class.
 */
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed" << std::endl;
}

/**
 * @brief	Makes a generic wrong animal sound.
 * 
 * This function outputs an unrecognizable noise to the console.
 */
void		WrongAnimal::makeSound() const
{
	std::cout << this->_type << " : *make an unrecognizable noise*" << std::endl;
}

/**
 * @brief	Gets the type of the wrong animal.
 * 
 * @return	The type of the wrong animal as a string.
 */
std::string	WrongAnimal::getType() const
{
	return (this->_type);
}
