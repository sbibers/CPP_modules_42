/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:06:46 by salam             #+#    #+#             */
/*   Updated: 2025/02/23 17:27:13 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact content[8]; // obj from class Contact
        int     index;
        int     total_content;
    public:
        PhoneBook() // constructor
        {
            index = 0;
            total_content = 0;
        }
        void addContact();
        void searchContacts();
};

#endif
