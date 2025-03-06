/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:34:26 by sbibers           #+#    #+#             */
/*   Updated: 2025/02/25 15:42:21 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setName(std::string name)
{
    this->name = name;
}

void Zombie::announce()
{
    std :: cout << this->name << ": Moar brainz!" <<  std :: endl;
}

Zombie::~Zombie()
{
    std :: cout << "Zombie " << this->name << " is destroyed!" << std :: endl;
}
