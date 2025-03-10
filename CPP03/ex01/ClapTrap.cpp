/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:58:02 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 21:20:31 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() // default constructor
{
    std :: cout << "ClapTrap Default constructor called" << std :: endl;
}

ClapTrap::ClapTrap(std::string name) // parameterized constructor
{
    std :: cout << "ClapTrap Parameterized constructor called" << std :: endl;
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &clap) // copy constructor
{
    std :: cout << "ClapTrap Copy constructor called" << std :: endl;
    *this = clap;
}

ClapTrap::~ClapTrap() // destructor
{
    std :: cout << "ClapTrap Destructor called for ClapTrap" << std :: endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clap) // copy assignment operator
{
    std :: cout << "ClapTrap copy assignment operator" << std :: endl;
    this->name = clap.name;
    this->hit_points = clap.hit_points;
    this->energy_points = clap.energy_points;
    this->attack_damage = clap.attack_damage;
    return (*this);
}

void ClapTrap::attack(std::string const & target)
{
    if (this->energy_points <= 0 || this->hit_points <= 0)
    {
        std :: cout << "ClapTrap " << this->name << " can't attack because it has no energy or hit points" << std :: endl;
        return ;
    }
    std :: cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->attack_damage << " points of damage!" << std :: endl;
    this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points <= 0)
    {
        std :: cout << "ClapTrap " << this->name << " can't take damage because it has no hit points" << std :: endl;
        return ;
    }
    if (amount >= this->hit_points)
    {
        this->hit_points = 0;
        std :: cout << "ClapTrap " << this->name << " has no hit points left" << std :: endl;
    }
    else
    {
        std :: cout << "ClapTrap " << this->name << " take " << amount << " points of damage!" << std :: endl;
        this->hit_points -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points <= 0)
    {
        std :: cout << "ClapTrap " << this->name << " can't be repaired because it has no hit points" << std :: endl;
        return ;
    }
    if (this->energy_points <= 0)
    {
        std :: cout << "ClapTrap " << this->name << " can't be repaired because it has no energy points" << std :: endl;
        return ;
    }
    if (!amount)
    {
        std :: cout << "ClapTrap " << this->name << " can't be repaired because the amount is 0" << std :: endl;
        return ;
    }
    if ((unsigned long)(amount + this->hit_points) >= std::numeric_limits<unsigned int>::max())
    {
        std :: cout << "ClapTrap " << this->name << " hit points is full!" << std :: endl;
        this->hit_points = std::numeric_limits<unsigned int>::max();
        std :: cout << "ClapTrap " << this->name << " be repaired by " << std::numeric_limits<unsigned int>::max << " points!" << std :: endl;
        this->energy_points--;
        return ;
    }
    std :: cout << "ClapTrap " << this->name << " be repaired by " << amount << " points!" << std :: endl;
    this->hit_points += amount;
    this->energy_points--;
}

void ClapTrap::setName(std::string name)
{
    this->name = name;
}

std::string ClapTrap::getName() const
{
    return (this->name);
}

void ClapTrap::setHitPoints(unsigned int hit_points)
{
    this->hit_points = hit_points;
}

unsigned int ClapTrap::getHitPoints() const
{
    return (this->hit_points);
}

void ClapTrap::setEnergyPoints(unsigned int energy_points)
{
    this->energy_points = energy_points;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return (this->energy_points);
}

void ClapTrap::setAttackDamage(unsigned int attack_damage)
{
    this->attack_damage = attack_damage;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return (this->attack_damage);
}
