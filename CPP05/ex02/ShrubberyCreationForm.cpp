/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:18:45 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/17 10:46:06 by sbibers          ###   ########.fr       */
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

int check_name(struct dirent *entry)
{
    if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        return (1);
    return (0);
}

void ShrubberyCreationForm::writeAsciiTree() const
{
    try
    {
        std::ofstream out_file((this->target + "_shrubbery").c_str());
        if (!out_file.is_open())
            throw AForm::FormCanNotOpenFileException();
        DIR *dir = opendir(".");
        if (dir == NULL)
        {
            out_file.close();
            throw AForm::FormCanNotOpenFileException();
        }
        struct dirent *entry;
        out_file << "|\n";
        if (out_file.fail())
        {
            closedir(dir);
            out_file.close();      
            throw AForm::FormCanNotWriteOnFile();
        }
        while ((entry = readdir(dir)) != NULL)
        {
            if (check_name(entry))
            {
                out_file << "|--> " << entry->d_name << std::endl;
                if (out_file.fail())
                {
                    closedir(dir);
                    out_file.close();      
                    throw AForm::FormCanNotWriteOnFile();
                }
            }
        }
        closedir(dir);
        out_file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void ShrubberyCreationForm::execute(Bureaucrat const &executer) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedExceptiom();
    if (executer.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    this->writeAsciiTree();
}
