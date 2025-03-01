/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:26:46 by salam             #+#    #+#             */
/*   Updated: 2025/03/01 14:31:15 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    
    a = Fixed(1234.4321f);
    std :: cout << "a is " << a << std :: endl;
    std :: cout << "b is " << b << std :: endl;
    std :: cout << "c is " << c << std :: endl;
    std :: cout << "d is " << d << std :: endl;

    std :: cout << "a is " << a.to_int() << " as integer" << std :: endl;
    std :: cout << "b is " << b.to_int() << " as integer" << std :: endl;
    std :: cout << "c is " << c.to_int() << " as integer" << std :: endl;
    std :: cout << "d is " << d.to_int() << " as integer" << std :: endl;
    return (0);
}
