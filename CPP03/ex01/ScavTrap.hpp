/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:27:34 by salam             #+#    #+#             */
/*   Updated: 2025/03/12 12:24:07 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(); // default constructor
        ScavTrap(std::string name); // parameterized constructor
        ScavTrap(const ScavTrap &scav); // copy constructor
        ScavTrap &operator=(const ScavTrap &scav); // copy assignment operator
        ~ScavTrap(); // destructor
        void attack(std::string const &target); // override
        void guardGate();
};

#endif
