/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:08:23 by salam             #+#    #+#             */
/*   Updated: 2025/02/28 18:34:38 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cstdlib>

int main()
{
    Fixed a;
    Fixed b(a);
    std::exit(0);
    Fixed c;
    
    c = b;
    std :: cout << "a : " << a.getRawBits() << std :: endl;
    std :: cout << "b : " << b.getRawBits() << std :: endl;
    std :: cout << "c : " << c.getRawBits() << std :: endl;
    return (0);
}
