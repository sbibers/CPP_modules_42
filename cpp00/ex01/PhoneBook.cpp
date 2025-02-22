/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:08:45 by salam             #+#    #+#             */
/*   Updated: 2025/02/22 13:17:32 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : index(0) , total_content(0){}

void PhoneBook::addContact()
{
    content[index].setContent();
    index = (index + 1) % 8;
    if (total_content < 8)
        total_content++;
}

void PhoneBook::searchContacts()
{
    if (total_content == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }
    std::cout << "| " << std::setw(10) << "Index" 
              << " | " << std::setw(10) << "First Name" 
              << " | " << std::setw(10) << "Last Name" 
              << " | " << std::setw(10) << "Nickname" 
              << " |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    for (int i = 0; i < total_content; i++)
    {
        content[i].displayShortInfo(i);
    }
    std::cout << "Enter index to view details: ";
    int search;
    std::cin >> search;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std :: cout << "Invalid input, Pleas enter a number." << std :: endl;
        return;
    }
    std::cin.ignore();
    if (search >= 0 && search < total_content)
    {
        content[search].displayFullInfo();
    }
    else
    {
        std::cout << "❌ Invalid index!" << std::endl;
    }
}
