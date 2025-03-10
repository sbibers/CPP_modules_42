/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:06:58 by salam             #+#    #+#             */
/*   Updated: 2025/03/10 21:17:27 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <limits>
#include <iostream>

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
