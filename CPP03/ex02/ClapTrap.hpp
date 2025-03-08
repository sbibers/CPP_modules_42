/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:58:13 by salam             #+#    #+#             */
/*   Updated: 2025/03/08 16:09:28 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std :: string name;
        unsigned int hit_points;
        unsigned int energy_points; // energy points that the claptrap has attack or be repaired.
        unsigned int attack_damage;
    public:
        ClapTrap(); // default constructor
        ClapTrap(std::string name); // parameterized constructor
        ClapTrap(const ClapTrap &clap); // copy constructor
        ClapTrap &operator=(const ClapTrap &clap); // assignation operator
        ~ClapTrap(); // destructor
        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setName(std::string name);
        std::string getName() const;
        void setHitPoints(unsigned int hit_points);
        unsigned int getHitPoints() const;
        void setEnergyPoints(unsigned int energy_points);
        unsigned int getEnergyPoints() const;
        void setAttackDamage(unsigned int attack_damage);
        unsigned int getAttackDamage() const;
};

#endif
