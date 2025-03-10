/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:06:58 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 21:21:15 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <cstdlib>

int main()
{
    std :: cout << "-------------ClapTrap Tests-------------" << std :: endl;
    ClapTrap clap("ClapTrap");
    ClapTrap clap2(clap);
    ClapTrap clap3 = clap;

    clap.takeDamage(5);
    clap.attack("enemy");
    clap.beRepaired(5);
    
    std :: cout << "-------------ScavTrap Tests-------------" << std :: endl;
    ScavTrap scav("ScavTrap");
    ScavTrap scav2(scav);
    ScavTrap scav3 = scav;

    std :: cout << "ScavTrap " << scav.getName() << " has " << scav.getHitPoints() << " hit points, " 
              << scav.getEnergyPoints() << " energy points, and " 
              << scav.getAttackDamage() << " attack damage." << std :: endl;
    scav.attack("enemy");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();
    scav.attack("enemy");
    std :: cout << "-------------Construction/Destruction Chaining Demo-------------" << std :: endl;
    return (0);
}
