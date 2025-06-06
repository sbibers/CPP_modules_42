/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:43:33 by salam             #+#    #+#             */
/*   Updated: 2025/05/14 16:45:05 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &copy); // copy constructor.
        ~Fixed(); // destructor.
        Fixed &operator=(const Fixed &copy); // Assignment operator.
        int getRawBits(void) const; // setter.
        void setRawBits(int const raw); // getter.
        float toFloat(void) const;
        int toInt(void) const;
        bool operator>(const Fixed &fix) const;
        bool operator<(const Fixed &fix) const;
        bool operator>=(const Fixed &fix) const;
        bool operator<=(const Fixed &fix) const;
        bool operator==(const Fixed &fix) const;
        bool operator!=(const Fixed &fix) const;
        Fixed operator+(const Fixed &fix) const;
        Fixed operator-(const Fixed &fix) const;
        Fixed operator*(const Fixed &fix) const;
        Fixed operator/(const Fixed &fix) const;
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);
        static Fixed &min(Fixed &fix1, Fixed &fix2);
        static Fixed &max(Fixed &fix1, Fixed &fix2);
        static const Fixed &min(const Fixed &fix1, const Fixed &fix2);
        static const Fixed &max(const Fixed &fix1, const Fixed &fix2);
};
    
std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif
