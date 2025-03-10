/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:43:47 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 15:59:57 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
    this->brain = new Brain();
    std :: cout << "Dog Constructor Called" << std :: endl;
}

Dog::Dog(std::string type) : AAnimal(type)
{
    this->brain = new Brain();
    std :: cout << "Dog Constructor with array of ideas Called" << std :: endl;
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
    this->brain = new Brain(*copy.brain);
    std :: cout << "Dog Copy Constructor Called" << std :: endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    this->type = obj.type;
    this->brain = new Brain(*obj.brain);
    return (*this);
}

void Dog::makeSound() const
{
    std :: cout << "Sound of Dog : " << "Woof Woof ..." << std :: endl;
}

void Dog::setBrain(Brain *brain)
{
    for (int i = 0; i < 100; i++)
    {
        this->brain->setIdeas(i, brain->getIdeas(i));
    }
}

Brain *Dog::getBrain() const
{
    return (this->brain);
}

Dog::~Dog()
{
    if (this->brain)
        delete (this->brain);
    std :: cout << "Dog Destructor Called" << std :: endl;
}
