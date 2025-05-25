/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:53:40 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/25 14:49:26 by sbibers          ###   ########.fr       */
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

static void print_special(const std::string &str)
{
    if (str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
}

void ScalarConverter::convert(const std::string &str)
{
    size_t length = str.length();
    type_of type = which_type(str, length);
    switch (type)
    {
        case INVALID:
            std::cout << "INVALID_INPUT\n";
            break;
        case SPECIAL:
            print_special(str);
            break;
        case CHAR:
            convert_char(str, length);
            break;
        case INT:
            convert_int(str);
            break;
        case FLOAT:
            convert_float(str);
            break;
        case DOUBLE:
            convert_double(str);
            break;
    }
}
