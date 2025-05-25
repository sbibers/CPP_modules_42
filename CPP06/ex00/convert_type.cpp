/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_type.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.amman>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:56:21 by sbibers           #+#    #+#             */
/*   Updated: 2025/05/25 14:50:05 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void convert_char(const std::string &str, size_t &length)
{
    char chr;

    if (length == 1)
        chr = str[0];
    else
        chr = str[1];
    if (isprint(chr))
    {
        std::cout << "char: '" << chr << "'\n";
        std::cout << "int: " << static_cast<int>(chr) << std::endl;
        std::cout << "float: " << static_cast<float>(chr) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(chr) << ".0" << std::endl;
    }
    else
    {
        std::cout << "char: Non Displayable\n";
        std::cout << "int: " << static_cast<int>(chr) << std::endl;
        std::cout << "float: " << static_cast<float>(chr) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(chr) << ".0" << std::endl;
    }
}

void convert_int(const std::string &str)
{
    long num = std::atol(str.c_str());
    std::cout << "char: ";
    if (num > 127 || num < 0)
        std::cout << "impossible\n";
    else
    {
        if (isprint(num))
            std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "Non displayable\n";
    }
    std::cout << "int: ";
    if (num > INT_MAX || num < INT_MIN)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(num) << std::endl;
    std::cout << "float: " << static_cast<float>(num) << ".0f\n";
    std::cout << "double: " << static_cast<double>(num) << ".0\n";
}

void convert_float(const std::string &str)
{
    float num = std::atof(str.c_str());
    bool flag = std::fabs(num - static_cast<int>(num)) < 0.0000000000001;
    std::cout << "char: ";
    if (num < 0 || num > 127)
        std::cout << "impossible\n";
    else
    {
        if (isprint(num))
            std::cout << "'" << static_cast<char>(num) << "'\n";
        else
            std::cout << "Non displayable\n";
    }
    std::cout << "int: ";
    if (static_cast<long>(num) < INT_MIN || static_cast<long>(num) > INT_MAX)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(num) << std::endl;
    std::cout << "float: ";
    if (num < -FLOAT_MAX || static_cast<float>(num) > FLOAT_MAX)
        std::cout << "impossible\n";
    else
    {
        if (flag)
            std::cout << num << ".0f\n";
        else
            std::cout << num << "f\n";
    }
    if (flag)
        std::cout << "double: " << static_cast<double>(num) << ".0\n";
    else
        std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void convert_double(const std::string &str)
{
    double num = std::atof(str.c_str());
    bool flag = std::fabs(num - static_cast<int>(num)) < 0.0000000000001;

    std::cout << "char: ";
    if (num < 0 ||  num > 127)
        std::cout << "impossible\n";
    else
    {
        if (isprint(num))
            std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "Non displayable\n";
    }
    std::cout << "int: ";
    if (num < INT_MIN || num > INT_MAX)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(num) << std::endl;
    std::cout << "float: ";
    if (num < -FLOAT_MAX || num > FLOAT_MAX)
        std::cout << "impossible\n";
    else
    {
        if (flag)
            std::cout << static_cast<float>(num) << ".0f\n";
        else
            std::cout << static_cast<float>(num) << "f\n";
    }
    std::cout << "double: ";
    if (num < -DOUBLE_MAX || num > DOUBLE_MAX)
        std::cout << "impossible\n";
    else
        std::cout << num << std::endl;
}
