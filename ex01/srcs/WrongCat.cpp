/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:04:40 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/07 17:04:42 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/**
 * @brief	Default constructor for the WrongCat class.
 */
WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << this->_type << " contructed" << std::endl;
}

/**
 * @brief	Copy constructor for the WrongCat class.
 * 
 * @param	origin The WrongCat object to copy from.
 */
WrongCat::WrongCat(WrongCat const &origin)
{
	*this = origin;
	std::cout << this->_type << " copied" << std::endl;
}

/**
 * @brief	Assignment operator for the WrongCat class.
 * 
 * @param	other The WrongCat object to assign from.
 * @return	A reference to the current object.
 */
WrongCat	&WrongCat::operator=(WrongCat const &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << this->_type << " Copy assignment operator called" << std::endl;
	return (*this);
}

/**
 * @brief	Destructor for the WrongCat class.
 */
WrongCat::~WrongCat()
{
	std::cout << _type << " destroyed" << std::endl;
}

/**
 * @brief	Makes a cat sound.
 */
void	WrongCat::makeSound() const
{
	std::cout << this->_type << " : *miaou miaou*" << std::endl;
}