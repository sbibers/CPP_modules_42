/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:14:02 by salam             #+#    #+#             */
/*   Updated: 2025/02/22 13:15:28 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

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
            std :: cout << "Invalid command !" << std :: endl;
    }
    return (0);
}