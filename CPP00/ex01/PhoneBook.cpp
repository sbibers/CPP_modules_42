/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:08:45 by salam             #+#    #+#             */
/*   Updated: 2025/02/24 14:40:25 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact()
{
    content[index].setContent();
    index = (index + 1) % 8;
    if (total_content < 8)
        total_content++;
}

// std::cin.clear() -> if the input does not number, use it to reset the input to normal.
void PhoneBook::searchContacts()
{
    if (total_content == 0)
    {
        std :: cout << "PhoneBook is empty." << std::endl;
        return;
    }
    std :: cout << "| " << std::setw(10) << "Index" 
              << " | " << std::setw(10) << "First Name" 
              << " | " << std::setw(10) << "Last Name" 
              << " | " << std::setw(10) << "Nickname" 
              << " |" << std::endl;
    std :: cout << "-----------------------------------------------------" << std :: endl;
    for (int i = 0; i < total_content; i++)
    {
        content[i].displayShortInfo(i);
    }
    std :: cout << "Enter index to view details: ";
    std :: string input;
    std :: getline(std::cin, input);
    for (size_t i = 0; input[i]; i++)
    {
        if (!std::isdigit(input[i]))
        {
            std :: cerr << "❌ Invalid input, Please enter a number." << std :: endl;    
            return;
        }
    }
    int search = std::atoi(input.c_str());
    if (search >= 0 && search < total_content)
        content[search].displayFullInfo();
    else
    {
        std :: cerr << "❌ Invalid index!" << std :: endl;
    }
}
