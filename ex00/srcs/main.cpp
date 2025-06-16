/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:06:01 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/04 15:47:49 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal		*meta = new Animal();
	const Animal		*j = new Dog();
	const Animal		*i = new Cat();
	const WrongAnimal	*test_wa = new WrongAnimal();
	const WrongAnimal	*test = new WrongCat();

	std::cout << std::endl << j->getType() << " : ";
	i->makeSound(); //will output the cat sound!
	std::cout << std::endl << i->getType() << " : ";
	j->makeSound();
	std::cout << std::endl << meta->getType() << " : ";
	meta->makeSound();
	std::cout << std::endl << test_wa->getType() << " : ";
	test_wa->makeSound();
	std::cout << std::endl << test->getType() << " : ";
	test->makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	delete test_wa;
	delete test;
	return (0);
}
