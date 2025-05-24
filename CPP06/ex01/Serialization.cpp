/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:53:09 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/24 15:56:10 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{}

Serialization::~Serialization()
{}

Serialization::Serialization(const Serialization &obj)
{
    *this = obj;
}

Serialization &Serialization::operator=(const Serialization &obj)
{
    if (this != &obj)
        *this = obj;
    return (*this);
}

uintptr_t Serialization::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialization::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
