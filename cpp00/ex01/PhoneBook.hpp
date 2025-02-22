/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:06:46 by salam             #+#    #+#             */
/*   Updated: 2025/02/22 14:52:24 by salam            ###   ########.fr       */
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
