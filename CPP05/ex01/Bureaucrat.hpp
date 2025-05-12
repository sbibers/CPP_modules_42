/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:38:08 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/12 14:13:23 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        const std::string &getName() const;
        int getGrade() const;
        void increment_grade();
        void decrement_grade();
        void signForm(Form &form);
        class GradeTooHighException : public std::exception // class exception inherit from std::exception.
        {
            public:
                const char *what() const throw(); // function override take the message of the error.
        };
        class GradeTooLowException : public std::exception // class exception inherit from std::exception.
        {
            public:
                const char *what() const throw(); // function override take the message of the error.
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj); // overload for << operator.

#endif
