/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:27:35 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/22 15:56:53 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    *this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void)obj;
    return (*this);
}

void ScalarConverter::converter(const std::string &str)
{
    size_t length = str.length();
    type type_of_string = find_type(str, length);
    switch (type_of_string)
    {
        case CHAR:
            convert_char(str, length);
        case INT:
            convert_int(str);
        case FLOAT:
            convert_float(str);
        case DOUBLE:
            convert_double(str);
        break;
    }
}
