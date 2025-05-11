/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:19:05 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/11 17:10:50 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default name in Form class"), is_signed(false), grade_to_sign(27), grade_to_execute(27)
{
    std::cout << "Form default constructor called\n";
}

Form::Form(const std::string &name, const int grade_to_sign, const int grade_to_execute)
: name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) 
{
    this->is_signed = false;
    std::cout << "Form paramterize constructor called\n";
    if (this->grade_to_sign > 150 || this->grade_to_execute > 150)
        throw Form::GradeTooLowException();
    else if (this->grade_to_sign < 1 || this->grade_to_execute < 1)
        throw Form::GradeTooHighException();
}

Form::~Form()
{
    std::cout << "Form destructor called\n";
}

Form::Form(const Form &copy) : name(copy.name), is_signed(copy.is_signed), grade_to_sign(copy.grade_to_sign), grade_to_execute(copy.grade_to_execute)
{
    std::cout << "Form copy constructor called\n";
}

Form &Form::operator=(const Form &copy)
{
    std::cout << "Form copy assignment operator called\n";
    this->is_signed = copy.is_signed;
    return (*this);
}

const std::string &Form::getName() const
{
    return (this->name);
}

bool Form::getIsSigned() const
{
    return (this->is_signed);
}

int Form::getGradeToSign() const
{
    return (this->grade_to_sign);
}

int Form::getGradeToExecute() const
{
    return (this->grade_to_execute);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form : Grade Too High Exception");    
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form : Grade Too Low Exception");
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->grade_to_sign)
        throw Form::GradeTooLowException();
    this->is_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << "Form: " << obj.getName() << std::endl;
    out << "Signed: " << (obj.getIsSigned() ? "Yes" : "No") << std::endl;
    out << "Required Sign Grade: " << obj.getGradeToSign() << std::endl;
    out << "Required Execute Grade: " << obj.getGradeToExecute() << std::endl;
    return (out);
}
