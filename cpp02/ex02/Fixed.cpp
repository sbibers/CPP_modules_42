/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:50:09 by salam             #+#    #+#             */
/*   Updated: 2025/03/01 15:00:29 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = value * 256;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * 256.0f);
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = copy.value;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Assignation operator called" << std::endl;
    this->value = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::to_float(void) const
{
    return ((float)value / 256.0f);
}

int Fixed::to_int(void) const
{
    return (value / 256);
}

bool Fixed::operator>(const Fixed &fix) const
{
    if (this->value > fix.getRawBits())
        return (true);
    return false;
}

bool Fixed::operator<(const Fixed &fix) const
{
    if (this->value < fix.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed &fix) const
{
    if (this->value >= fix.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed &fix) const
{
    if (this->value <= fix.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed &fix) const
{
    if (this->value == fix.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed &fix) const
{
    if (this->value != fix.getRawBits())
        return (true);
    return (false);
}

Fixed Fixed::operator+(const Fixed &fix) const
{
    return Fixed(this->to_float() + fix.to_float());
}

Fixed Fixed::operator-(const Fixed &fix) const
{
    return Fixed(this->to_float() - fix.to_float());
}

Fixed Fixed::operator*(const Fixed &fix) const
{
    return Fixed(this->to_float() * fix.to_float());
}

Fixed Fixed::operator/(const Fixed &fix) const
{
    return Fixed(this->to_float() / fix.to_float());
}

Fixed &Fixed::operator++()
{
    this->value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed &Fixed::operator--()
{
    this->value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

Fixed &Fixed::min(Fixed &fix1, Fixed &fix2)
{
    if (fix1 < fix2)
        return (fix1);
    return (fix2);
}

Fixed &Fixed::max(Fixed &fix1, Fixed &fix2)
{
    if (fix1 > fix2)
        return (fix1);
    return (fix2);
}

const Fixed &Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
    if (fix1 < fix2)
        return (fix1);
    return (fix2);
}

const Fixed &Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
    if (fix1 > fix2)
        return (fix1);
    return (fix2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fix)
{
    out << fix.to_float();
    return (out);
}
