/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:43:47 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 14:43:18 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std :: cout << "Dog Constructor Called" << std :: endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    std :: cout << "Dog parameterized Constructor Called" << std :: endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std :: cout << "Dog Copy Constructor Called" << std :: endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    std :: cout << "Dog Assignment Operator Called" << std :: endl;
    this->type = obj.type;
    return (*this);
}

void Dog::makeSound() const
{
    std :: cout << "Sound of Dog : " << "Woof Woof ..." << std :: endl;
}

Dog::~Dog()
{
    std :: cout << "Dog Destructor Called" << std :: endl;
}
