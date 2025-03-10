/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:27:43 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 16:15:17 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    this->type = "";
    std :: cout << "AAnimal Constructor Called" << std :: endl;
}

AAnimal::AAnimal(std::string type)
{
    this->type = type;
    std :: cout << "AAnimal parameterized Constructor Called" << std :: endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    std :: cout << "AAnimal Copy Constructor Called" << std :: endl;
    *this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &obj)
{
    this->type = obj.type;
    return (*this);
}

void AAnimal::makeSound() const
{
    std :: cout << "AAnimal Sound ..." << std :: endl;
}

AAnimal::~AAnimal()
{
    std :: cout << "AAnimal Destructor Called" << std :: endl;
}

void AAnimal::setType(std::string type)
{
    this->type = type;
}

std::string AAnimal::getType() const
{
    if (this->type.empty())
        return ("type of class Animal is not set");
    return (this->type);
}
