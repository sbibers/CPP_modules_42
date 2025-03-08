/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:34:05 by salam             #+#    #+#             */
/*   Updated: 2025/03/08 17:19:30 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std :: cout << "Cat Constructor Called" << std :: endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    std :: cout << "Cat parameterized Constructor Called" << std :: endl;
}

Cat::Cat(const Cat &copy) : Animal()
{
    std :: cout << "Cat Copy Constructor Called" << std :: endl;
    this->type = copy.type;
}

Cat &Cat::operator=(const Cat &obj)
{
    std :: cout << "Cat Assignment Operator Called" << std :: endl;
    this->type = obj.type;
    return (*this);
}

void Cat::makeSound() const
{
    std :: cout << "Sound of Cat : " << "Meow Meow ..." << std :: endl;
}

Cat::~Cat()
{
    std :: cout << "Cat Destructor Called" << std :: endl;
}
