/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:31:50 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/17 10:33:47 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("salam", 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    // std::exit(0);
    std::cout << "=========================================\n";
    Bureaucrat *a = new Bureaucrat("salam", 150);
    try
    {
        a->decrement_grade();
        std::cout << *a << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete a;
    return (0);
}
