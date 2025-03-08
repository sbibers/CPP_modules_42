/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:27:34 by salam             #+#    #+#             */
/*   Updated: 2025/03/08 15:15:15 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() // default constructor
{
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std :: cout << "ScavTrap default constructor called" << std :: endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap() // parameterized constructor
{
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std :: cout << "ScavTrap parameterized constructor called" << std :: endl;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : ClapTrap(scav) // copy constructor
{
    std :: cout << "ScavTrap copy constructor called" << std :: endl;
    *this = scav;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scav) // assignment operator
{
    std :: cout << "ScavTrap assignation operator called" << std :: endl;
    if (this != &scav)
    {
        ClapTrap::operator=(scav);
    }
    return (*this);
}

ScavTrap::~ScavTrap() // destructor
{
    std :: cout << "ScavTrap destructor called for " << this->getName() << std :: endl;
}

void ScavTrap::attack(std::string const & target)
{
    if (this->getEnergyPoints() <= 0)
    {
        std :: cout << "ScavTrap " << this->getName() << " has no energy points left to attack!" << std :: endl;
        return;
    }
    if (this->getHitPoints() <= 0)
    {
        std :: cout << "ScavTrap " << this->getName() << " is already dead and cannot attack!" << std :: endl;
        return;
    }
    std :: cout << "ScavTrap " << this->getName() << " attacks " << target 
              << ", causing " << this->getAttackDamage() << " points of damage!" << std :: endl;
    this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ScavTrap::guardGate()
{
    std :: cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode!" << std :: endl;
}
