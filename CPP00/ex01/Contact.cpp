/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:55:52 by salam             #+#    #+#             */
/*   Updated: 2025/02/23 17:35:28 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setContent()
{
    while (1)
    {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, firstName);

        bool valid = !firstName.empty();
        for (size_t i = 0; i < firstName.length(); i++)
        {
            if (!std::isalpha(firstName[i]))
            {
                valid = false;
                break;
            }
        }
        if (!valid)
            std::cerr << "❌ Invalid First Name! Only letters are allowed.\n";
        else
            break;
    }
    while (1)
    {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, lastName);

        bool valid = !lastName.empty();
        for (size_t i = 0; i < lastName.length(); i++)
        {
            if (!std::isalpha(lastName[i]))
            {
                valid = false;
                break;
            }
        }
        if (!valid)
            std::cerr << "❌ Invalid Last Name! Only letters are allowed.\n";
        else
            break;
    }
    while (1)
    {
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, nickName);

        bool valid = !nickName.empty();
        for (size_t i = 0; i < nickName.length(); i++)
        {
            if (!std::isalpha(nickName[i]))
            {
                valid = false;
                break;
            }
        }
        if (!valid)
            std::cerr << "❌ Invalid Nickname! Only letters are allowed.\n";
        else
            break;
    }
    while (1)
    {
        std::cout << "Enter Phone Number (10 digits): ";
        std::getline(std::cin, phoneNumber);

        bool valid = phoneNumber.length() == 10;
        for (size_t i = 0; i < phoneNumber.length(); i++)
        {
            if (!std::isdigit(phoneNumber[i]))
            {
                valid = false;
                break;
            }
        }
        if (!valid)
            std::cerr << "❌ Invalid Phone Number! It must be exactly 10 digits.\n";
        else
            break;
    }
    while (1)
    {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, darkestSecret);

        bool valid = !darkestSecret.empty();
        for (size_t i = 0; i < darkestSecret.length(); i++)
        {
            if (!std::isalpha(darkestSecret[i]))
            {
                valid = false;
                break;
            }
        }
        if (!valid)
            std::cerr << "❌ Invalid Secret! Only letters are allowed.\n";
        else
            break;
    }
}

std::string Contact::truncateString(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

// std::setw(10) -> use the width (number of names) that the text should have when printing.
// If the printed text is shorter than the specified number, spaces are added automatically.
// std::right -> the spaces will added before the text, and the text go to right. 
void Contact::displayShortInfo(int index)
{
    std::cout << "| " << std::setw(10) << std::right << index 
              << " | " << std::setw(10) << std::right << truncateString(firstName)
              << " | " << std::setw(10) << std::right << truncateString(lastName)
              << " | " << std::setw(10) << std::right << truncateString(nickName) 
              << " |" << std::endl;
}

void Contact::displayFullInfo()
{
    std :: cout << "First Name : " << firstName << std :: endl;
    std :: cout << "Last Name : " << lastName << std :: endl;
    std :: cout << "Nickname : " << nickName << std :: endl;
    std :: cout << "Phone Number : " << phoneNumber << std :: endl;
    std :: cout << "Drakest secret : " << darkestSecret << std :: endl;
}
