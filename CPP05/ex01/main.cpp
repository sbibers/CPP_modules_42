/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:31:50 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/11 17:10:48 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("TooHigh", 0);
        std::cout << b1.getGrade();
        std::cout << b1.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
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
        Form f1("InvalidForm1", 3, 50);
        f1.beSigned(test);
        std::cout << (bool)f1.getIsSigned() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------------\n";
    try
    {
        Form f2("InvalidForm2", 10, 200);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------------\n";
    Bureaucrat b4("Boss", 1);
    Form f3("hahaha", 5, 10);
    std::cout << f3;
    std::cout << "-------------------------\n";
    b4.signForm(f3);
    std::cout << f3;
    std::cout << "-------------------------\n";
    Bureaucrat b5("Messi", 150);
    Form f4("Ronlado", 100, 120);
    std::cout << f4;
    std::cout << "-------------------------\n";
    b5.signForm(f4);
    std::cout << f4;
    return (0);
}
