/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:18:00 by sbibers           #+#    #+#             */
/*   Updated: 2025/02/25 19:33:56 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std :: cout << "DEBUG !!!" << std :: endl;
}

void Harl::info(void)
{
    std :: cout <<  "INFO !!!" << std :: endl;
}

void Harl::warning(void)
{
    std :: cout << "WARNING !!!" << std :: endl;
}

void Harl::error(void)
{
    std :: cout << "ERROR !!!" << std :: endl;
}

void Harl::complain(std::string level)
{
    void (Harl:: *array[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; // array of functions.
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" }; // array of strings.
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*array[i])();
            break;
        }
    }
}
