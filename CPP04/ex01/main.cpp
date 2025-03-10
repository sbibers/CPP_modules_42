/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:21:46 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 15:45:39 by salam            ###   ########.fr       */
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
    // std :: cout << "------------Correct Animal Tests------------" << std :: endl;
    // const Animal    *meta = new Animal("Animal");
    // const Animal    *i = new Dog();
    // const Animal    *j = new Cat();
    
    // std :: cout << "Dog type: " << i->getType() << std :: endl;
    // std :: cout << "Cat type: " << j->getType() << std :: endl;
    // std :: cout << "Dog sound: ";
    // i->makeSound();
    // std :: cout << "Cat sound: ";
    // j->makeSound();
    // std :: cout << "Animal sound: ";
    // meta->makeSound();
    // delete (i);
    // delete (j);
    // delete (meta);
    
    // std :: cout << "------------Wrong Animal Tests------------" << std :: endl;
    // const WrongAnimal   *wrong_animal = new WrongAnimal();
    // const WrongAnimal   *wrong_cat = new WrongCat();
    // const WrongCat      *direct_wrong_cat = new WrongCat();
    
    // std :: cout << "WrongCat type: " << wrong_cat->getType() << std :: endl;
    // std :: cout << "WrongCat through WrongAnimal pointer sound: ";
    // wrong_cat->makeSound(); // call WrongAnimal::makeSound(), because it does not have virtual function
    // std :: cout << "WrongAnimal sound: ";
    // wrong_animal->makeSound();  // call WrongAnimal::makeSound(), because it does not have virtual function
    // std :: cout << "Direct WrongCat sound: ";
    // direct_wrong_cat->makeSound(); // call WrongCat::makeSound()
    // delete (wrong_animal);
    // delete (wrong_cat);
    // delete (direct_wrong_cat);

    std :: cout << "------------Test Animal Object Array------------" << std :: endl;
    Animal *animals[10];
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < 10; i++)
    {
        animals[i]->makeSound();
        delete (animals[i]);
    }
    std::string arr[10] = {"Hello", "World", "This", "Is", "A", "Test", "Of", "The", "Brain", "Function"};
    std :: cout << "------------Test Brain Object------------" << std :: endl;
    Brain *brain = new Brain(arr, sizeof(arr) / sizeof(arr[0]));
    Brain *brain2 = new Brain();
    for (int i = 0; i < 10; i++)
    {
        if (!brain->getIdeas(i).empty())
            std :: cout << brain->getIdeas(i) << std :: endl;
        else
            std :: cout << "Idea " << i << " is empty" << std :: endl;
    }
    std :: cout << "------------Test Brain Object 2------------" << std :: endl;
    for (int i = 0; i < 10; i++)
    {
        if (!brain2->getIdeas(i).empty())
            std :: cout << brain2->getIdeas(i) << std :: endl;
        else
            std :: cout << "Idea " << i << " is empty" << std :: endl;
    }
    delete (brain);
    delete (brain2);
    return (0);
}
