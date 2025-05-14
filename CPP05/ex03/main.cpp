/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:31:50 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/14 19:13:33 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    // try
    // {
    //     Bureaucrat boss("Boss", 1);
    //     Bureaucrat intern("Intern", 150);
    //     RobotomyRequestForm form("my_garden");
    //     intern.signForm(form);
    //     boss.signForm(form);
    //     intern.executeForm(form);
    //     boss.executeForm(form);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    // std::cout << "---------------------------------------------------------------\n";
    // Bureaucrat b("salam", 47);
    // RobotomyRequestForm a("hahaha");
    // a.execute(b);
    Intern a;
    try
    {
        a.makeForm("Robotomy Request", "salam");
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
