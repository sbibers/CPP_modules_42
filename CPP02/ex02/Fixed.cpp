/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:50:09 by salam             #+#    #+#             */
/*   Updated: 2025/03/06 19:30:03 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() // default constructor
{
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) // int constructor.
{
    std :: cout << "Int constructor called" << std :: endl;
    this->value = value * 256;
}

Fixed::Fixed(const float value) // float constructor.
{
    std :: cout << "Float constructor called" << std :: endl;
    this->value = roundf(value * 256.0f);
}

Fixed::Fixed(const Fixed &copy) // copy constructor.
{
    std :: cout << "Copy constructor called" << std :: endl;
    this->value = copy.value;
}

Fixed::~Fixed() // destructor.
{
    std :: cout << "Destructor called" << std :: endl;
}

Fixed &Fixed::operator=(const Fixed &copy) // copy assignment operator.
{
    std :: cout << "Copy assignment operator called" << std :: endl;
    this->value = copy.getRawBits();
    return (*this);
}

void Fixed::setRawBits(int const raw) // setter.
{
    value = raw;
}

int Fixed::getRawBits(void) const // getter.
{
    return (value);
}

float Fixed::toFloat(void) const // convert to float.
{
    return ((float)value / 256.0f);
}

int Fixed::toInt(void) const  // convert to int.
{
    return (value / 256);
}

bool Fixed::operator>(const Fixed &fix) const // greater than operator.
{
    if (value > fix.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed &fix) const // less than operator.
{
    if (value < fix.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed &fix) const // greater than or equal operator.
{
    if (value >= fix.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed &fix) const // less than or equal operator.
{
    if (value <= fix.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed &fix) const // equal operator.
{
    if (value == fix.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed &fix) const // not equal operator.
{
    if (value != fix.getRawBits())
        return (true);
    return (false);
}

Fixed Fixed::operator+(const Fixed &fix) const // addition operator.
{
    return Fixed(this->toFloat() + fix.toFloat());
}

Fixed Fixed::operator-(const Fixed &fix) const // subtraction operator.
{
    return Fixed(this->toFloat() - fix.toFloat());
}

Fixed Fixed::operator*(const Fixed &fix) const // multiplication operator.
{
    return Fixed(this->toFloat() * fix.toFloat());
}

Fixed Fixed::operator/(const Fixed &fix) const // division operator.
{
    return Fixed(this->toFloat() / fix.toFloat());
}

Fixed &Fixed::operator++() // pre-increment operator.
{
    this->value++;
    return (*this);
}

Fixed Fixed::operator++(int) // post-increment operator.
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed &Fixed::operator--() // pre-decrement operator.
{
    this->value--;
    return (*this);
}

Fixed Fixed::operator--(int) // post-decrement operator.
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

Fixed &Fixed::min(Fixed &fix1, Fixed &fix2) // min function.
{
    if (fix1 < fix2)
        return (fix1);
    return (fix2);
}

Fixed &Fixed::max(Fixed &fix1, Fixed &fix2) // max function.
{
    if (fix1 > fix2)
        return (fix1);
    return (fix2);
}

const Fixed &Fixed::min(const Fixed &fix1, const Fixed &fix2) // min function.
{
    if (fix1 < fix2)
        return (fix1);
    return (fix2);
}

const Fixed &Fixed::max(const Fixed &fix1, const Fixed &fix2) // max function.
{
    if (fix1 > fix2)
        return (fix1);
    return (fix2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fix) // output stream operator.
{
    out << fix.toFloat();
    return (out);
}
