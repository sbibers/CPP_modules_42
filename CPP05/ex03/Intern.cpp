/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:32:14 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/15 14:42:42 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    this->array_names[0] = "Shrubbery Creation";
    this->array_names[1] = "Robotomy Request";
    this->array_names[2] = "Presidential Pardon";
    std::cout << "Intern default constructor called\n";
}

Intern::~Intern()
{
    std::cout << "Intern destructor called\n";
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
    std::cout << "Intern copy constructor called\n";
}

Intern &Intern::operator=(const Intern &copy)
{
    std::cout << "Intern copy assignment operator called\n";
    this->array_names[0] = copy.array_names[0];
    this->array_names[1] = copy.array_names[1];
    this->array_names[2] = copy.array_names[2];
    return (*this);
}

int Intern::getIndexOfName(const std::string &type)
{
    for (int i = 0; i < 3; i++)
    {
        if (!type.compare(this->array_names[i]))
            return (i);
    }
    return (-1);
}

const char *Intern::FormCanNotCreation::what() const throw()
{
    return ("Inter, Exception Can Not Find Target To Creat Form!");
}

AForm *Intern::makeForm(const std::string &form_name, const std::string &target)
{
    AForm *form;
    int index = this->getIndexOfName(form_name);
    if (index == -1)
        throw Intern::FormCanNotCreation();
    try
    {
        switch (index)
        {
            case (0):
            {
                form = new ShrubberyCreationForm(target);
                break;
            }
            case (1):
            {
                form = new RobotomyRequestForm(target);
                break;
            }
            case (2):
            {
                form = new PresidentialPardonForm(target);
                break;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cout << form_name << " : " << e.what() << std::endl;
    }
    std::cout << form_name << " : Intern Create Done :)\n";
    delete form;
    return (form);
}
