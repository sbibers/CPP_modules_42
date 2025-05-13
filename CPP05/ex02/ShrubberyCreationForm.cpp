/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:18:45 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/13 19:20:25 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <dirent.h>
#include <string.h>

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

void ShrubberyCreationForm::writeAscciTree() const
{
    try
    {
        std::ofstream outfile((this->target + "_shrubbery").c_str());
        if (!outfile.is_open())
            throw std::runtime_error("Error: Could not open the output file.");
        DIR *dir = opendir(".");
        if (dir == NULL)
            throw std::runtime_error("Error: Could not open current directory.");
        struct dirent *entry;
        outfile << "|\n";
        while ((entry = readdir(dir)) != NULL)
        {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                outfile << "|" << "--> ";
                outfile << entry->d_name << std::endl;
                if (outfile.fail())
                {
                    closedir(dir);
                    outfile.close();        
                    throw std::runtime_error("Error: Writing to file failed.");
                }
            }
        }
        closedir(dir);
        outfile.close();
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
    this->writeAscciTree();
}
