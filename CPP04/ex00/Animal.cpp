/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:27:43 by salam             #+#    #+#             */
/*   Updated: 2025/03/08 16:58:40 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
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
    return (this->type);
}
