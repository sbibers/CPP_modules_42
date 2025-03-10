/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:21:46 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 16:14:53 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std :: cout << "------------Correct Animal Tests------------" << std :: endl;
    // const AAnimal    *meta = new AAnimal(); // wrong
    const AAnimal    *i = new Dog();
    const AAnimal    *j = new Cat();
    
    std :: cout << "Dog type: " << i->getType() << std :: endl;
    std :: cout << "Cat type: " << j->getType() << std :: endl;
    std :: cout << "Dog sound: ";
    i->makeSound();
    std :: cout << "Cat sound: ";
    j->makeSound();
    std :: cout << "Animal sound: ";
    // meta->makeSound();
    delete (i);
    delete (j);
    // delete (meta);
    return (0);
}
