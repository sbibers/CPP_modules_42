/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:34:34 by salam             #+#    #+#             */
/*   Updated: 2025/03/01 14:38:01 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std :: cout << "Default constructor called" << std :: endl;
    value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
    std :: cout << "Copy constructor called" << std :: endl;
    this->value = copy.value;
}

Fixed &Fixed::operator = (const Fixed &copy)
{
    std :: cout << "Assignation operator called" << std :: endl;
    this->value = copy.value;
    return (*this);
}

Fixed::~Fixed()
{
    std :: cout << "Destructor called" << std :: endl;
}

int Fixed::getRawBits(void) const
{
    std :: cout << "getRawBits member function called" << std :: endl;
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    std :: cout << "setRawBits member function called" << std :: endl;
    value = raw;
}

Fixed::Fixed(const int value)
{
    std :: cout << "Int constructor called" << std :: endl;
    this->value = value * 256;
}

Fixed::Fixed(const float value)
{
    std :: cout << "Float constructor called" << std :: endl;
    this->value = roundf(value * 256.0f);
}

float Fixed::to_float(void) const
{
    return ((float)value / 256.0f);
}

int Fixed::to_int(void) const
{
    return (value / 256);
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed) // stream output operator.
{
    out << fixed.to_float();
    return (out);
}
