/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:12:42 by sbibers           #+#    #+#             */
/*   Updated: 2025/02/26 11:22:09 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Zombie
{
    private:
        std::string name;
    public:
        void announce();
        Zombie(std::string name);
        ~Zombie();
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif
