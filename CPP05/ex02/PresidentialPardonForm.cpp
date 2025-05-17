/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:54:36 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/17 10:43:05 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm parameterize constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy), target(copy.target)
{
    std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << "PresidentialPardonForm copy assignment operator called\n";
    Form::operator=(copy);
    this->target = copy.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executer) const
{
    (void)executer;
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox.\n";
}
