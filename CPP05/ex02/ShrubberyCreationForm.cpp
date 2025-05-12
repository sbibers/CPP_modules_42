/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:18:45 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/12 18:26:45 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm paramterize constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{
    std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << "ShrubberyCreationForm copy assignment operator called\n";
    AForm::operator=(copy);
    this->target = copy.target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executer) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedExceptiom();
    if (executer.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
}
