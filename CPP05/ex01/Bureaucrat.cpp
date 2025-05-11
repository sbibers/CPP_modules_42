/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:13:49 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/11 17:10:45 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Exception : Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Exception : Grade too low!");
}

Bureaucrat::Bureaucrat() : name("haha"), grade(27)
{
    std::cout << "Default constructor called, default grade = 27\n";
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : name(name)
{
    std::cout << "Bureaucrat Parametrize constructor called\n";
    if (grade < 1 || grade > 150)
    {
        this->grade = 27;
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else
            throw Bureaucrat::GradeTooLowException();
    }
    this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
    std::cout << "Copy constructor called\n";
}

const std::string &Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Copy assignment operator called\n";
    this->grade = copy.getGrade();
    return (*this);
}

void Bureaucrat::increment_grade()
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade--;
}

void Bureaucrat::decrement_grade()
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade++;
}

void Bureaucrat::signForm(Form &form)
{
    if (form.getIsSigned())
    {
        std::cout << form.getName() << " already signed\n";
        return;
    }
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << this->name << " cat not sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
    out << obj.getName() << ", Bureaucrat Grade : " << obj.getGrade();
    return (out);
}
