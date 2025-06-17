/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:08:50 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/17 15:28:53 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/**
 * @brief	Default constructor for the Cat class.
 */
Cat::Cat() : AAnimal(), _brain(new Brain())
{
	_type = "Cat";
	std::cout << this->_type << " contructed" << std::endl;
}

/**
 * @brief	Copy constructor for the Cat class.
 * 
 * @param	origin The Cat object to copy from.
 */
Cat::Cat(Cat const &origin) : AAnimal(), _brain(NULL)
{
	*this = origin;
	std::cout << this->_type << " copied" << std::endl;
}

/**
 * @brief	Assignment operator for the Cat class.
 * 
 * @param	other The Cat object to assign from.
 * @return	A reference to the current object.
 */
Cat	&Cat::operator=(Cat const &other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		if (_brain != NULL)
		{
			delete _brain;;
			_brain = NULL;
		}
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

/**
 * @brief	Destructor for the Cat class.
 */
Cat::~Cat()
{
	if (_brain != NULL)
	{
		delete _brain;
		_brain = NULL;
	}
	std::cout << _type << " destroyed" << std::endl;
}

/**
 * @brief	Makes a cat sound.
 * 
 * This function outputs the sound a cat makes.
 */
void	Cat::makeSound() const
{
	std::cout << "*miaou miaou*" << std::endl;
}

/**
 * @brief	Gets the brain of the cat.
 * 
 * @return	A pointer to the Cat's brain.
 */
Brain	*Cat::getBrain() const
{
	return (this->_brain);
}
