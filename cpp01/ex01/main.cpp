/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:18:16 by sbibers           #+#    #+#             */
/*   Updated: 2025/02/26 11:24:53 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombie;

    zombie = zombieHorde(4, "hahahah");
    for (int i = 0; i < 4; i++)
    {
        zombie[i].announce();
    }
    delete[] zombie;
    return (0);
}
