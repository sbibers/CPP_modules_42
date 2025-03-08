/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:06:58 by salam             #+#    #+#             */
/*   Updated: 2025/03/07 23:10:17 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>

int main()
{
    std::cout << "-------------ClapTrap Tests-------------" << std::endl;
    ClapTrap clap("ClapTrap");
    ClapTrap clap2(clap);
    ClapTrap clap3 = clap;

    clap.takeDamage(5);
    clap.attack("enemy");
    clap.beRepaired(5);
    
    std::cout << "\n-------------ScavTrap Tests-------------" << std::endl;
    ScavTrap scav("ScavTrap");
    ScavTrap scav2(scav);
    ScavTrap scav3 = scav;

    std::cout << "ScavTrap " << scav.getName() << " has " << scav.getHitPoints() << " hit points, " 
              << scav.getEnergyPoints() << " energy points, and " 
              << scav.getAttackDamage() << " attack damage." << std::endl;
    // std :: exit(0);
    scav.attack("enemy");
    scav.takeDamage(30);
    // std :: exit(0);
    scav.beRepaired(20);
    scav.guardGate();
    // std :: exit(0);
    scav.attack("enemy");
    std :: exit(0);
    std::cout << "\n-------------Construction/Destruction Chaining Demo-------------" << std::endl;
    {
        std::cout << "Creating a ScavTrap..." << std::endl;
        ScavTrap tempScav("TempScav");
        std::cout << "ScavTrap created, now destroying..." << std::endl;
    }
    
    return (0);
}
