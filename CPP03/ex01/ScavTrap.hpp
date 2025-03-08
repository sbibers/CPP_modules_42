/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:27:34 by salam             #+#    #+#             */
/*   Updated: 2025/03/08 15:16:51 by salam            ###   ########.fr       */
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
        void attack(std::string const & target); // override
        void guardGate();
};

#endif
