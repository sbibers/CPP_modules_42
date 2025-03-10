/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:34:05 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 15:32:19 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    this->brain = new Brain();
    std :: cout << "Cat Constructor Called" << std :: endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    this->brain = new Brain(*copy.brain);
    std :: cout << "Cat Copy Constructor Called" << std :: endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    this->type = obj.type;
    this->brain = new Brain(*obj.brain);
    return (*this);
}

void Cat::makeSound() const
{
    std :: cout << "Sound of Cat : " << "Meow Meow ..." << std :: endl;
}

void Cat::setBrain(Brain *brain)
{
    for (int i = 0; i < 100; i++)
    {
        this->brain->setIdeas(i, brain->getIdeas(i));
    }
}

Brain *Cat::getBrain() const
{
    return (this->brain);
}

Cat::~Cat()
{
    if (this->brain)
        delete (this->brain);
    std :: cout << "Cat Destructor Called" << std :: endl;
}
