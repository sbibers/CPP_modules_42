/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:27:00 by salam             #+#    #+#             */
/*   Updated: 2025/03/04 16:02:41 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int fractionalBits = 8;
    public:
        Fixed(); // default constructor.
        Fixed(const Fixed &fixed); // copy constructor.
        Fixed &operator = (const Fixed &fixed); // copy assignment operator.
        ~Fixed(); // destructor.
        int getRawBits(void) const; // getter.
        void setRawBits(int const raw); // setter.
        Fixed(const int value); // Int constructor.
        Fixed(const float value); // Float constructor.
        float to_float(void) const; // Getter for float.
        int to_int(void) const; // Getter for int.
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);
// To print the object use the std :: cout << obj << std :: endl;

#endif
