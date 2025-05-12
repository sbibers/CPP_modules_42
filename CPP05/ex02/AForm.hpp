/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:44:49 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/12 18:24:48 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm // abstract class.
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
    public:
        AForm();
        AForm(std::string name, const int grade_to_sign, const int grade_to_execute);
        virtual ~AForm();
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        const std::string &getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executer) const = 0; // pure virtual function;
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class FormNotSignedExceptiom : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class FormNotOpenFileException : public std::exception // exception for open file in function execute.
        {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif
