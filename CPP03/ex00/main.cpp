/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:06:58 by salam             #+#    #+#             */
/*   Updated: 2025/03/12 12:21:18 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("ClapTrap");
    ClapTrap clap2(clap);
    ClapTrap clap3 = clap;
    
    clap.takeDamage(5);
    std :: cout << "Health : " << clap.getHitPoints() << std :: endl;
    clap.attack("enemy");
    clap.beRepaired(5);
    clap.takeDamage(5);
    return (0);
}
