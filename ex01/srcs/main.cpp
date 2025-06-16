/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:06:01 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/08 15:20:21 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ORANGE	"\033[1;33m"
#define NC		"\033[0m"

int main()
{
	Animal	*tab[10];
	int				i;

	std::cout << std::endl << ORANGE << "/*\n * MANDATORY\n */" << NC 
			  << std::endl << NC;
	std::cout << std::endl << ORANGE << "/*  CONSTRUCTOR  */\n" << NC;
	for (i = 0; i < 10; i++)
	{
		if (i < 5)
			tab[i] = new Cat();
		else
			tab[i] = new Dog();
	}
	std::cout << std::endl << ORANGE << "/*  MAKES A SOUND  */\n" << NC;
	for (int i = 0; i < 10; i++) {
		std::cout << tab[i]->getType() << " makes a sound: ";
		tab[i]->makeSound();
	}
	std::cout << std::endl << ORANGE << "/*  DESTRUCTOR  */\n" << NC;
	for (i = 0; i < 10; i++)
	{
		delete tab[i];
	}

	std::cout << std::endl << ORANGE << "/**\n * DEEP COPY TEST OF BRAIN "
			  << "IDEAS\n */" << NC << std::endl
			  << std::endl << ORANGE << "/*  CONSTRUCTOR  */\n" << NC;
	Cat	cat1;
	cat1.getBrain()->setIdea(0, "Push the cup");
	Cat cat2 = Cat(cat1);
	Dog	dog1;
	dog1.getBrain()->setIdea(0, "Chase the cat");
	Dog	dog2 = Dog(dog1);

	std::cout << std::endl << ORANGE << "/*  ORIGINAL AND COPY IDEAS  */\n" << NC
			  << "cat1 idea : " << cat1.getBrain()->getIdea(0) << std::endl
			  << "cat2 idea : " << cat2.getBrain()->getIdea(0) << std::endl
			  << "dog1 idea : " << dog1.getBrain()->getIdea(0) << std::endl
			  << "dog2 idea : " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl << ORANGE << "/*  ORIGINAL IDEAS AND COPY "
			  << "IDEAS CHANGE  */\n" << NC;
	cat1.getBrain()->setIdea(0, "Chase the bird");
	dog1.getBrain()->setIdea(0, "Eat");
	std::cout << "cat1 idea : " << cat1.getBrain()->getIdea(0) << std::endl
			  << "cat2 idea : " << cat2.getBrain()->getIdea(0) << std::endl
			  << "dog1 idea : " << dog1.getBrain()->getIdea(0) << std::endl
			  << "dog2 idea : " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl << ORANGE << "/*  DESTRUCTOR  */\n" << NC;
	return (0);
}

