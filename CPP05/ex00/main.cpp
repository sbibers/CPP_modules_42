/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:31:50 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/12 13:01:08 by sbibers          ###   ########.fr       */
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
    // std::exit(0);
    std::cout << "=========================================\n";
    try
    {
        Bureaucrat *b = new Bureaucrat("Boss", 28);
        if (b != NULL)
        {
            std::cout << *b << std::endl;
            delete b;
        }
        else
            std::cout << "Pointer NULL\n";
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
