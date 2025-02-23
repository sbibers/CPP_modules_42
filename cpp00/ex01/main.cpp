/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:14:02 by salam             #+#    #+#             */
/*   Updated: 2025/02/23 17:35:29 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std :: string command;

    while (1)
    {
        std :: cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std :: getline(std :: cin, command);
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
