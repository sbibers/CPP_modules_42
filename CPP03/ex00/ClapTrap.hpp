/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:58:13 by salam             #+#    #+#             */
/*   Updated: 2025/03/12 12:21:24 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <limits>

class ClapTrap
{
    private:
        std :: string name;
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int attack_damage;
    public:
        ClapTrap(); // default constructor
        ClapTrap(std::string name); // parameterized constructor
        ClapTrap(const ClapTrap &clap); // copy constructor
        ClapTrap &operator=(const ClapTrap &clap); // copy assignment operator
        ~ClapTrap(); // destructor
        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setName(std::string name);
        std::string getName();
        void setHitPoints(unsigned int hit_points);
        unsigned int getHitPoints();
        void setEnergyPoints(unsigned int energy_points);
        unsigned int getEnergyPoints();
        void setAttackDamage(unsigned int attack_damage);
        unsigned int getAttackDamage();
};

#endif
