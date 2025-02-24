/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:18:16 by sbibers           #+#    #+#             */
/*   Updated: 2025/02/24 16:50:57 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombie;
    int     N;

    N = 4;
    zombie = zombieHorde(N, "hahahah");
    for (int i = 0; i < N; i++)
    {
        zombie[i].announce();
    }
    delete[] zombie;
    return (0);
}
