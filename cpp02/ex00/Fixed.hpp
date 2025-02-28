/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:02:18 by salam             #+#    #+#             */
/*   Updated: 2025/02/28 18:08:14 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Fixed
{
    private:
        int value;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &copy); // copy constructor.
        ~Fixed(); // destructor.
        Fixed &operator = (const Fixed &f); // assignment operator.
        int getRawBits(void) const;
        void setRawBits(int const raw);
};
