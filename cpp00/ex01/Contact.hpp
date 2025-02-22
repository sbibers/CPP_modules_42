/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:50:37 by salam             #+#    #+#             */
/*   Updated: 2025/02/22 13:17:38 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cctype> // for isalpha
#include <iomanip>  // For setw()

class Content
{
    private:
        std :: string firstName;
        std :: string lastName;
        std :: string nickName;
        std :: string phoneNumber;
        std :: string darkestSecret;
    public:
        void setContent();
        void displayShortInfo(int index);
        void displayFullInfo();
};

#endif