/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:14:02 by salam             #+#    #+#             */
/*   Updated: 2025/02/24 14:42:50 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void handleInputFail()
{
    if (std::cin.eof())
    {
        std::cout << "\nEOF found, exit!" << std::endl;
        std::exit(0);
    }
}

int main()
{
    PhoneBook phoneBook;
    std :: string command;

    while (1)
    {
        std :: cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std :: getline(std :: cin, command);
        handleInputFail();
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContacts();
        else if (command == "EXIT")
            break;
        else
            std :: cerr << "❌ Invalid command !" << std :: endl;
    }
    return (0);
}
