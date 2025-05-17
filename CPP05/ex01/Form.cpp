/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:51:22 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/17 10:35:58 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form : Exception, Grade Too High!");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form : Exception, Grade Too Low!");
}

Form::Form() : name("default name"), grade_to_sign(10), grade_to_execute(20)
{
    std::cout << "Form default constructor called, name = default name, is_signed = false, grade_to_sign = 10, grade_to_execute = 20\n";
    this->is_signed = false;
}

Form::Form(std::string name, const int grade_to_sign, const int grade_to_execute)
: name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw Form::GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_execute > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form paramterize constructor called\n";
    this->is_signed = false;
}

Form::~Form()
{
    std::cout << "Form destructor called\n";
}

Form::Form(const Form &copy) : name(copy.name), is_signed(copy.is_signed)
, grade_to_sign(copy.grade_to_sign), grade_to_execute(copy.grade_to_execute)
{
    std::cout << "Form copy constructor called\n";
}

Form &Form::operator=(const Form &copy)
{
    this->is_signed = copy.is_signed;
    std::cout << "Form copy assignment operator called\n";
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
