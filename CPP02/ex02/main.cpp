/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:51:14 by salam             #+#    #+#             */
/*   Updated: 2025/03/06 19:30:05 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std :: cout <<  a << std :: endl;
    std :: cout << ++a << std :: endl;
    std :: cout << a << std :: endl;
    std :: cout << a++ << std :: endl;
    std :: cout << a << std :: endl;
    std :: cout << b << std :: endl;
    std :: cout << Fixed::max(a, b) << std :: endl;
    return (0);
}
