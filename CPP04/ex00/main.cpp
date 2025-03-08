/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:21:46 by salam             #+#    #+#             */
/*   Updated: 2025/03/08 17:39:59 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

int main()
{
    std :: cout << "------------Correct Animal Tests------------" << std :: endl;
    const Animal    *meta = new Animal();
    const Animal    *i = new Dog();
    const Animal    *j = new Cat();
    
    std :: cout << "Dog type: " << i->getType() << std :: endl;
    std :: cout << "Cat type: " << j->getType() << std :: endl;
    std :: cout << "Dog sound: ";
    i->makeSound();
    std :: cout << "Cat sound: ";
    j->makeSound();
    std :: cout << "Animal sound: ";
    meta->makeSound();
    delete (i);
    delete (j);
    delete (meta);
    
    std :: cout << "------------Wrong Animal Tests------------" << std :: endl;
    const WrongAnimal   *wrong_animal = new WrongAnimal();
    const WrongAnimal   *wrong_cat = new WrongCat();
    const WrongCat      *direct_wrong_cat = new WrongCat();
    
    std :: cout << "WrongCat type: " << wrong_cat->getType() << std :: endl;
    std :: cout << "WrongCat through WrongAnimal pointer sound: ";
    wrong_cat->makeSound(); // This will call WrongAnimal::makeSound(), because it does not have virtual function
    std :: cout << "WrongAnimal sound: ";
    wrong_animal->makeSound();  // This will call WrongAnimal::makeSound(), because it does not have virtual function
    std :: cout << "Direct WrongCat sound: ";
    direct_wrong_cat->makeSound(); // This will call WrongCat::makeSound()
    delete (wrong_animal);
    delete (wrong_cat);
    delete (direct_wrong_cat);
    return (0);
}
