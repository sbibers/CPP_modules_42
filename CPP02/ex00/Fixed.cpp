/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:02:07 by salam             #+#    #+#             */
/*   Updated: 2025/03/06 19:29:10 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() // default constructor.
{
    value = 0;
    std :: cout << "Default constructor called" << std :: endl;
}

Fixed::Fixed(const Fixed &copy) // copy constructor.
{
    std :: cout << "Copy constructor called" << std :: endl;
    value = copy.value;
}

Fixed::~Fixed() // destructor.
{
    std :: cout << "Destructor called" << std :: endl;
}

Fixed &Fixed::operator = (const Fixed &copy) // assignment operator.
{
    std :: cout << "Copy assignment operator called" << std :: endl;
    value = copy.value;
    return (*this);
}

void Fixed::setRawBits(int const raw) // setter.
{
    value = raw;
}

int Fixed::getRawBits(void) const // getter.
{
    std :: cout << "getRawBits member function called" << std :: endl;
    return (value);
}
