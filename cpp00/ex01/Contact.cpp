/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:55:52 by salam             #+#    #+#             */
/*   Updated: 2025/02/22 15:41:25 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setContent()
{
    while (1)
    {
        std :: cout << "Enter First Name : ";
        std :: getline(std :: cin, firstName);
        bool valid = true;
        for (char c : firstName)
        {
            if (!std::isalpha(c))
            {
                valid = false;
                break;
            }
        }
        if (firstName.empty() || !valid)
            std::cout << "❌ Invalid First Name! Only letters are allowed.\n";
        else
            break;
    }
    while (1)
    {
        std :: cout << "Enter Last Name : ";
        std :: getline(std :: cin, lastName);
        bool valid = true;
        for (char c : lastName)
        {
            if (!std::isalpha(c))
            {
                valid = false;
                break;
            }
        }
        if (lastName.empty() || !valid)
            std::cout << "❌ Invalid Last Name! Only letters are allowed.\n";
        else
            break;
    }
    while (1)
    {
        std :: cout << "Enter Nickname : ";
        std :: getline(std :: cin, nickName);

        bool valid = true;
        for (char c : nickName)
        {
            if (!std::isalpha(c))
            {
                valid = false;
                break;
            }
        }
        if (nickName.empty() || !valid)
            std::cout << "❌ Invalid Nickname! Only letters are allowed.\n";
        else
            break;
    }
    while (1)
    {
        std :: cout << "Enter Phone Number (10 digits): ";
        std :: getline(std :: cin, phoneNumber);
        bool valid = true;
        if (phoneNumber.length() != 10)
            valid = false;
        else
        {
            for (char c : phoneNumber)
            {
                if (!std::isdigit(c))
                {
                    valid = false;
                    break;
                }
            }
        }
        if (phoneNumber.empty() || !valid)
            std :: cout << "❌ Invalid Phone Number! It must be exactly 10 digits.\n";
        else
            break;
    }
    while (1)
    {
        std :: cout << "Enter Darkest Secret : ";
        std :: getline(std :: cin, darkestSecret);
        bool valid = true;
        for (char c : darkestSecret)
        {
            if (!std::isalpha(c))
            {
                valid = false;
                break;
            }
        }
        if (darkestSecret.empty() || !valid)
            std :: cout << "❌ Invalid Secret! Only letters are allowed.\n";
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
