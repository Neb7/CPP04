/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:47:27 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/17 15:28:41 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**
 * @brief	Default constructor for the Dog class.
 */
Dog::Dog() : Animal(), _brain(new Brain())
{
	_type = "Dog";
	std::cout << this->_type << " contructed" << std::endl;
}

/**
 * @brief	Copy constructor for the Dog class.
 * 
 * @param	origin The Dog object to copy from.
 */
Dog::Dog(Dog const &origin) : Animal(), _brain(NULL)
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
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		if (_brain != NULL)
		{
			delete _brain;
			_brain = NULL;
		}
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

/**
 * @brief	Destructor for the Dog class.
 */
Dog::~Dog()
{
	if (_brain != NULL)
	{
		delete _brain;
		_brain = NULL;
	}
	std::cout << this->_type << " destroyed" << std::endl;
}

/**
 * @brief	Makes a dog sound.
 */
void	Dog::makeSound() const
{
	std::cout << "*wouf wouf*" << std::endl;
}

/**
 * @brief	Gets the brain of the Dog.
 * 
 * @return	A pointer to the Dog's brain.
 */
Brain	*Dog::getBrain() const
{
	return (this->_brain);
}
