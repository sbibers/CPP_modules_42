/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:35:06 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/15 14:42:42 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45),  target(target)
{
    std::cout << "RobotomyRequestForm paramterize constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target)
{
    std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "RobotomyRequestForm copy assignment operator called\n";
    AForm::operator=(copy);
    this->target = copy.target;
    return (*this);
}

void RobotomyRequestForm::drilling_noises() const
{
    std::cout << "Drilling Noises\a" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executer) const
{
    drilling_noises();
    srand(time(NULL));
    if (rand() % 2 == 0)
        std::cout << executer.getName() << " -> Mission, Successful :)\n";
    else
        std::cout << executer.getName() << " -> Mission, Fail :(\n";
}
