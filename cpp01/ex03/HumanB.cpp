/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:43:32 by sbibers           #+#    #+#             */
/*   Updated: 2025/02/24 18:34:02 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}


void HumanB::attack()
{
    if (weapon)
        std :: cout << name << " attacks with their " << weapon->getType() << std :: endl;
    else
        std :: cout << name << " has no weapon to attack with." << std :: endl;
}
