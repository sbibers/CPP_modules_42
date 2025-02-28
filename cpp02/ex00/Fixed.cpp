/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:02:07 by salam             #+#    #+#             */
/*   Updated: 2025/02/28 18:12:46 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
    std :: cout << "Default constructor called" << std :: endl;
}

Fixed::Fixed(const Fixed &copy) // copy constructor.
{
    std :: cout << "Copy constructor called" << std :: endl;
    *this = copy;
}

Fixed::~Fixed()
{
    std :: cout << "Destructor called" << std :: endl;
}

Fixed &Fixed::operator = (const Fixed &copy) // copy assignment operator.
{
    std :: cout << "Assignation operator called" << std :: endl;
    this->value = copy.getRawBits();
    return (*this);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

int Fixed::getRawBits(void) const
{
    std :: cout << "getRawBits member function called" << std :: endl;
    return (this->value);
}
