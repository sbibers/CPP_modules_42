/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:27:52 by sbibers           #+#    #+#             */
/*   Updated: 2025/02/25 16:10:24 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce()
{
    std :: cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std :: endl;    
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std :: cout << "Zombie " << this->name << " is destroyed!" << std :: endl;
}
