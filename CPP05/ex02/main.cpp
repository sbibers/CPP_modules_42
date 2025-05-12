/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:31:50 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/12 17:08:48 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    try
    {
        Bureaucrat b1("TooHigh", 0);
        std::cout << b1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------------\n";
    try
    {
        Bureaucrat b2("TooLow", 200);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------------\n";
    Bureaucrat b3("NormalGuy", 75);
    std::cout << b3 << std::endl;
    b3.increment_grade();
    std::cout << b3 << std::endl;
    b3.decrement_grade();
    std::cout << b3 << std::endl;
    std::cout << "-------------------------\n";
    Bureaucrat test("TooHigh", 2);
    try
    {
        AForm f1("InvalidForm1", 3, 50);
        test.signForm(f1);
        f1.beSigned(test);
        std::cout << f1;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------------\n";
    try
    {
        AForm f2("InvalidForm2", 10, 200);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------------\n";
    Bureaucrat b4("Boss", 1);
    AForm f3("hahaha", 5, 10);
    std::cout << f3;
    b4.signForm(f3);
    std::cout << f3;
    std::cout << "-------------------------\n";
    Bureaucrat b5("Messi", 150);
    AForm f4("Ronlado", 100, 120);
    std::cout << f4;
    b5.signForm(f4);
    std::cout << f4;
    return (0);
}
