/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:27:43 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 14:37:41 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    this->type = "";
    std :: cout << "Animal Constructor Called" << std :: endl;
}

Animal::Animal(std::string type)
{
    this->type = type;
    std :: cout << "Animal parameterized Constructor Called" << std :: endl;
}

Animal::Animal(const Animal &copy)
{
    std :: cout << "Animal Copy Constructor Called" << std :: endl;
    *this = copy;
}

Animal &Animal::operator=(const Animal &obj)
{
    this->type = obj.type;
    return (*this);
}

void Animal::makeSound() const
{
    std :: cout << "Animal Sound ..." << std :: endl;
}

Animal::~Animal()
{
    std :: cout << "Animal Destructor Called" << std :: endl;
}

void Animal::setType(std::string type)
{
    this->type = type;
}

std::string Animal::getType() const
{
    if (this->type.empty())
        return ("type of class Animal is not set");
    return (this->type);
}
