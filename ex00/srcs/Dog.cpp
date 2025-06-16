/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:47:27 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/04 16:44:39 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**
 * @brief	Default constructor for the Dog class.
 */
Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << this->_type << " contructed" << std::endl;
}

/**
 * @brief	Copy constructor for the Dog class.
 * 
 * @param	origin The Dog object to copy from.
 */
Dog::Dog(Dog const &origin)
{
	*this = origin;
	std::cout << this->_type << " copied" << std::endl;
}

/**
 * @brief	Assignment operator for the Dog class.
 * 
 * @param	other The Dog object to assign from.
 * @return	A reference to the current object.
 */
Dog	&Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << this->_type << " Copy assignment operator called" << std::endl;
	return (*this);
}

/**
 * @brief	Destructor for the Dog class.
 */
Dog::~Dog()
{
	std::cout << this->_type << " destroyed" << std::endl;
}

/**
 * @brief	Makes a dog sound.
 */
void	Dog::makeSound() const
{
	std::cout << "*wouf wouf*" << std::endl;
}

